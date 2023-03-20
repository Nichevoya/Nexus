#ifndef PLUGIN
#define PLUGIN

/* Source */
#include "ressource.hpp"
#include "dynamic_library_loader.hpp"
#include "logic.hpp"
#include "graphic.hpp"

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

                    const std::pair<bool, const std::string> find(const std::string &plugin);
                    void list(void);
                    void list(const std::string &files);
                    void load(const std::string &plugin);
                    void remove(const std::string &plugin);
                    void clear(void);

                protected:
                    plugin() { logs("Plugin loader component start"); }
                    ~plugin()
                    {
                        clear();
                        logs("Plugin loader component stop");
                    }
                private:
                    static plugin *_instance;
                    static std::mutex _mutex;
                    std::vector<std::string> _list;
                    dynamic_library_loader _game_lib;
                    dynamic_library_loader _graphic_lib;
                    std::unique_ptr<interface::logic::game> _game = nullptr;
                    std::unique_ptr<interface::graphic::lib2D> _graphic_2D = nullptr;
                    std::unique_ptr<interface::graphic::lib3D> _graphic_3D = nullptr;
            };

        } // components
        
    } // core
    
} // nexus


#endif /* PLUGIN */
