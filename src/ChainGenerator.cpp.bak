#include "ChainGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void ChainGenerator::generate(const LayoutStats&) {
    auto editor = EditorLayerBridge::editor;
    if (!editor) return;

    for (int c = 0; c < 50; c++) {
        float x = 300.f + c * 200.f;

        for (int y = 700; y > 300; y -= 30) {
            auto obj = editor->createObject(
                KuzuretaIDs::CHAIN_A,
                {x, (float)y},
                false
            );

            if (!obj) continue;

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
            editor->addSpecial(obj);
            editor->objectMoved(obj);
        }
    }
}
