#ifndef __SAVETOOLS_H__
#define __SAVETOOLS_H__

#include "nlohmann\json.hpp"
#include "Point.h"
#include <string>
#include <fstream>

class SaveTools
{
public:
    SaveTools()
    {
    }

    void SaveGUIPosition(Json& jsonFile, const std::string& name, const iPoint& point)
    {
        jsonFile[name]["x"] = point.x;
        jsonFile[name]["y"] = point.y;
    }

    void LoadGUIPosition(const Json& jsonFile, const std::string& name, iPoint& point)
    {
        point.x = jsonFile[name]["x"];
        point.y = jsonFile[name]["y"];
    }

private:

};

#endif // !__SAVETOOLS_H__
