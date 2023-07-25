#include "hunter.hpp"

using namespace nexus::module::logic;

extern "C" const std::unique_ptr<hunter> entry_point(void) { return std::make_unique<hunter>(); }

hunter::hunter()
{
    logs("Hunter start");
    _engine.initialization();
    this->initialization();
}

hunter::~hunter() { logs("Hunter stop"); }


void hunter::initialization(void)
{
    factory();
    assemble();
}

void hunter::factory(void)
{
    component_factory();
    system_factory();
}

void hunter::assemble(void)
{
    assemble_targets();
}

const std::map<std::string, std::vector<std::string>> &hunter::get_texture_file_list(void) const { return _texture_file_list; }

void hunter::update(void)
{
    systems_update();
}

void hunter::systems_update(void)
{
    for (const auto &system : _systems) {
        system->update(_engine, _entities);
    }
}

bool hunter::status(void) const { return _status; }
