#ifndef __MODULESCENEMENU_H__
#define __MODULESCENEMENU_H__

#include "ModuleScene.h"
#include "Globals.h"
#include "Point.h"
#include "Animation.h"
#include "nlohmann\json.hpp"
#include <fstream>
#include <string>

struct SDL_Texture;

class ModuleSceneMenu : public ModuleScene
{
public:
    ModuleSceneMenu(bool active = true);
    ~ModuleSceneMenu();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();

private:


private: 
    SDL_Texture* menuTextures = nullptr;
    SDL_Rect background;
    SDL_Rect title;
    SDL_Rect newGame;
    SDL_Rect credits;
    SDL_Rect exit;
    iPoint backgroundPos;
    iPoint titlePos;
    iPoint newGamePos;
    iPoint creditsPos;
    iPoint exitPos;

};

#endif // !__MODULESCENEMENU_H__
