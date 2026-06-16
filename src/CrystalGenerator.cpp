#include "CrystalGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "KuzuretaGenerator.hpp"
#include "LayoutAnalyzer.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void CrystalGenerator::generate(
    const LayoutStats& stats
) {
    auto editor =
        EditorLayerBridge::editor;

    if (!editor)
        return;

    float center =
        (stats.startX + stats.endX) * 0.5f;

    for (int i = 0; i < 200; i++) {

        float x =
            center +
            ((i % 40) - 20) * 60.f;

        float y =
            120.f +
            (i % 8) * 45.f;

        auto obj =
            editor->createObject(
                KuzuretaIDs::CRYSTAL_A,
                {x,y},
                false
            );

        if (!obj)
            continue;

        obj->setScale(
            1.f +
            ((i % 4) * 0.3f)
        );

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}
