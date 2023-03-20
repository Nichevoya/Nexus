#ifndef COMMAND
#define COMMAND

/* Source */
#include "ressource.hpp"
#include "plugin.hpp"
#include "graphic.hpp"
#include "logic.hpp"

enum class command_type {
    none,
    help,
    quit,
    list,
    load,
};

namespace nexus {

    namespace core {

        namespace components {

            class command {
                public:
                   command(const command_type &command_type);
                   ~command();

                   void set_type(const command_type &command_type) { _command_type = command_type; }

                   const command_type &get_type(void) const { return _command_type; }

                   void help(void) const;
                   void quit(void) const;
                   void list(void) const;
                   void list(const std::string &files) const;
                   void load(const std::string &file) const;

               protected:
               private:
                   command_type _command_type = command_type::none;
                   components::plugin *_plugin = components::plugin::get();
                   app::integrity::status *_app = app::integrity::status::get();
            };
            
        } // components
        
    } // core

} // nexus

#endif /* COMMAND */
