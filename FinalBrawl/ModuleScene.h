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
    }

    ~ModuleScene()
    {
    }
    bool EditGUI()
    {
        LOG("%d", positions.size());
        bool ret = false;

        if (App->input->GetKey(SDL_SCANCODE_TAB) == KEY_DOWN)
        {
            ++id;
            id = (id >= mainMenuObjects.size()) ? 0 : id;
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
    
    bool LoadGUI(const char* path)
    {
        std::ifstream file(path);
        if (file.good())
        {
            file >> jsonFile;
            for (int i = 0; i < mainMenuObjects.size(); i++)
            {
                App->saveTools->LoadGUIPosition(jsonFile, mainMenuObjects[i], *positions[i]);
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
                App->saveTools->SaveGUIPosition(jsonFile, mainMenuObjects[id], *positions[id]);
                jsonFile >> file;
            }
        }
    }

protected:
    std::vector<std::string> mainMenuObjects;
    std::vector<iPoint*> positions;
    bool canEdit;
    Json jsonFile;
    int id;

};

#endif // !__MODULESCENE_H__
