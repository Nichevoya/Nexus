#ifndef RESSOURCE
#define RESSOURCE

/* --------------------------------- Define --------------------------------- */
#define exit_success 0
#define exit_failure -1
#define fatal_error -2

#define logs(message) std::cout << message << std::endl
#define err_logs(message) std::cerr << message << std::endl

/* ---------------------------- Standard Library ---------------------------- */
#include <iostream>
#include <string>

#include <filesystem>

#include <memory>
#include <thread>
#include <mutex>

#include <vector>
#include <map>

/* -------------------------------- Exception ------------------------------- */
class exception : public std::runtime_error {
    public: exception(const std::string &message) : std::runtime_error(message) { err_logs("Exception:"); }
};

/* ------------------------------ Global ------------------------------ */

/* -------------------------------- App ------------------------------- */
namespace nexus {

    namespace core {

        namespace app {

            namespace integrity {

                class status {
                    public:
                        void operator=(const status &) = delete;
                        status(const status &) = delete;

                        static status *get(void);
                        void destroy(void) const { delete get(); }

                        void set_status(const bool status) { _is_active = status; }
                        bool is_active(void) const { return _is_active; }

                    protected:
                        status() { logs("System status " << _is_active); }
                        ~status() { logs("System status " << _is_active); }
                    private:
                        static status *_instance;
                        static std::mutex _mutex;
                        bool _is_active = true;
                };
                
            } // intergrity
            
        } // app
        
    } // Core

} // nexus

#endif /* RESSOURCE */
