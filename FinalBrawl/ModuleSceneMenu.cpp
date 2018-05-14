#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneMenu.h"



ModuleSceneMenu::ModuleSceneMenu(bool active) : Module(active)
{
    title.x = 0;
    title.y = 0;
    title.w = 959;
    title.h = 200;

}

ModuleSceneMenu::~ModuleSceneMenu()
{
}

bool ModuleSceneMenu::Start()
{
    menuTextures = App->textures->Load("GUISprites/Menu.png");
    return true;
}

update_status ModuleSceneMenu::Update(float deltaTime)
{
    App->renderer->DrawBackground(0, 0, 255, 255);
    App->renderer->Blit(menuTextures, 0, 0, &title);
    return UPDATE_CONTINUE;
}

bool ModuleSceneMenu::CleanUp()
{
    return true;
}