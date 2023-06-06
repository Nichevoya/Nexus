#ifndef PLUGIN
#define PLUGIN

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"
#include "dynamic_library_loader.hpp"
#include "logic.hpp"
#include "graphic.hpp"

enum class active_plugin {
    none,
    lib_game,
    lib_graphic_2d,
    lib_graphic_3d
};

namespace nexus {

    namespace core {

        namespace components {

            class plugin {
                public:
                    void operator=(const plugin &) = delete;
                    plugin(const plugin &) = delete;

                    static plugin *get(void);
                    void destroy(void) const { delete get(); }

                    const std::string get_list_at(const std::size_t position) const { if (position < _list.size() && position >= 0) return _list.at(position); return ""; }
                    
                    const std::unique_ptr<interface::logic::game> &get_lib_game(void) const { return _game; }
                    const std::unique_ptr<interface::graphic::lib2D> &get_lib_2d(void) const { return _graphic_2d; }
                    const std::unique_ptr<interface::graphic::lib3D> &get_lib_3d(void) const { return _graphic_3d; }
                    const active_plugin &get_game_state(void) const { return _game_state; }
                    const active_plugin &get_graphic_state(void) const { return _graphic_state; }

                    void set_game_state(const active_plugin active_plugin) { _game_state = active_plugin; }
                    void set_graphic_state(const active_plugin active_plugin) { _graphic_state = active_plugin; }

                    const std::pair<bool, const std::string> find(const std::string &plugin);
                    void list(void);
                    void list(const std::string &files);
                    void load(const std::string &plugin);
                    void unload(void);
                    void unload(const std::string &plugin);

                protected:
                    plugin() { logs("Plugin loader component start"); }
                    ~plugin() { unload(); logs("Plugin loader component stop"); }
                private:
                    static plugin *_instance;
                    static std::mutex _mutex;
                    std::vector<std::string> _list;
                    dynamic_library_loader _game_lib;
                    dynamic_library_loader _graphic_lib;
                    std::unique_ptr<interface::logic::game> _game = nullptr;
                    std::unique_ptr<interface::graphic::lib2D> _graphic_2d = nullptr;
                    std::unique_ptr<interface::graphic::lib3D> _graphic_3d = nullptr;

                    active_plugin _game_state = active_plugin::none;
                    active_plugin _graphic_state = active_plugin::none;
            };

        } // components
        
    } // core
    
} // nexus


#endif /* PLUGIN */
