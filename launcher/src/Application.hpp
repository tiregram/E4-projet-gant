#pragma once

#include <string>

namespace G {

	class Application {

	public:
		std::string name;
		std::string comment;
		std::string exec;

		Application();
		~Application();
	};
}
