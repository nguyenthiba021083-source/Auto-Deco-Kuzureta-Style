#include "ParallaxGenerator.hpp"
#include "LayoutAnalyzer.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

static GameObject* createObj(
    LevelEditorLayer* editor,
    int id,
    float x,
    float y,
    float scale = 1.f
) {
    auto obj = editor->createObject(
        id,
        { x, y },
        false
    );

    if (!obj)
        return nullptr;

    obj->setScale(scale);

    log::info(
        "Created object {} at ({}, {})",
        id,
        x,
        y
    );

    return obj;
}

void ParallaxGenerator::generateBackgroundCity() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    auto stats = LayoutAnalyzer::analyze();

    for (float x = 0.f; x < stats.levelLength; x += 120.f) {
        createObj(
            editor,
            1,
            x,
            -50.f,
            5.f
        );
    }
}

void ParallaxGenerator::generateFarGlow() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    auto stats = LayoutAnalyzer::analyze();

    for (float x = 0.f; x < stats.levelLength; x += 350.f) {
        createObj(
            editor,
            1,
            x,
            250.f,
            8.f
        );
    }
}

void ParallaxGenerator::generateNearGlow() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    auto stats = LayoutAnalyzer::analyze();

    for (float x = 0.f; x < stats.levelLength; x += 220.f) {
        createObj(
            editor,
            1,
            x,
            180.f,
            4.f
        );
    }
}

void ParallaxGenerator::generateForegroundDetail() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    auto stats = LayoutAnalyzer::analyze();

    for (float x = 0.f; x < stats.levelLength; x += 200.f) {
        createObj(
            editor,
            1,
            x,
            300.f,
            1.f
        );
    }
}
