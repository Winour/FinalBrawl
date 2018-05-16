#ifndef __MODULESCENE_H__
#define __MODULESCENE_H__

#include "Module.h"
#include "Point.h"
#include "Globals.h"
#include "nlohmann\json.hpp"

class ModuleScene : public Module
{
public:
    ModuleScene(bool active = true) : Module(active)
    {
        id = 0;
        canEdit = false;
    }

    ~ModuleScene()
    {
    }

    bool EditGUI()
    {
        bool ret = false;

        if (App->input->GetKey(SDL_SCANCODE_TAB) == KEY_DOWN)
        {
            ++id;
            id = (id >= guiObjects.size()) ? 0 : id;
        }
        if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
        {
            positions[id]->x += 1;
            ret = true;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
        {
            positions[id]->y -= 1;
            ret = true;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
        {
            positions[id]->y += 1;
            ret = true;
        }
        if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
        {
            positions[id]->x -= 1;
            ret = true;
        }
        return ret;
    }
    
    void ActivateEdition()
    {
        if (App->input->GetKey(SDL_SCANCODE_0) == KEY_DOWN)
        {
            canEdit = !canEdit;
        }
    }

    bool LoadGUI(const char* path)
    {
        std::ifstream file(path);
        if (file.good())
        {
            file >> jsonFile;
            for (int i = 0; i < guiObjects.size(); i++)
            {
                App->saveTools->LoadGUIPosition(jsonFile, guiObjects[i], *positions[i]);
            }
            return true;
        }
        return false;
    }

    void SaveGUI(const char* path)
    {
        if (canEdit && EditGUI())
        {
            std::ofstream file(path);
            if (file.good())
            {
                App->saveTools->SaveGUIPosition(jsonFile, guiObjects[id], *positions[id]);
                jsonFile >> file;
            }
        }
    }
    
    void DrawGUI(SDL_Texture& texture)
    {
        for (int i = 0; i < guiObjects.size(); i++)
        {
            App->renderer->Blit(&texture, positions[i]->x, positions[i]->y, rects[i]);
        }
    }

protected:
    std::vector<std::string> guiObjects;
    std::vector<iPoint*> positions;
    std::vector<SDL_Rect*> rects;
    bool canEdit;
    Json jsonFile;
    int id;

};

#endif // !__MODULESCENE_H__
