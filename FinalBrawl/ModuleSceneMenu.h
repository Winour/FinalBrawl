#ifndef __MODULESCENEMENU_H__
#define __MODULESCENEMENU_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"
#include "Animation.h"
#include "nlohmann\json.hpp"
#include <fstream>
#include <string>

struct SDL_Texture;

class ModuleSceneMenu : public Module
{
public:
    ModuleSceneMenu(bool active = true);
    ~ModuleSceneMenu();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();

private: 
    SDL_Rect title;
    SDL_Rect newGame;
    SDL_Rect exit;
    iPoint titlePos;
    iPoint newGamePos;
    iPoint creditsPos;
    iPoint exitPos;

    std::vector<std::string> mainMenuObjects;
    std::vector<iPoint*> positions;
    int id = 0;
    int idNumber = 4;
    Json jsonFile;

    SDL_Texture* menuTextures = nullptr;
};

#endif // !__MODULESCENEMENU_H__
