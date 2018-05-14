#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
    ModuleSceneIntro(bool active = true);
    ~ModuleSceneIntro();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();

private:

    SDL_Texture* textureLogo = nullptr;
    Animation testAnim;
    SDL_Rect background;
};

#endif // !__MODULESCENEINTRO_H__