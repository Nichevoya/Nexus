#include "environment.hpp"

using namespace nexus::core::components;

environment::environment(const int ac, const char **av) : _ac(ac), _av(av)
{
    logs("Terminal component start");
    initialization();
}

environment::~environment() { logs("Terminal component stop"); }

void environment::initialization(void)
{
    while (this->_is_active && (get_input() != "no" || get_input() != "yes")) {
        log(terminal_log_type::message, "Do you wish to use the Nexus environment ? (yes/no)");
        set_log_type(terminal_log_type::nexus);
        format();
        input();
        if (get_input() == "no") {
            this->_is_active = false;
        } else if (get_input() == "yes") {
            break;
        }
    }
}

void environment::format(void)
{
    switch (get_log_type()) {
        case terminal_log_type::nexus: std::cout << "[nexus]: "; break;
        case terminal_log_type::message: std::cout << "[message]: "; break;
        case terminal_log_type::error: std::cout << "[error]: "; break;
        default: break;
    }
}

void environment::log(const terminal_log_type &log_type, const std::string &message)
{
    set_log_type(log_type);
    format();
    std::cout << message << std::endl;
}

void environment::read(void)
{
    while (_app->is_active() && this->_is_active) {
        format(); input();
        set_command_type_from_input();
        set_log_type(terminal_log_type::nexus);
    }
}

void environment::input(void)
{
    std::getline(std::cin, _input);
}

const std::string &environment::input(const std::string &message)
{
    std::cout << "[message]: " << message << std::endl;
    std::getline(std::cin, _input);
    return _input;
}

void environment::set_command_type_from_input(void)
{
    if (_input == "h" || _input == "help") _command.set_type(command_type::help);
    else if (_input == "q" || _input == "quit") _command.set_type(command_type::quit);
    else if (_input == "load") _command.set_type(command_type::load);
    else _command.set_type(command_type::none);
    action();
}

void environment::action(void)
{
    switch (_command.get_type()) {
        case command_type::none: break;
        case command_type::help: _command.help(); break;
        case command_type::quit: _command.quit(); break;
        case command_type::load: _command.load(); break;
        default: break;
    }
}
