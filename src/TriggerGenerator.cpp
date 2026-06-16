#include "TriggerGenerator.hpp"
#include "LayoutAnalyzer.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

constexpr int PULSE_TRIGGER = 1006;
constexpr int MOVE_TRIGGER  = 901;

static GameObject* createTrigger(
    LevelEditorLayer* editor,
    int id,
    float x,
    float y
) {
    auto obj = editor->createObject(
        id,
        { x, y },
        false
    );

    if (!obj) {
        log::error("FAILED OBJECT {}", id);
        return nullptr;
    }

    log::info("CREATED OBJECT {}", id);

    return obj;
}

void TriggerGenerator::generatePulseTriggers() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    auto stats = LayoutAnalyzer::analyze();

    for (float x = 0.f; x < stats.levelLength; x += 500.f) {
        createTrigger(
            editor,
            PULSE_TRIGGER,
            x,
            -300.f
        );
    }
}

void TriggerGenerator::generateMoveTriggers() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    auto stats = LayoutAnalyzer::analyze();

    for (float x = 250.f; x < stats.levelLength; x += 700.f) {
        createTrigger(
            editor,
            MOVE_TRIGGER,
            x,
            -350.f
        );
    }
}
