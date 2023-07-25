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

#define screen_width 1920
#define screen_height 1080

/* ---------------------------- Standard Library ---------------------------- */
#include <iostream>
#include <assert.h>
#include <string>

#include <filesystem>

#include <typeinfo>
#include <bitset>
#include <set>

#include <memory>
#include <thread>
#include <mutex>

#include <chrono>
#include <random>

#include <unordered_map>
#include <vector>
#include <array>
#include <queue>
#include <map>


/* -------------------------------- Exception ------------------------------- */

/**
 * @brief Exception handler object
 * 
 */
class exception : public std::runtime_error {
    public: exception(const std::string &message) : std::runtime_error(message) { err_logs("Exception:"); }
};

namespace nexus {

    namespace core {

        /* ------------------------------ Global ------------------------------ */
        namespace global {

            /**
             * @brief Global random utility object
             * 
             */
            class random {
                public:

                    /**
                     * @brief Return a random integer between 0 and RAND_MAX inclusive
                     * 
                     * @return int 
                     */
                    static int number(void) { return std::rand(); }
                    
                    /**
                     * @brief Return a random integer between the given range inclusive
                     * 
                     * @param from Lowest number from which the range will start
                     * @param to Highest number from which the range will stop
                     * @return int 
                     */
                    static int ranged_number(const int from, const int to) { return std::rand() % (to + 1 - from) + from; }
            
                protected:
                private:
            };
            
        } // global
        
        /* -------------------------------- App ------------------------------- */
        namespace app {

            namespace integrity {

                /**
                 * @brief Define the application status and gives control over it
                 * 
                 */
                class status {
                    public:
                        void operator=(const status &) = delete;
                        status(const status &) = delete;

                        /**
                         * @brief Return a unique reference to the status object
                         * 
                         * @return status& 
                         */
                        static status &get(void) { static status instance; return instance; };

                        /**
                         * @brief Set the status
                         * 
                         * @param status 
                         */
                        void set_status(const bool status) { get()._status = status; }
                        
                        /**
                         * @brief Get the status
                         * 
                         * @return true 
                         * @return false 
                         */
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
