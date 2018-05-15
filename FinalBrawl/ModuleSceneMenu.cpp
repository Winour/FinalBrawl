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

    mainMenuObjects.push_back("MainTitle");
    mainMenuObjects.push_back("NewGame");
    mainMenuObjects.push_back("Credits");
    mainMenuObjects.push_back("Exit");
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
    std::ifstream file("MenuGuiPos.txt");
    if (file.good())
    {
        file >> jsonFile;
        for (int i = 0; i < idNumber; i++)
        {
            App->saveTools->LoadGUIPosition(jsonFile, mainMenuObjects[i], *positions[i]);
        }
        
    }

    return true;
}

update_status ModuleSceneMenu::Update(float deltaTime)
{
    if (App->input->GetKey(SDL_SCANCODE_TAB) == KEY_DOWN)
    {
        ++id;
        id = (id >= idNumber) ? 0 : id;
    }
    std::ofstream file("MenuGuiPos.txt");
    if (file.good())
    {
        jsonFile >> file;
    }

    App->renderer->DrawBackground(0, 0, 255, 255);
    App->renderer->Blit(menuTextures, titlePos.x, titlePos.y, &title);
    return UPDATE_CONTINUE;
}

bool ModuleSceneMenu::CleanUp()
{
    return true;
}