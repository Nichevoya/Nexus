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

                        void set_status(const bool status) { _status = status; }
                        bool get_status(void) const { return _status; }

                    protected:
                        status() { logs("System status " << _status); }
                        ~status() { logs("System status " << _status); }
                    private:
                        static status *_instance;
                        static std::mutex _mutex;
                        bool _status = true;
                };
                
            } // intergrity
            
        } // app
        
    } // Core

} // nexus

#endif /* RESSOURCE */
