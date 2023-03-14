#include "command.hpp"

using namespace nexus::core::components;

command::command(const command_type &command_type) : _command_type(command_type) {}

command::~command() {}

void command::help(void)
{
    logs("\thelp - display helps");
    logs("\tq, quit - global shutdown");
    logs("\tload - load open a subsequent environment from which you can load libraries into memory then returns to this environment");
}

void command::quit(void) { _app->set_status(false); }

void command::load(void)
{
    
}
