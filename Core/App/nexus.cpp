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

void app::nexus::arguments(void) const
{
    if (_av[1] != nullptr) return;
    else if (_av[1] != nullptr && _av[2] != nullptr) return;
    else return;
}

void app::nexus::initialization(void) const
{
    arguments();
    switch (_ac) {
        case 2: _plugin->load(_av[1]); break;
        case 3: _plugin->load(_av[1]); _plugin->load(_av[2]); break;
        default: break;
    }
}

void app::nexus::run(void)
{
    _environment.start();
}
