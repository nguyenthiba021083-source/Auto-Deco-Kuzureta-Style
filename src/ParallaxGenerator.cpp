#include "ParallaxGenerator.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void ParallaxGenerator::generateBackgroundCity() {
    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        FLAlertLayer::create(
            "Auto Deco",
            "EditorLayer NULL",
            "OK"
        )->show();
        return;
    }

    float startX = 300.f;

    for (int i = 0; i < 20; i++) {
        auto obj = editor->createObject(
            1,
            { startX + i * 30.f, 150.f },
            false
        );

        if (!obj)
            continue;

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }

    FLAlertLayer::create(
        "Auto Deco",
        "20 Objects Added",
        "OK"
    )->show();
}

void ParallaxGenerator::generateFarGlow() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    for (int i = 0; i < 15; i++) {
        auto obj = editor->createObject(
            1764,
            { 250.f + i * 60.f, 300.f },
            false
        );

        if (!obj)
            continue;

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}

void ParallaxGenerator::generateNearGlow() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    for (int i = 0; i < 15; i++) {
        auto obj = editor->createObject(
            1765,
            { 250.f + i * 60.f, 200.f },
            false
        );

        if (!obj)
            continue;

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}

void ParallaxGenerator::generateForegroundDetail() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    for (int i = 0; i < 25; i++) {
        auto obj = editor->createObject(
            1,
            { 150.f + i * 30.f, 90.f },
            false
        );

        if (!obj)
            continue;

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}
