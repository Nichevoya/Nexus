#ifndef TARGET
#define TARGET

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"

/* -------------------------------- Interface ------------------------------- */
#include "abstract.hpp"

/* --------------------------------- Engine --------------------------------- */
#include "entity.hpp"

/* ------------------------------- Components ------------------------------- */
#include "transform.hpp"

/* --------------------------------- Entity --------------------------------- */
#include "type.hpp"

namespace factory {

    namespace entity {

        class target : public factory::abstract::entity {
            public:
                target(const target &) = delete;
                target(const std::string &file_path) : _file_path(file_path) {}
                target(const std::string &file_path, const factory::components::transform &transform) : _file_path(file_path), _transform(transform) {}
                
                ~target() = default;

                void set_file_path(const std::string &file_path) { _file_path = file_path; }
                void set_entity(const engine::entity &entity) override { _entity = entity; }
                void set_transform(const factory::components::transform &transform) { _transform = transform; }

                const engine::entity &get_entity(void) const override { return _entity; }
                factory::components::transform &get_transform(void) { return _transform; }
                const factory::components::transform &get_transform(void) const { return _transform; }
                const std::string &get_texture_file_path(void) const override { return _file_path; }

            protected:
            private:
                std::string _file_path;
                engine::entity _entity;
                factory::components::transform _transform;
        };
        
    } // entity
    
} // factory


#endif /* TARGET */
