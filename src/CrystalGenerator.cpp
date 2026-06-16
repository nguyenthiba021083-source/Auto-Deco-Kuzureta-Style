#include "CrystalGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>
#include <cstdlib>

using namespace geode::prelude;

void CrystalGenerator::generate(const LayoutStats& stats) {
    auto editor = EditorLayerBridge::editor;
    if (!editor) return;

    for (int i = 0; i < 80; i++) {
        float x = stats.startX + rand() % (int)(stats.endX - stats.startX);
        float y = 80.f + rand() % 400;

        auto obj = editor->createObject(
            KuzuretaIDs::CRYSTAL_A,
            {x, y},
            false
        );

        if (!obj) continue;

        obj->setScale(1.5f);

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}
