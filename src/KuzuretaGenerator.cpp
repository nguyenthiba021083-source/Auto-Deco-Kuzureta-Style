#include "KuzuretaGenerator.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void KuzuretaGenerator::generate() {
    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        FLAlertLayer::create(
            "Auto Deco",
            "Editor not found!",
            "OK"
        )->show();
        return;
    }

    FLAlertLayer::create(
        "Auto Deco",
        "Generator Started!",
        "OK"
    )->show();

    log::info("Kuzureta Generator Started");
}
