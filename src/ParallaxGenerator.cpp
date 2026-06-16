#include "ParallaxGenerator.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

static void testCreate() {
    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        FLAlertLayer::create(
            "Auto Deco",
            "Editor NULL",
            "OK"
        )->show();
        return;
    }

    auto obj = editor->createObject(
        1,
        { 300.f, 150.f },
        false
    );

    if (obj) {
        FLAlertLayer::create(
            "Auto Deco",
            "Object Created!",
            "OK"
        )->show();
    }
    else {
        FLAlertLayer::create(
            "Auto Deco",
            "Create Failed!",
            "OK"
        )->show();
    }
}

void ParallaxGenerator::generateBackgroundCity() {
    testCreate();
}

void ParallaxGenerator::generateFarGlow() {}
void ParallaxGenerator::generateNearGlow() {}
void ParallaxGenerator::generateForegroundDetail() {}
