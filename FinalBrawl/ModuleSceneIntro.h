#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "ModuleScene.h"
#include "Globals.h"
#include "Point.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleSceneIntro : public ModuleScene
{
public:
    ModuleSceneIntro(bool active = true);
    ~ModuleSceneIntro();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();

private:

    SDL_Texture* textureLogo = nullptr;
    iPoint logoPos;
    Animation logoAnim;
};

#endif // !__MODULESCENEINTRO_H__