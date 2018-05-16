#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneMenu.h"



ModuleSceneMenu::ModuleSceneMenu(bool active) : ModuleScene(active)
{
    title.x = 0;
    title.y = 0;
    title.w = 959;
    title.h = 200;
    newGame.x = 0;
    newGame.y = 204;
    newGame.w = 539;
    newGame.h = 84;
    credits.x = 0;
    credits.y = 301;
    credits.w = 328;
    credits.h = 78;
    exit.x = 0;
    exit.y = 392;
    exit.w = 200;
    exit.h = 72;

    rects.push_back(&title);
    rects.push_back(&newGame);
    rects.push_back(&credits);
    rects.push_back(&exit);
    guiObjects.push_back("MainTitle");
    guiObjects.push_back("NewGame");
    guiObjects.push_back("Credits");
    guiObjects.push_back("Exit");
    positions.push_back(&titlePos);
    positions.push_back(&newGamePos);
    positions.push_back(&creditsPos);
    positions.push_back(&exitPos);
}

ModuleSceneMenu::~ModuleSceneMenu()
{
}

bool ModuleSceneMenu::Start()
{
    menuTextures = App->textures->Load("GUISprites/Menu.png");
    LoadGUI("MenuGuiPos.txt");
    canEdit = false;
    id = 0;

    return true;
}

update_status ModuleSceneMenu::Update(float deltaTime)
{
    if (App->input->GetKey(SDL_SCANCODE_0) == KEY_DOWN)
    {
        canEdit = !canEdit;
    }
    SaveGUI("MenuGuiPos.txt");

    App->renderer->DrawBackground(0, 0, 255, 255);
    DrawGUI(*menuTextures);

    return UPDATE_CONTINUE;
}

bool ModuleSceneMenu::CleanUp()
{
    return true;
}
