#ifndef NEXUS
#define NEXUS

/* Source */
#include "ressource.hpp"
#include "environment.hpp"
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
                    void arguments(void) const;
                    void initialization(void) const;
                private:
                    const int _ac;
                    const char **_av;

                    // Components
                    components::environment _environment;
                    components::plugin *_plugin = components::plugin::get();
                    integrity::status *_app = integrity::status::get();
            };
        
        } // app

    } // core
    
} // nexus


#endif /* NEXUS */
