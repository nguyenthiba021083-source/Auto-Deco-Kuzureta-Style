#include "TemplateDatabase.hpp"
#include "KuzuretaGenerator.hpp"

std::vector<TemplateObject> TemplateDatabase::kuzureta() {
    return {
        {KuzuretaIDs::GLOW_CIRCLE,0,0},
        {KuzuretaIDs::CHAIN_A,40,-20},
        {KuzuretaIDs::CRYSTAL_A,-30,30}
    };
}

std::vector<TemplateObject> TemplateDatabase::city() {
    return {
        {KuzuretaIDs::CITY_BLOCK,0,0},
        {KuzuretaIDs::WINDOW_LIGHT,20,20}
    };
}

std::vector<TemplateObject> TemplateDatabase::crystal() {
    return {
        {KuzuretaIDs::CRYSTAL_A,0,0},
        {KuzuretaIDs::CRYSTAL_B,30,40}
    };
}
