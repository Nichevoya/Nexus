#ifndef GRAPHIC
#define GRAPHIC

/* Source */
#include "ressource.hpp"

namespace nexus {
    
    namespace core {
        
        namespace interface {

            namespace graphic {

                class lib3D {
                    public:
                        virtual ~lib3D() = default;
                    protected:
                    private:
                };

                class lib2D {
                    public:
                        virtual ~lib2D() = default;
                    protected:
                    private:
                };
                
            } // graphic
                
        } // interface

    } // core

} // nexus

#endif /* GRAPHIC */
