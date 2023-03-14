#ifndef NEXUS
#define NEXUS

/* Source */
#include "ressource.hpp"
#include "terminal.hpp"
#include "plugin.hpp"

namespace nexus {

    namespace core {

        namespace app {

            class nexus {
                public:
                    void operator=(const nexus &) = delete;
                    nexus(const nexus &) = delete;
                    explicit nexus(const int ac, const char **av);
                    ~nexus();

                    void run(void);
                
                protected:
                private:
                    // Components
                    components::plugin _plugin;
                    components::terminal _input;
            };
        
        } // app

    } // core
    
} // nexus


#endif /* NEXUS */
