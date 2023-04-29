#include "command.hpp"

using namespace nexus::core::components;

command::command(const command_type &command_type) : _command_type(command_type) {}

command::~command() {}

void command::help(void) const
{
    logs("\thelp - display helps");
    logs("\tq, quit - global shutdown");
    logs("\tload - load open a subsequent environment from which you can load libraries into memory, it then returns to this environment, memory is already handled so you can use this command to load another library, it will remove the previous one along the way");
    logs("\tlist - list open a subsequent environment from which you can recursively list files into your console, it always starts from nexus binary location");
}

void command::quit(void) const { _app->set_status(false); }

void command::list(void) const
{
    _plugin->list();
}

void command::list(const std::string &files) const
{
    _plugin->list(files);
}

void command::load(const std::string &file) const
{
    const auto &position = std::atoi(file.c_str());
    if (position != 0) {
        const auto &path = _plugin->get_list_at(position - 1);
        if (path != "") _plugin->load(path);
    } else err_logs("Wrong file input");
}
