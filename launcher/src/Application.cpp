#include "Application.hpp"


G::Application::Application()
{
	this->name = "";
	this->comment = "";
	this-> exec = "";
};

G::Application::~Application()
{

};

std::string G::Application::get_name()
{
	return this->name;
};

std::string G::Application::get_comment()
{
	return this->comment;
};

std::string G::Application::get_exec()
{
		return this->exec;
};

void G::Application::set_name(std::string name)
{
		this->name = name;
};

void G::Application::set_comment(std::string comment)
{
		this->comment = comment;
};

void G::Application::set_exec(std::string exec)
{
	this->exec = exec;
};
