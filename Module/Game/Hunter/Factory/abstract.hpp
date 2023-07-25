#ifndef ABSTRACT
#define ABSTRACT

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"

/* --------------------------------- Engine --------------------------------- */
#include "coordinator.hpp"

/* --------------------------------- Engine --------------------------------- */
#include "system.hpp"

/* ------------------------------- Components ------------------------------- */
#include "transform.hpp"

/* --------------------------------- Entity --------------------------------- */
#include "type.hpp"

namespace factory {

    namespace abstract {

        class entity {
            public:
                virtual ~entity() = default;

                virtual void set_entity(const engine::entity &entity) = 0;

                virtual const engine::entity &get_entity(void) const = 0;
                virtual const std::string &get_texture_file_path(void) const = 0;
            
            protected:
            private:
        };
        
        class system : public engine::system_loader {
            public:
                virtual ~system() = default;

                virtual void update(engine::coordinator &engine, std::map<const factory::entity::type, std::vector<engine::entity> &> &entities) = 0;
        
            protected:
            private:
        };
        
        
    } // abstract
    
} // factory

#endif /* ABSTRACT */
