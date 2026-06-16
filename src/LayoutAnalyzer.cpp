#include "LayoutAnalyzer.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

LayoutStats LayoutAnalyzer::analyze() {

    LayoutStats stats;

    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return stats;

    auto objects = editor->m_objects;

    if (!objects)
        return stats;

    stats.totalObjects = objects->count();

    float maxX = 0.f;

    CCObject* obj = nullptr;

    CCARRAY_FOREACH(objects, obj) {

        auto gameObj =
            static_cast<GameObject*>(obj);

        if (!gameObj)
            continue;

        int id = gameObj->m_objectID;

        maxX = std::max(
            maxX,
            gameObj->getPositionX()
        );

        if (id <= 8)
            stats.spikeCount++;

        else if (id <= 200)
            stats.blockCount++;

        else if (id >= 700 && id <= 900)
            stats.portalCount++;

        else if (id >= 1000 && id <= 1300)
            stats.triggerCount++;

        else if (id >= 30 && id <= 60)
            stats.orbCount++;

        else if (id >= 130 && id <= 160)
            stats.padCount++;

        else
            stats.decoCount++;
    }

    stats.levelLength = maxX;

    return stats;
}
