#ifndef MOVABLE
#define MOVABLE

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"

/* --------------------------------- Engine --------------------------------- */
#include "coordinator.hpp"

/* -------------------------------- Interface ------------------------------- */
#include "abstract.hpp"

/* ------------------------------- Components ------------------------------- */
#include "transform.hpp"

/* --------------------------------- Entity --------------------------------- */
#include "type.hpp"

namespace factory {

    namespace system {

        class movable : public abstract::system {
            public:

                void update(engine::coordinator &engine, std::map<const factory::entity::type, std::vector<engine::entity> &> &entities) override
                {
                    for (auto &entry : entities) {

                        for (std::size_t it = 0; it != entry.second.size(); it++) {

                            auto &position = engine.get_component<factory::components::transform>(entry.second.at(it)).get_position();

                            switch (entry.first) {
                                case factory::entity::type::target:
                                    if (position.get_x() < screen_width) {
                                        position.set_x(position.get_x() + 1);
                                    } else if (position.get_x() >= screen_width) {
                                        position.set_x_y(0, 0);
                                    } break;
                                default: break;
                            }

                        }

                    }
                }
        
            protected:
            private:
        };
        
    } // system
    
} // factory

#endif /* MOVABLE */
