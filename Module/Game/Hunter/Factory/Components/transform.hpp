#ifndef TRANSFORM
#define TRANSFORM

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"

/* ------------------------------- Components ------------------------------- */
#include "force.hpp"
#include "position.hpp"

namespace factory {

    namespace components {

        struct transform {
            public:
                force &get_force(void) { return _force; }
                const force &get_force(void) const { return _force; }

                position &get_position(void) { return _position; }
                const position &get_position(void) const { return _position; }

            protected:
            private:
                force _force;
                position _position;
        };
        
    } // components
    
} // factory

#endif /* TRANSFORM */
