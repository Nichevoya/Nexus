#ifndef FORCE
#define FORCE

namespace factory {

    namespace components {

        struct force {
            public:
                void set_scale(const double &scale) { _scale = scale; }
                void set_speed(const double &speed) { _speed = speed; }
                
                double get_scale(void) const { return _scale; }
                double get_speed(void) const { return _speed; }

            protected:
            private:
                double _scale = 0.0, _speed = 0.0;
        };
        
    } // components
    
} // factory

#endif /* FORCE */
