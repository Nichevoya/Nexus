#ifndef RESSOURCE
#define RESSOURCE

/* --------------------------------- Define --------------------------------- */
#define exit_success 0
#define exit_failure -1
#define fatal_error -2

#ifdef DEBUG
    #define logs(message) std::cout << message << std::endl
    #define err_logs(message) std::cerr << message << std::endl
#else
    #define logs(message)
    #define err_logs(message)
#endif

/* ---------------------------- Standard Library ---------------------------- */
#include <iostream>
#include <string>
#include <assert.h>

#include <filesystem>

#include <typeinfo>
#include <bitset>
#include <set>

#include <memory>
#include <thread>
#include <mutex>

#include <chrono>

#include <unordered_map>
#include <vector>
#include <array>
#include <queue>
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

                        static status &get(void) { static status instance; return instance; };

                        void set_status(const bool status) { get()._status = status; }
                        bool get_status(void) const { return get()._status; }

                    protected:
                    private:
                        status() { logs("System status " << _status); }
                        ~status()
                        {
                            set_status(false);
                            logs("System status " << _status);
                        }

                        bool _status = true;
                };
                
            } // intergrity
            
        } // app
        
    } // Core

} // nexus

#endif /* RESSOURCE */
