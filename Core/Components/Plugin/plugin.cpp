#include "plugin.hpp"

using namespace nexus::core::components;

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
            get()._list.push_back(dir->path().c_str());
            std::cout << '\t' << at << " " << dir->path().c_str() << std::endl;
            at++;
        }
}

void plugin::list(const std::string &files)
{
    std::size_t at = 1;
    for (std::filesystem::recursive_directory_iterator dir(files), end; dir != end; dir++)
        if (!std::filesystem::is_directory(dir->path())) {
            get()._list.push_back(dir->path().c_str());
            std::cout << '\t' << at << " " << dir->path().c_str() << std::endl;
            at++;
        }
}

void plugin::load(const std::string &plugin)
{
    try {
        const auto &load = find(plugin);
        if (load.first && load.second.substr(10, 4) == "Game")
            if (_game == nullptr) { set_game_state(active_plugin::lib_game); get()._game = get()._game_lib.load_unique<interface::logic::game>(plugin, "entry_point"); }
            else { this->unload("Game"); this->load(plugin); }
        else if (load.first && load.second.substr(10, 7) == "Graphic")
            if (load.second.substr(18, 2) == "2D") {
                if (_graphic_2d == nullptr) { set_graphic_state(active_plugin::lib_graphic_2d); get()._graphic_2d = get()._graphic_lib.load_unique<interface::graphic::lib2D>(plugin, "entry_point"); }
                else { this->unload("Graphic"); this->load(plugin); }
            } else if (load.second.substr(18, 2) == "3D") {
                if (_graphic_3d == nullptr) { set_graphic_state(active_plugin::lib_graphic_3d); get()._graphic_3d = get()._graphic_lib.load_unique<interface::graphic::lib3D>(plugin, "entry_point"); }
                else { this->unload("Graphic"); this->load(plugin); }
            }
    } catch(const std::exception& error) {
        err_logs("Load: " << error.what());
    }
    
}

void plugin::unload(void)
{
    try {
        if (get()._game != nullptr) {
            get()._game_state = active_plugin::none;
            get()._game = nullptr;
            get()._game_lib.free();
        }
        if (get()._graphic_2d != nullptr && get()._graphic_3d == nullptr) {
            get()._graphic_state = active_plugin::none;
            get()._graphic_2d = nullptr;
            get()._graphic_lib.free();
        } else if (get()._graphic_3d != nullptr && get()._graphic_2d == nullptr) {
            get()._graphic_state = active_plugin::none;
            get()._graphic_3d = nullptr;
            get()._graphic_lib.free();
        }
    } catch(const std::exception& error) {
        err_logs("Unload: " << error.what());
    }
    
}

void plugin::unload(const std::string &plugin)
{
    try {
        if (plugin == "Game" && get()._game != nullptr) {
            get()._game_state = active_plugin::none;
            get()._game = nullptr;
            get()._game_lib.free();
        } else if (plugin == "Graphic" && (get()._graphic_2d != nullptr || get()._graphic_3d != nullptr)) {
            get()._graphic_state = active_plugin::none;
            get()._graphic_2d = nullptr;
            get()._graphic_3d = nullptr;
            get()._graphic_lib.free();
        } else logs("No library was unloaded");
    } catch(const std::exception& error) {
        err_logs("Unload: " << error.what());
    }
    
}

bool plugin::game_status(void) const
{
    switch (get_game_state()) {
        case active_plugin::lib_game: if (get().get_lib_game() != nullptr) return get().get_lib_game()->status(); return false; break;
        default: return false; break;
    }
}

bool plugin::graphic_status(void) const
{
    switch (get_graphic_state()) {
        case active_plugin::lib_graphic_2d: if (get().get_lib_2d() != nullptr) return get().get_lib_2d()->status(); return false; break;
        case active_plugin::lib_graphic_3d: if (get().get_lib_3d() != nullptr) return get().get_lib_3d()->status(); return false; break;
        default: return false; break;
    }
}

void plugin::update_game(void)
{
    switch (get_game_state()) {
        case active_plugin::lib_game: if (get().get_lib_game() != nullptr) get().get_lib_game()->update(); break;
        default: break;
    }
}

void plugin::update_graphic(void)
{
    switch (get_graphic_state()) {
        case active_plugin::lib_graphic_2d: if (get().get_lib_2d() != nullptr) get().get_lib_2d()->update(); break;
        case active_plugin::lib_graphic_3d: if (get().get_lib_3d() != nullptr) get().get_lib_3d()->update(); break;
        default: break;
    }
}
