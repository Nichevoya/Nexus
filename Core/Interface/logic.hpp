#ifndef LOGIC
#define LOGIC

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"

namespace nexus {
    
    namespace core {
        
        namespace interface {

            namespace logic {

                class game {
                    public:
                        virtual ~game() = default;

                        virtual void update(void) = 0;
                        virtual bool status(void) const = 0;

                    protected:
                    private:
                };
                
            } // logic
                
        } // interface

    } // core

} // nexus

#endif /* LOGIC */
