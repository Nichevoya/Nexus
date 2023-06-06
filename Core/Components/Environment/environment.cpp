#include "environment.hpp"

using namespace nexus::core::components;

environment::environment()
{
    logs("Terminal component start");
}

environment::~environment() { logs("Terminal component stop"); }

void environment::format(const terminal_log_type &log_type)
{
    set_log_type(log_type);
    switch (get_log_type()) {
        case terminal_log_type::nexus: std::cout << "[nexus]: "; break;
        case terminal_log_type::message: std::cout << "[message]: "; break;
        case terminal_log_type::error: std::cout << "[error]: "; break;
        case terminal_log_type::load: std::cout << "[load]: "; break;
        case terminal_log_type::unload: std::cout << "[unload]: "; break;
        case terminal_log_type::list: std::cout << "[list]: "; break;
        default: break;
    }
}

void environment::log(const terminal_log_type &log_type, const std::string &message)
{
    format(log_type);
    std::cout << message << std::endl;
}

void environment::run(void)
{
    if (!_status) return;
    format(terminal_log_type::nexus);
    input(); set_command_type_from_input();
}

void environment::stop(void) { _status = false; }

void environment::input(void)
{
    std::getline(std::cin, _input);
}

const std::string &environment::input(const std::string &message)
{
    if (!message.empty()) log(terminal_log_type::message, message);
    std::getline(std::cin, _input);
    return _input;
}

const std::string &environment::input(const std::string &message, const terminal_log_type &log_type)
{
    format(log_type);
    return input(message);
}

void environment::set_command_type_from_input(void)
{
    if (_input == "h" || _input == "help") _command.set_type(command_type::help);
    else if (_input == "q" || _input == "quit") _command.set_type(command_type::quit);
    else if (_input == "ls" || _input == "list") _command.set_type(command_type::list);
    else if (_input == "load") _command.set_type(command_type::load);
    else if (_input == "unload") _command.set_type(command_type::unload);
    else _command.set_type(command_type::none);
    action();
}

void environment::action(void)
{
    switch (_command.get_type()) {
        case command_type::help: _command.help(); break;
        case command_type::quit: _command.quit(); break;
        case command_type::list: _command.list(input("", terminal_log_type::list)); break;
        case command_type::load: 
            log(terminal_log_type::message, "Load from : Module/"); _command.list();
            _command.load(input("", terminal_log_type::load)); break;
        case command_type::unload:
            log(terminal_log_type::message, "Unload : Game | Graphic");
            _command.unload(input("", terminal_log_type::unload)); break;
        default: break;
    }
}
