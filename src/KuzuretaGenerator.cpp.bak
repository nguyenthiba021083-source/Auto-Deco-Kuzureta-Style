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
        1,      // block
        2,
        8,
        39,
        103,
        130
    };

    constexpr int count = sizeof(ids) / sizeof(ids[0]);

    int created = 0;

    for (int i = 0; i < 200; i++) {
        int objectID = ids[rand() % count];

        float x = 50.f + (i * 10.f);
        float y = 50.f;

        auto obj = editor->createObject(
            objectID,
            {x, y},
            false
        );

        if (!obj)
            continue;

        
        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);

        created++;
    }

    FLAlertLayer::create(
        "Auto Deco",
        fmt::format("Created {} Objects", created).c_str(),
        "OK"
    )->show();
}
