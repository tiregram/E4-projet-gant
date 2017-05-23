#include "Launcher.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <boost/algorithm/string.hpp>

G::Launcher::Launcher(const void* host, int port, std::string display) {

	std::cout << "Create Launcher" << '\n';

	this->session = ssh_new();
	int verbosity = SSH_LOG_PROTOCOL;
	// int port = 22;
	this->port = port;
	this->host = host;
	this->display = display;
	int rc;

	if(this->session == NULL)
		exit(-1);

	// ssh_options_set(this->session, SSH_OPTIONS_HOST, "192.168.43.179");
	ssh_options_set(this->session, SSH_OPTIONS_HOST, host);
	ssh_options_set(this->session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
	ssh_options_set(this->session, SSH_OPTIONS_PORT, &port);

	// Connect to server
	rc = ssh_connect(this->session);

	if(rc != SSH_OK) {
		std::cerr << "Error connecting to localhost: %s\n" << ssh_get_error(this->session);
		ssh_free(this->session);
		exit(-1);
	}

	char* password = getpass("Enter your password : ");
	rc = ssh_userauth_password(this->session, NULL, password);

	if(rc == SSH_AUTH_ERROR) {
		std::cerr << "Error Auth : %s\n" << ssh_get_error(this->session);
		ssh_free(this->session);
		exit(-1);
	}
}

G::Launcher::~Launcher() {

	std::cout << "Delete Launcher" << '\n';

	for(unsigned int i = 0; i < this->channels.size(); i++) {
		ssh_channel_close(this->channels[i]);
		ssh_channel_free(this->channels[i]);
	}

	ssh_disconnect(this->session);
	ssh_free(this->session);
};

int G::Launcher::compute_application_list() {

	const std::string NAME = "Name=";
	const std::string EXEC = "Exec=";
	const std::string COMMENT = "Comment=";

	ssh_channel channel;
	int rc;
	channel = ssh_channel_new(this->session);
	if(channel == NULL) {
		return SSH_ERROR;
	}

	rc = ssh_channel_open_session(channel);
	if(rc != SSH_OK) {
		return rc;
	} else {
		this->channels.push_back(channel);
	}

	std::string str = "find /usr/share/applications -name \"*.desktop\" -print | xargs cat |grep "
	                  "\"^Comment=|^Name=|^Exec=\" -E";
	// find /usr/share/applications -name "*.desktop" -print | xargs cat |grep
	// "^Comment=|^Name=|^Exec=" -E

	const char* cmd = str.c_str();
	rc = ssh_channel_request_exec(channel, cmd);
	if(rc != SSH_OK) {
		return rc;
	}

	std::vector<std::string> founds;
	std::string tmp_last = "";
	char buffer[256];
	int nbytes;
	nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	while(nbytes > 0) {
		if(fwrite(buffer, 1, nbytes, stdout) != nbytes) {
			return SSH_ERROR;
		}

		const std::string s = std::string(buffer, nbytes);
		std::vector<std::string> tokens;
		boost::split(tokens, s, boost::is_any_of("\n"));

		tokens[0] = tmp_last + tokens[0];
		for(int i = 0; i < tokens.size() - 1; i++) {

			founds.push_back(tokens[i]);
		}
		tmp_last = tokens[tokens.size() - 1];

		nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	}
	if(nbytes < 0) {
		return SSH_ERROR;
	}

	std::shared_ptr<G::Application> tmp;

	for(int i = 0; i < founds.size(); i++) {

		if(founds[i].find(NAME) != std::string::npos) {
			founds[i].erase(0, NAME.size());
			// std::cout << "New Application : " << '\n';
			// std::cout << "NAME : " << founds[i] << '\n';
			tmp = std::make_shared<G::Application>();
			tmp->name = founds[i];
			this->applications.push_back(tmp);
		}

		if(founds[i].find(COMMENT) != std::string::npos) {
			founds[i].erase(0, COMMENT.size());
			// std::cout << "COMMENT : " << founds[i] << '\n';
			tmp->comment = founds[i];
		}

		if(founds[i].find(EXEC) != std::string::npos) {
			founds[i].erase(0, EXEC.size());
			// std::cout << "EXEC : " << founds[i] << '\n';
			tmp->exec = founds[i];
		}
	}

	return SSH_OK;
};

std::vector<std::shared_ptr<G::Application>> G::Launcher::get_applications_list() {
	if(this->applications.size() == 0)
		this->compute_application_list();

	return this->applications;
};

int G::Launcher::launch(std::shared_ptr<Application> app) {

	const std::string DISPLAY_PREFIX = "DISPLAY=:";

	ssh_channel channel;
	int rc;
	channel = ssh_channel_new(this->session);
	if(channel == NULL) {
		return SSH_ERROR;
	}

	rc = ssh_channel_open_session(channel);
	if(rc != SSH_OK) {
		return rc;
	} else {
		this->channels.push_back(channel);
	}

	std::string cmd = std::string(DISPLAY_PREFIX + this->display) + " " + app->exec + " & echo $!";
	std::cout << "COMMANDE : " << cmd << '\n';
	rc = ssh_channel_request_exec(channel, cmd.c_str());
	std::cout << "RETURN STATUS : " << rc << '\n';
	if(rc != SSH_OK) {
		return rc;
	}

	std::cout << "Launche Application : " << app->name << '\n';

	return SSH_OK;
};
