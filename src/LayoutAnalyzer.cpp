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

    for (unsigned int i = 0; i < objects->count(); i++) {
        auto gameObj = static_cast<GameObject*>(objects->objectAtIndex(i));

        if (!gameObj)
            continue;

        if (gameObj->getPositionX() > maxX)
            maxX = gameObj->getPositionX();

        int id = gameObj->m_objectID;

        if (id == 8 || id == 39 || id == 103 || id == 392) {
            stats.spikeCount++;
        }
        else if (id >= 1 && id <= 500) {
            stats.blockCount++;
        }
        else if (id == 12 || id == 13 || id == 47 || id == 111 || id == 660) {
            stats.portalCount++;
        }
    }

    stats.levelLength = maxX;
    stats.startX = 0.f;
    stats.endX = maxX > 500.f ? maxX : 10000.f;
    stats.avgY = 250.f;
    return stats;
}
