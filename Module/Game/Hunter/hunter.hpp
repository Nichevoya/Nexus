#ifndef HUNTER
#define HUNTER

/* --------------------------------- Source --------------------------------- */
#include "ressource.hpp"
#include "logic.hpp"

namespace nexus {

    namespace module {

        namespace logic {

            using namespace nexus::core::interface::logic;

            class hunter : public game {
                public:
                    hunter();
                    ~hunter();

                    void update() override;
                    bool status(void) const override;

                protected:
                private:
                    bool _status = true;
            };
            
        } // logic
        
    } // module
    
} // nexus


#endif /* HUNTER */
