#include "KuzuretaGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "LayoutAnalyzer.hpp"
#include "ClusterSystem.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void KuzuretaGenerator::generate() {
    auto editor = EditorLayerBridge::editor;
    if (!editor) return;

    auto stats = LayoutAnalyzer::analyze();

    float center =
        (stats.startX + stats.endX) * 0.5f;

    for (int i = 0; i < 400; i++) {

        int ids[] = {
            1,
            2,
            8,
            39,
            103,
            130
        };

        int objectID =
            ids[i % 6];

        float x =
            center - 2500.f +
            (i * 12.f);

        float y =
            stats.avgY +
            ((i % 20) - 10) * 8.f;

        auto obj =
            editor->createObject(
                objectID,
                {x,y},
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
