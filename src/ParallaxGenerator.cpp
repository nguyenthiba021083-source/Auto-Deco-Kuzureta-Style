#include "ParallaxGenerator.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void ParallaxGenerator::generateBackgroundCity() {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    auto obj = editor->createObject(
        1,
        {300.f, 150.f},
        false
    );

    if (!obj) {
        FLAlertLayer::create(
            "Auto Deco",
            "Create Failed",
            "OK"
        )->show();
        return;
    }

    editor->m_objects->addObject(obj);

    FLAlertLayer::create(
        "Auto Deco",
        "Added To m_objects",
        "OK"
    )->show();
}

void ParallaxGenerator::generateFarGlow() {}
void ParallaxGenerator::generateNearGlow() {}
void ParallaxGenerator::generateForegroundDetail() {}
