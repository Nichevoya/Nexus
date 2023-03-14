#include "nexus.hpp"

using namespace nexus::core;

app::nexus::nexus(const int ac, const char **av) : _input(ac, av) { logs("Nexus start"); }

app::nexus::~nexus() { logs("Nexus stop"); }

void app::nexus::run(void)
{
    _input.read();
}
