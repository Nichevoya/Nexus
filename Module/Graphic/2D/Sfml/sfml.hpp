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

                using namespace nexus::core::interface::graphic;

                class sfml : public lib2D {
                    public:
                        sfml();
                        ~sfml();

                        void update() override;
                        bool status(void) const override;

                    protected:
                    private:
                        bool _status = true;
                };
                
            } // library
            
        } // graphic
        
    } // module
    
} // nexus



#endif /* SFML */
