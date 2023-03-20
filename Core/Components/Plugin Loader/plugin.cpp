#include "plugin.hpp"

using namespace nexus::core::components;

plugin *plugin::_instance = nullptr;
std::mutex plugin::_mutex;

plugin *plugin::get(void)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _instance == nullptr && (_instance = new plugin{});
    return _instance;
}

const std::pair<bool, const std::string> plugin::find(const std::string &plugin)
{
    const std::string path(plugin);
    if (std::filesystem::status(path).type() != std::filesystem::file_type::not_found)
        return {true, std::string(path)};
    return {false, ""};
}

void plugin::list(void)
{
    std::size_t at = 1;
    for (std::filesystem::recursive_directory_iterator dir("../Module/"), end; dir != end; dir++)
        if (!std::filesystem::is_directory(dir->path()) && std::filesystem::path(dir->path()).extension() == ".so") {
            _list.push_back(dir->path().c_str());
            std::cout << '\t' << at << " " << dir->path().c_str() << std::endl;
            at++;
        }
}

void plugin::list(const std::string &files)
{
    std::size_t at = 1;
    for (std::filesystem::recursive_directory_iterator dir(files), end; dir != end; dir++)
        if (!std::filesystem::is_directory(dir->path())) {
            _list.push_back(dir->path().c_str());
            std::cout << '\t' << at << " " << dir->path().c_str() << std::endl;
            at++;
        }
}

void plugin::load(const std::string &plugin)
{
    const auto &load = find(plugin);
    if (load.first && load.second.substr(10, 4) == "Game")
        _game == nullptr ? (_game = _game_lib.load_unique<interface::logic::game>(plugin, "entry_point"))
        : (remove("Game"), _game = _game_lib.load_unique<interface::logic::game>(plugin, "entry_point"));
    else if (load.first && load.second.substr(10, 7) == "Graphic")
        if (load.second.substr(18, 2) == "2D") {
            (_graphic_2D == nullptr || _graphic_3D == nullptr) ? (_graphic_2D = _graphic_lib.load_unique<interface::graphic::lib2D>(plugin, "entry_point"))
            : (remove("Graphic"), _graphic_2D = _graphic_lib.load_unique<interface::graphic::lib2D>(plugin, "entry_point"));
        } else if (load.second.substr(18, 2) == "3D") {
            (_graphic_3D == nullptr || _graphic_2D == nullptr) ? (_graphic_3D = _graphic_lib.load_unique<interface::graphic::lib3D>(plugin, "entry_point"))
            : (remove("Graphic"), _graphic_3D = _graphic_lib.load_unique<interface::graphic::lib3D>(plugin, "entry_point"));
        }
}

void plugin::remove(const std::string &plugin)
{
    if (plugin == "Game") {
        _game->~game();
        _game = nullptr;
        _game_lib.free();
    } else if (plugin == "Graphic") {
        _graphic_2D->~lib2D();
        _graphic_3D->~lib3D();
        _graphic_2D = nullptr;
        _graphic_3D = nullptr;
        _graphic_lib.free();
    }
}

void plugin::clear(void)
{
    if (_game != nullptr) {
        _game = nullptr;
        _game_lib.free();
    }
    if (_graphic_2D != nullptr) {
        _graphic_2D = nullptr;
        _graphic_lib.free();
    }
    if (_graphic_3D != nullptr) {
        _graphic_3D = nullptr;
        _graphic_lib.free();
    }
}
