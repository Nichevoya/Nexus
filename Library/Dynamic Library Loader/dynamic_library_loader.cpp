#include "dynamic_library_loader.hpp"

//? Dynamic Library Loader (.so)
static_library_loader::static_library_loader() {}

static_library_loader::~static_library_loader() {}

void *static_library_loader::open_file(std::string const &file)
{
    _handler = dlopen(file.c_str(), RTLD_LAZY);
    if (_handler == nullptr) {
        err_logs("Library loader: " << error_logs());
        return nullptr;
    } else {
        logs(file << ": opened");
        return _handler;
    }
}

int static_library_loader::close_file(void) const { return dlclose(_handler); }

char *static_library_loader::error_logs(void) const { return dlerror(); }
