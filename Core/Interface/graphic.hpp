#ifndef GRAPHIC
#define GRAPHIC

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"

namespace nexus {
    
    namespace core {
        
        namespace interface {

            namespace graphic {

                class lib3D {
                    public:
                        virtual ~lib3D() = default;

                        virtual void update(void) = 0;
                        virtual bool status(void) const = 0;

                    protected:
                    private:
                };

                class lib2D {
                    public:
                        virtual ~lib2D() = default;

                        virtual void update(void) = 0;
                        virtual bool status(void) const = 0;


                    protected:
                    private:
                };
                
            } // graphic
                
        } // interface

    } // core

} // nexus

#endif /* GRAPHIC */
