#include "raylib.hpp"

using namespace nexus::module::graphic::library;

extern "C" const std::unique_ptr<raylib> entry_point(void) { return std::make_unique<raylib>(); }

raylib::raylib()
{
    logs("Raylib Start");
    initialization();
}

raylib::~raylib()
{
    CloseWindow();
    logs("Raylib Stop");
}

void raylib::initialization(void) const
{
    InitWindow(800, 800, "Nexus");
    SetTargetFPS(60);
}

void raylib::update(void)
{
    //NOTE - Update Logic Here
    BeginDrawing();
    
        ClearBackground(BLACK);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    
    EndDrawing();
}

bool raylib::status(void) const
{
    return !WindowShouldClose();
}
