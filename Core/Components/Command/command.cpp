#include "command.hpp"

using namespace nexus::core::components;

command::command(const command_type &command_type) : _command_type(command_type) {}

command::~command() {}

void command::help(void) const
{
    logs("\thelp - display helps");
    logs("\tq, quit - global shutdown");
    logs("\tload - load libraries into memory, memory is fully managed so you can use this command to load another library, it will remove the previous one along the way");
    logs("\tunload - unload the specified plugin from memory");
    logs("\tlist - recursively list files into your console, it always starts from app binary location");
}

void command::quit(void) const { _app->set_status(false); }

void command::list(void) const
{
    _plugin->list();
}

void command::list(const std::string &directory) const
{
    _plugin->list(directory);
}

void command::load(const std::string &file) const
{
    const auto &position = std::atoi(file.c_str());
    if (position != 0) {
        const auto &path = _plugin->get_list_at(position - 1);
        if (path != "") _plugin->load(path);
    } else err_logs("Wrong file input");
}

void command::unload(const std::string &file) const
{
    _plugin->unload(file);
}
