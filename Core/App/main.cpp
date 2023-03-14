#include "nexus.hpp"

int main(const int ac, const char **av)
{
    try {
        nexus::core::app::nexus instance(ac, av);
        instance.run();
        return exit_success;
    } catch (const std::exception &error) {
        err_logs("Standard exception" << std::endl << "\t" << error.what() << std::endl << "Exit failure " << exit_failure);
        return exit_failure;
    } catch (...) {
        err_logs("Fatal error " << fatal_error);
        return fatal_error;
    }
}

