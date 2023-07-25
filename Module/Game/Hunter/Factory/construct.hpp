#ifndef CONSTRUCT
#define CONSTRUCT

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"

/* --------------------------------- Entity --------------------------------- */
#include "target.hpp"

namespace factory {

    namespace entity {

        class construct {
            public:
                std::unique_ptr<factory::entity::target> target(const std::string &file_path) { return std::make_unique<factory::entity::target>(file_path); }
                const std::unique_ptr<factory::entity::target> target(const std::string &file_path) const { return std::make_unique<factory::entity::target>(file_path); }
        
            protected:
            private:
        };
        
    } // entity
    
} // factory

#endif /* CONSTRUCT */
