#include "KuzuretaGenerator.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>
#include <cstdlib>

using namespace geode::prelude;

void KuzuretaGenerator::generate() {
    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        FLAlertLayer::create(
            "Auto Deco",
            "Editor NULL",
            "OK"
        )->show();
        return;
    }

    int ids[] = {
        KuzuretaIDs::GLOW_CIRCLE,
        KuzuretaIDs::GLOW_EDGE,
        KuzuretaIDs::CHAIN_A,
        KuzuretaIDs::CHAIN_B,
        KuzuretaIDs::LINE_THIN,
        KuzuretaIDs::CRYSTAL_A,
        KuzuretaIDs::CRYSTAL_B,
        KuzuretaIDs::CITY_BLOCK,
        KuzuretaIDs::WINDOW_LIGHT
    };

    constexpr int count = sizeof(ids) / sizeof(ids[0]);

    for (int i = 0; i < 400; i++) {
        int objectID = ids[rand() % count];

        float x = 300.f + (rand() % 8000);
        float y = 100.f + (rand() % 700);

        auto obj = editor->createObject(
            objectID,
            { x, y },
            false
        );

        if (!obj)
            continue;

        obj->setScale(
            0.5f + (rand() % 150) / 100.f
        );

        obj->setRotation(
            rand() % 360
        );

        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }

    FLAlertLayer::create(
        "Auto Deco",
        "Generated 400 Kuzureta Objects",
        "OK"
    )->show();
}
