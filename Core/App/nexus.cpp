#include "nexus.hpp"

using namespace nexus::core;

app::nexus::nexus(const int ac, const char **av) : _ac(ac), _av(av)
{
    logs("Nexus start");
    initialization();
}

app::nexus::~nexus()
{
    logs("Nexus stop");
}

void app::nexus::initialization(void)
{
    switch (_ac) {
        case 2: components::plugin::get().load(_av[1] != nullptr ? _av[1] : nullptr); break;
        case 3: components::plugin::get().load(_av[1] != nullptr ? _av[1] : nullptr); components::plugin::get().load(_av[2] != nullptr ? _av[2] : nullptr); break;
        default: throw exception(""); break;
    }
}

void app::nexus::run(void)
{
    while (integrity::status::get().get_status() && components::plugin::get().graphic_status()) {
        if (components::plugin::get().game_status()) components::plugin::get().update_game();
        components::plugin::get().update_graphic();
    }
}
