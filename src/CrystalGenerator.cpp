#include "CrystalGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "KuzuretaGenerator.hpp"
#include "LayoutAnalyzer.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void CrystalGenerator::generate(
    const LayoutStats&
) {
    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return;

    for (int i = 0; i < 100; i++) {

        float x =
            300.f +
            (i % 20) * 40.f;

        float y =
            120.f +
            (i / 20) * 60.f;

        auto obj =
            editor->createObject(
                KuzuretaIDs::CRYSTAL_A,
                {x, y},
                false
            );

        if (!obj)
            continue;

        obj->setScale(1.5f);

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}
