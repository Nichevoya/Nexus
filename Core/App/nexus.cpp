#include "nexus.hpp"

using namespace nexus::core;

app::nexus::nexus(const int ac, const char **av) : _ac(ac), _av(av)
{
    logs("Nexus start");
    initialization();
}

app::nexus::~nexus()
{
    components::plugin::get()->destroy();
    integrity::status::get()->destroy();
    logs("Nexus stop");
}

void app::nexus::initialization(void) const
{
    switch (_ac) {
        case 2: _plugin->load(_av[1] != nullptr ? _av[1] : nullptr); break;
        case 3: _plugin->load(_av[1] != nullptr ? _av[1] : nullptr); _plugin->load(_av[2] != nullptr ? _av[2] : nullptr); break;
        default: break;
    }
}

void app::nexus::plugin(void)
{
    switch (_plugin->get_game_state()) {
        case active_plugin::lib_game: if (_plugin->get_lib_game()->status()) _plugin->get_lib_game()->update(); break;
        default: break;
    }

    switch (_plugin->get_graphic_state()) {
        case active_plugin::lib_graphic_2d: if (_plugin->get_lib_2d()->status()) _plugin->get_lib_2d()->update(); break;
        case active_plugin::lib_graphic_3d: if (_plugin->get_lib_3d()->status()) _plugin->get_lib_3d()->update(); break;
        default: break;
    }
}

void app::nexus::env(void) { _environment.run(); }

void app::nexus::run(void)
{
    while (_app->is_active()) {
        plugin(); env();
    }
}
