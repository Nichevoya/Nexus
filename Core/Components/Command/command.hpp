#ifndef COMMAND
#define COMMAND

/* Source */
#include "ressource.hpp"
#include "dynamic_library_loader.hpp"

enum class command_type {
    none,
    help,
    quit,
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

                   void help(void);
                   void quit(void);
                   void load(void);

               protected:
               private:
                   command_type _command_type = command_type::none;
                   app::integrity::status *_app = app::integrity::status::get();
            };
            
        } // components
        
    } // core

} // nexus

#endif /* COMMAND */
