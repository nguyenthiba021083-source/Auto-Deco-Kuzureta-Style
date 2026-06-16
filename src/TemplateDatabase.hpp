#pragma once
#include <vector>

struct TemplateObject {
    int objectID;
    float offsetX;
    float offsetY;
};

class TemplateDatabase {
public:
    static std::vector<TemplateObject> kuzureta();
    static std::vector<TemplateObject> city();
    static std::vector<TemplateObject> crystal();
};
