#ifndef SFML
#define SFML

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"
#include "graphic.hpp"

/* ---------------------------------- SFML ---------------------------------- */
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

namespace nexus {

    namespace module {

        namespace graphic {

            namespace library {

                class sfml : public nexus::core::interface::graphic::lib2D {
                    public:
                        sfml();
                        ~sfml();

                        void initialisation(void);
                        void update(void) override;
                            void event_update(void);
                        
                        bool status(void) const override;

                        void set_texture_file_list(const std::map<std::string, std::vector<std::string>> &texture_file_list) override;

                    protected:
                    private:
                        sf::Event _event;
                        sf::RenderWindow _window;

                        std::map<std::string, std::vector<std::string>> _texture_file_list;
                };
                
            } // library
            
        } // graphic
        
    } // module
    
} // nexus



#endif /* SFML */
