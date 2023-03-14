#include "plugin.hpp"

using namespace nexus::core::components;

plugin::plugin() { logs("Plugin loader component start"); }

plugin::~plugin() { logs("Plugin loader component stop"); }

const std::pair<bool, const std::string> plugin::find(const std::pair<const std::string, const std::string> &plugin)
{
    const std::string path(plugin.first.empty() ? (_plugin_dir + '/' + plugin.second) : (_plugin_dir + '/' + plugin.first + '/' + plugin.second));
    if (std::filesystem::status(path).type() != std::filesystem::file_type::not_found)
        return {true, std::string(path)};
    return {false, ""};
}

void plugin::load(void) {}

void plugin::remove(void) {}
