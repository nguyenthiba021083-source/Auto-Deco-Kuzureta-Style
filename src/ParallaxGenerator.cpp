#include "ParallaxGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "LayoutAnalyzer.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

constexpr int CITY_BLOCK = 211;
constexpr int GLOW_OBJ   = 1006;
constexpr int DETAIL_OBJ = 1732;

static void place(
    LevelEditorLayer* editor,
    int id,
    float x,
    float y,
    float scale
) {

    auto obj = editor->createObject(
        id,
        {x,y},
        false
    );

    if(!obj)
        return;

    obj->setScale(scale);

    editor->addObject(obj);
}

void ParallaxGenerator::generateBackgroundCity() {

    auto editor = EditorLayerBridge::editor;
    auto stats  = LayoutAnalyzer::analyze();

    if(!editor)
        return;

    for(float x = 0;
        x < stats.levelLength + 1000;
        x += 160)
    {
        place(
            editor,
            CITY_BLOCK,
            x,
            -120,
            4.f
        );
    }
}

void ParallaxGenerator::generateFarGlow() {

    auto editor = EditorLayerBridge::editor;
    auto stats  = LayoutAnalyzer::analyze();

    if(!editor)
        return;

    for(float x = 0;
        x < stats.levelLength;
        x += 300)
    {
        place(
            editor,
            GLOW_OBJ,
            x,
            350,
            6.f
        );
    }
}

void ParallaxGenerator::generateNearGlow() {

    auto editor = EditorLayerBridge::editor;
    auto stats  = LayoutAnalyzer::analyze();

    if(!editor)
        return;

    for(float x = 0;
        x < stats.levelLength;
        x += 180)
    {
        place(
            editor,
            GLOW_OBJ,
            x,
            180,
            3.f
        );
    }
}

void ParallaxGenerator::generateForegroundDetail() {

    auto editor = EditorLayerBridge::editor;
    auto stats  = LayoutAnalyzer::analyze();

    if(!editor)
        return;

    for(float x = 0;
        x < stats.levelLength;
        x += 120)
    {
        place(
            editor,
            DETAIL_OBJ,
            x,
            90,
            1.5f
        );
    }
}
