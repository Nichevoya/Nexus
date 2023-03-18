#include "hunter.hpp"

using namespace nexus::module::logic;

extern "C" const std::unique_ptr<hunter> entry_point(void) { return std::make_unique<hunter>(); }

hunter::hunter() {}

hunter::~hunter() {}
