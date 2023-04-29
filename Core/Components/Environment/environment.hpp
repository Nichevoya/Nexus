#ifndef ENVIRONMENT
#define ENVIRONMENT

/* Source */
#include "ressource.hpp"
#include "command.hpp"

enum class terminal_log_type {
    none,
    nexus,
    message,
    error,
    load,
    list,
};

namespace nexus {

    namespace core {

        namespace components {

            class environment {
                public:
                    explicit environment();
                    ~environment();

                    void set_log_type(const terminal_log_type &log_type) { _log_type = log_type; }

                    const std::string &get_input(void) const { return _input; }
                    const terminal_log_type &get_log_type(void) const { return _log_type; }
                    
                    void initialization(void);

                    void format(const terminal_log_type &log_type);
                    void log(const terminal_log_type &log_type, const std::string &message);
                    
                    void start(void);
                    
                    void input(void);
                    const std::string &input(const std::string &message);
                    const std::string &input(const std::string &message, const terminal_log_type &log_type);

                    void set_command_type_from_input(void);
                    void action(void);

                protected:
                private:
                    bool _is_active = true;

                    std::string _input = "";
                    terminal_log_type _log_type = terminal_log_type::none;
                    command _command = command_type::none;
                    
                    app::integrity::status *_app = app::integrity::status::get();
            };
            
        } // components
        
    } // core

} // nexus


#endif /* ENVIRONMENT */
