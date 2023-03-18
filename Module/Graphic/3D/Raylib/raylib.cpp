#include "raylib.hpp"

using namespace nexus::module::graphic::library;

extern "C" const std::unique_ptr<raylib> entry_point(void) { return std::make_unique<raylib>(); }

raylib::raylib() { logs("Raylib Start"); }

raylib::~raylib() { logs("Raylib Start"); }
