#ifndef COORDINATOR
#define COORDINATOR

/* --------------------------------- Engine --------------------------------- */
#include "component.hpp"
#include "system.hpp"

        namespace engine {

            class coordinator {
                public:
                    coordinator(const coordinator &) = delete;
                    explicit coordinator() {}
                    ~coordinator() {}

                    void initialization()
                    {
                        _entity_manager = std::make_unique<entity_manager>();
                        _component_manager = std::make_unique<component_manager>();
                        _system_manager = std::make_unique<system_manager>();
                    }

                    // entity Methods
                    entity create_entity(void)
                    {
                        return _entity_manager->create_entity();
                    }

                    void destroy_entity(const entity entity)
                    {
                        _entity_manager->destroy_entity(entity);
                        _component_manager->entity_destroyed(entity);
                        _system_manager->entity_destroyed(entity);
                    }

                    // Component Methods
                    template <typename T>
                    void register_component(void)
                    {
                        _component_manager->register_component<T>();
                    }

                    template <typename T>
                    void add_component(entity entity, T component)
                    {
                        _component_manager->add_component<T>(entity, component);

                        auto signature = _entity_manager->get_signature(entity);
                        signature.set(_component_manager->get_component_type<T>(), true);
                        _entity_manager->set_signature(entity, signature);

                        _system_manager->entity_signature_changed(entity, signature);
                    }

                    template <typename T>
                    void remove_component(entity entity)
                    {
                        _component_manager->remove_component<T>(entity);

                        auto signature = _entity_manager->get_signature(entity);
                        signature.set(_component_manager->get_component_type<T>(), false);
                        _entity_manager->set_signature(entity, signature);

                        _system_manager->entity_signature_changed(entity, signature);
                    }

                    template <typename T>
                    T &get_component(entity entity) const
                    {   
                        return _component_manager->get_component<T>(entity);
                    }

                    template <typename T>
                    component_type get_component_type() const
                    {
                        return _component_manager->get_component_type<T>();
                    }

                    // System Methods
                    template <typename T>
                    std::shared_ptr<T> register_system()
                    {
                        return _system_manager->register_system<T>();
                    }

                    template <typename T>
                    void set_system_signature(signature signature)
                    {
                        _system_manager->set_signature<T>(signature);
                    }

                protected:
                private:
                    std::unique_ptr<entity_manager> _entity_manager;
                    std::unique_ptr<component_manager> _component_manager;
                    std::unique_ptr<system_manager> _system_manager;
            };
            
        } // engine

#endif /* COORDINATOR */
