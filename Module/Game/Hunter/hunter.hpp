#ifndef HUNTER
#define HUNTER

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"
#include "logic.hpp"

/* -------------------------------- Construct ------------------------------- */
#include "construct.hpp"

/* --------------------------------- Engine --------------------------------- */
#include "coordinator.hpp"

/* -------------------------------- Interface ------------------------------- */
#include "abstract.hpp"

/* -------------------------------- Component ------------------------------- */
#include "force.hpp"
#include "position.hpp"
#include "transform.hpp"

/* --------------------------------- System --------------------------------- */
#include "movable.hpp"

namespace nexus {

    namespace module {

        namespace logic {

            class hunter : public nexus::core::interface::logic::game {
                public:
                    hunter();
                    ~hunter();

                    void initialization(void);
                    void factory(void);
                        void component_factory(void)
                        {
                            //NOTE - Space
                            _engine.register_component<factory::components::force>();
                            _engine.register_component<factory::components::position>();
                            _engine.register_component<factory::components::transform>();
                            
                        }

                        void system_factory(void)
                        {
                            auto movable = _engine.register_system<factory::system::movable>();
                            {
                                _engine.set_system_signature<factory::system::movable>(engine::signature{}.set(_engine.get_component_type<factory::components::transform>()));
                            }

                            _systems.push_back(movable);
                        }

                    void assemble(void);
                        void assemble_targets(void)
                        {
                            for(std::size_t nb = 0; nb < 1; nb++) {
                                const auto entity = _engine.create_entity();
                                _engine.add_component<factory::components::transform>(entity, factory::components::transform{});
                                _targets.push_back(entity);
                            }

                            _entities.insert({factory::entity::type::target, _targets});
                        }

                    const std::map<std::string, std::vector<std::string>> &get_texture_file_list(void) const override;

                    void update() override;
                        void systems_update(void);

                    bool status(void) const override;

                protected:
                private:
                    bool _status = true;

                    engine::coordinator _engine;
                    factory::entity::construct _construct;

                    std::map<std::string, std::vector<std::string>> _texture_file_list;
                    
                    std::vector<std::shared_ptr<factory::abstract::system>> _systems;

                    std::vector<engine::entity> _targets;
                    std::map<const factory::entity::type, std::vector<engine::entity> &> _entities;                    
            };
            
        } // logic
        
    } // module
    
} // nexus


#endif /* HUNTER */
