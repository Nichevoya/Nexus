#ifndef SYSTEM
#define SYSTEM

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"

/* --------------------------------- Engine --------------------------------- */
#include "entity.hpp"

        namespace engine {

            class system_loader {
                public:
                    
                    std::set<entity> get_entity_set() { return _entities; }

                protected:
                private:
                    std::set<entity> _entities;
            };

            class system_manager {
                public:
                    template <typename T>
                    std::shared_ptr<T> register_system()
                    {
                        const char *type_name = typeid(T).name();

                        assert(_systems.find(type_name) == _systems.end() && "Registering system more than once.");

                        // Create a pointer to the system and return it so it can be used externally
                        auto system = std::make_shared<T>();
                        _systems.insert({type_name, system});
                        return system;
                    }

                    template <typename T>
                    void set_signature(signature signature)
                    {
                        const char *type_name = typeid(T).name();

                        assert(_systems.find(type_name) != _systems.end() && "System used before registered.");

                        // Set the signature for this system
                        _signatures.insert({type_name, signature});
                    }

                    void entity_destroyed(entity entity)
                    {
                        // Erase a destroyed entity from all system lists
                        // _Entities is a set so no check needed
                        for (const auto &pair : _systems) {
                            const std::shared_ptr<system_loader> &system = pair.second;
                            system->get_entity_set().erase(entity);
                        }
                    }

                    void entity_signature_changed(entity entity, signature entity_signature)
                    {
                        // Notify each system that an entity's signature changed
                        for (const auto &pair : _systems) {
                            const char *const &type = pair.first;
                            const std::shared_ptr<system_loader> &system = pair.second;
                            const signature &system_signature = _signatures[type];

                            // entity signature matches system signature - insert into set
                            if ((entity_signature &system_signature) == system_signature) {
                                system->get_entity_set().insert(entity);
                            }
                            // entity signature does not match system signature - erase from set
                            else {
                                system->get_entity_set().erase(entity);
                            }
                        }
                    }

                private:
                    // Map from system type string pointer to a signature
                    std::unordered_map<const char *, signature> _signatures = {};

                    // Map from system type string pointer to a system pointer
                    std::unordered_map<const char *, std::shared_ptr<system_loader>> _systems = {};
            };

        } // engine

#endif /* SYSTEM */
