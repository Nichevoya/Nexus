#include "sfml.hpp"

using namespace nexus::module::graphic::library;

extern "C" const std::unique_ptr<sfml> entry_point(void) { return std::make_unique<sfml>(); }

sfml::sfml()
{
    logs("SFML Start");
    initialisation();
}

sfml::~sfml()
{
    _window.close();
    logs("SFML Stop");
}

void sfml::initialisation(void)
{
    _window.create(sf::VideoMode(1920, 1080), "Nexus");
    _window.setFramerateLimit(60);
}

void sfml::update(void)
{
    event_update();
    
    _window.clear();
    // _window.draw();
    _window.display();
}

void sfml::event_update(void)
{
    while (_window.pollEvent(_event))
        if (_event.type == sf::Event::Closed) _window.close();
}

bool sfml::status(void) const { return _window.isOpen(); }

void sfml::set_texture_file_list(const std::map<std::string, std::vector<std::string>> &texture_file_list)
{
    _texture_file_list = texture_file_list;
}
