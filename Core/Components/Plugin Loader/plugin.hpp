#ifndef PLUGIN_LOADER
#define PLUGIN_LOADER

/* Source */
#include "ressource.hpp"
#include "dynamic_library_loader.hpp"

namespace nexus {

    namespace core {

        namespace components {

            class plugin {
                public:
                    plugin();
                    ~plugin();

                    const std::pair<bool, const std::string> find(const std::pair<const std::string, const std::string> &plugin);

                    void load(void);
                    void remove(void);
                
                protected:
                private:
                    std::string _plugin_dir = "../../Plugin";
            };

        } // components
        
    } // core
    
} // nexus


#endif /* PLUGIN_LOADER */
