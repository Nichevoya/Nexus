#ifndef RAYLIB
#define RAYLIB

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"
#include "graphic.hpp"

/* --------------------------------- Raylib --------------------------------- */
#include "raylib.h"

namespace nexus {

    namespace module {

        namespace graphic {

            namespace library {

                using namespace nexus::core::interface::graphic;

                class raylib : public lib3D {
                    public:
                        raylib();
                        ~raylib();

                        void initialization(void) const;
                        void update(void) override;
                        bool status(void) const override;

                    protected:
                    private:
                };
                
            } // library
            
        } // graphic
        
    } // module
    
} // nexus

#endif /* RAYLIB */
