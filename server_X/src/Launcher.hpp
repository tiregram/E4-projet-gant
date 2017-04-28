#pragma once

#include <libssh/libssh.h>

namespace G {
	class Launcher {
	public:
		Launcher();
		virtual ~Launcher();

		int show_remote_files();

	private:
		ssh_session session;
	};
}
