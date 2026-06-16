#include "TriggerGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "LayoutAnalyzer.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

constexpr int PULSE_TRIGGER = 1006;
constexpr int MOVE_TRIGGER  = 901;
constexpr int ALPHA_TRIGGER = 1007;
constexpr int COLOR_TRIGGER = 899;

static void spawnTrigger(
    LevelEditorLayer* editor,
    int id,
    float x,
    float y
) {
    auto obj = editor->createObject(
        id,
        {x,y},
        false
    );

    if (!obj)
        return;

    editor->addObject(obj);
}

void TriggerGenerator::generatePulseTriggers() {

    auto stats = LayoutAnalyzer::analyze();
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    for(float x = 0;
        x < stats.levelLength;
        x += 600.f)
    {
        spawnTrigger(
            editor,
            PULSE_TRIGGER,
            x,
            300.f
        );
    }
}

void TriggerGenerator::generateMoveTriggers() {

    auto stats = LayoutAnalyzer::analyze();
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    for(float x = 300;
        x < stats.levelLength;
        x += 800.f)
    {
        spawnTrigger(
            editor,
            MOVE_TRIGGER,
            x,
            350.f
        );
    }
}

void TriggerGenerator::generateAlphaTriggers() {

    auto stats = LayoutAnalyzer::analyze();
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    for(float x = 200;
        x < stats.levelLength;
        x += 700.f)
    {
        spawnTrigger(
            editor,
            ALPHA_TRIGGER,
            x,
            250.f
        );
    }
}

void TriggerGenerator::generateColorTriggers() {

    auto stats = LayoutAnalyzer::analyze();
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    for(float x = 100;
        x < stats.levelLength;
        x += 500.f)
    {
        spawnTrigger(
            editor,
            COLOR_TRIGGER,
            x,
            200.f
        );
    }
}
