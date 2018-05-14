#ifndef __MODULESCENEMENU_H__
#define __MODULESCENEMENU_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"
#include "Animation.h"

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
    SDL_Rect background;
    SDL_Rect title;
    SDL_Rect newGame;
    SDL_Rect exit;

    SDL_Texture* menuTextures;
};

#endif // !__MODULESCENEMENU_H__
