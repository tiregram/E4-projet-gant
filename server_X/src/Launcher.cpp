#include "Launcher.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

G::Launcher::Launcher() {

	this->session = ssh_new();
	int verbosity = SSH_LOG_PROTOCOL;
	int port = 22;
	int rc;

	if(this->session == NULL)
		exit(-1);

	ssh_options_set(this->session, SSH_OPTIONS_HOST, "ruhtra@192.168.43.179");
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

G::Launcher::~Launcher() { ssh_free(this->session); }

int G::Launcher::show_remote_files() {

	ssh_channel channel;
	int rc;
	channel = ssh_channel_new(this->session);
	if(channel == NULL)
		return SSH_ERROR;
	std::cout << "1st" << '\n';

	rc = ssh_channel_open_session(channel);
	if(rc != SSH_OK) {
		ssh_channel_free(channel);
		return rc;
	}
	std::cout << "2nd" << '\n';

	// rc = ssh_channel_open_forward(ssh_channel channel, const char *remotehost, int remoteport,
	// const char *sourcehost, int localport)

	// rc = ssh_channel_request_exec(channel, "ls -l");
	rc = ssh_channel_request_exec(channel, "DISPLAY=:0 blender");
	if(rc != SSH_OK) {
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		return rc;
	}
	std::cout << "3rd" << '\n';

	char buffer[256];
	int nbytes;
	nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	while(nbytes > 0) {
		if(fwrite(buffer, 1, nbytes, stdout) != nbytes) {
			ssh_channel_close(channel);
			ssh_channel_free(channel);
			return SSH_ERROR;
		}
		nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	}
	if(nbytes < 0) {
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		return SSH_ERROR;
	}
	ssh_channel_send_eof(channel);
	ssh_channel_close(channel);
	ssh_channel_free(channel);
	return SSH_OK;
}

int G::Launcher::shell_session() {
	ssh_channel channel;
	int rc;
	channel = ssh_channel_new(this->session);
	if(channel == NULL)
		return SSH_ERROR;
	rc = ssh_channel_open_session(channel);
	if(rc != SSH_OK) {
		ssh_channel_free(channel);
		return rc;
	}
	ssh_channel_close(channel);
	ssh_channel_send_eof(channel);
	ssh_channel_free(channel);
	return SSH_OK;
}
