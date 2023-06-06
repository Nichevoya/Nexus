#include "sfml.hpp"

using namespace nexus::module::graphic::library;

extern "C" const std::unique_ptr<sfml> entry_point(void) { return std::make_unique<sfml>(); }

sfml::sfml() { logs("SFML Start"); }

sfml::~sfml() { logs("SFML Stop"); }

void sfml::update(void) {}

bool sfml::status(void) const { return _status; }
