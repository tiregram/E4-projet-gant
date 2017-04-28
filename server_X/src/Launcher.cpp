#include "Launcher.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

G::Launcher::Launcher() {

	session = ssh_new();
	int rc;

	if(session == NULL)
		exit(-1);

	ssh_options_set(session, SSH_OPTIONS_HOST, "localhost");

	// Connect to server
	rc = ssh_connect(session);

	if(rc != SSH_OK) {
		std::cerr << "Error connecting to localhost: %s\n" << ssh_get_error(session);
		ssh_free(session);
		exit(-1);
	}
}

G::Launcher::~Launcher() { ssh_free(session); }

int G::Launcher::show_remote_files() {

	ssh_channel channel;
	int rc;
	channel = ssh_channel_new(session);
	if(channel == NULL)
		return SSH_ERROR;
	rc = ssh_channel_open_session(channel);
	if(rc != SSH_OK) {
		ssh_channel_free(channel);
		return rc;
	}

	rc = ssh_channel_request_exec(channel, "ls -l");
	if(rc != SSH_OK) {
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		return rc;
	}

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
