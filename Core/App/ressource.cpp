#include "ressource.hpp"

using namespace nexus::core::app::integrity;

status *status::_instance = nullptr;
std::mutex status::_mutex;

status *status::get(void)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _instance == nullptr && (_instance = new status{});
    return _instance;
}
