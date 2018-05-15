#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"


ModuleSceneIntro::ModuleSceneIntro(bool active) : Module(active)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            testAnim.frames.push_back({ j * 1024 , i * 669 , 1024 , 669 });
        }
    }

    testAnim.speed = 0.1f;
    testAnim.loop = false;
}


ModuleSceneIntro::~ModuleSceneIntro()
{
}

bool ModuleSceneIntro::Start() 
{

    textureLogo = App->textures->Load("SpriteSheet/Logo/WinourLogoSpriteSheet.png");

    return true;
}

update_status ModuleSceneIntro::Update(float deltaTime)
{


    App->renderer->DrawBackground((Uint8)160, (Uint8)190, (Uint8)255, (Uint8)255);
    if (!App->fade->isFading())
    {
        App->renderer->Blit(textureLogo, 200, 130, &testAnim.GetCurrentFrame(), 0.0f);
    }
    if (testAnim.Finished())
    {
        App->fade->FadeToBlack((Module*)App->sceneMenu,this,0.0f);
    }
    return UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp() 
{
    return true;
}