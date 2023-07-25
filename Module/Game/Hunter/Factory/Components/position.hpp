#ifndef POSITION
#define POSITION

namespace factory {

    namespace components {

        struct position {
            public:
                void set_x(const int &x) { _x = x; }
                void set_y(const int &y) { _y = y; }
                void set_z(const int &z) { _z = z; }

                void set_x_y(const int &x, const int &y) { _x = x; _y = y; }
                void set_x_y_z(const int &x, const int &y, const int &z) { _x = x; _y = y; _z = z; }

                int get_x(void) const { return _x; }
                int get_y(void) const { return _y; }
                int get_z(void) const { return _z; }

            protected:
            private:
                int _x = 0, _y = 0, _z = 0;
        };
        
    } // components
    
} // factory

#endif /* POSITION */
