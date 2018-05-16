#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"


ModuleSceneIntro::ModuleSceneIntro(bool active) : ModuleScene(active)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            logoAnim.frames.push_back({ j * 1024 , i * 669 , 1024 , 669 });
        }
    }

    logoAnim.speed = 0.1f;
    logoAnim.loop = false;

    positions.push_back(&logoPos);
    guiObjects.push_back("Logo");
}


ModuleSceneIntro::~ModuleSceneIntro()
{
}

bool ModuleSceneIntro::Start() 
{
    textureLogo = App->textures->Load("SpriteSheet/Logo/WinourLogoSpriteSheet.png");
    LoadGUI("GUIInfo/IntroGuiPos.txt");
    return true;
}

update_status ModuleSceneIntro::Update(float deltaTime)
{
    App->renderer->DrawBackground((Uint8)160, (Uint8)190, (Uint8)255, (Uint8)255);

    ActivateEdition();
    SaveGUI("GUIInfo/IntroGuiPos.txt");

    if (!App->fade->isFading())
    {
        App->renderer->Blit(textureLogo, logoPos.x, logoPos.y, &logoAnim.GetCurrentFrame(), 0.0f);
    }
    if (logoAnim.Finished() && !App->fade->isFading())
    {
        App->fade->FadeToBlack((Module*)App->sceneMenu,this,1.0f);
    }
    return UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp() 
{
    return true;
}