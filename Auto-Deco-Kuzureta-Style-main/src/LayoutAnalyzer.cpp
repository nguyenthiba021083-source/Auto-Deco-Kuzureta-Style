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

        //---------------------------------
        // LEVEL LENGTH
        //---------------------------------

        if (gameObj->getPositionX() > maxX)
            maxX = gameObj->getPositionX();

        //---------------------------------
        // OBJECT TYPE
        //---------------------------------

        int id = gameObj->m_objectID;

        // Spikes

        if (
            id == 8 ||
            id == 39 ||
            id == 103 ||
            id == 392
        ) {
            stats.spikeCount++;
        }

        // Blocks

        else if (
            id >= 1 &&
            id <= 500
        ) {
            stats.blockCount++;
        }

        // Portals

        else if (
            id == 12 ||
            id == 13 ||
            id == 47 ||
            id == 111 ||
            id == 660
        ) {
            stats.portalCount++;
        }

        // Orbs

        else if (
            id == 36 ||
            id == 84 ||
            id == 141 ||
            id == 1022
        ) {
            stats.orbCount++;
        }

        // Pads

        else if (
            id == 35 ||
            id == 67 ||
            id == 140
        ) {
            stats.padCount++;
        }

        // Triggers

        else if (
            id >= 899 &&
            id <= 1616
        ) {
            stats.triggerCount++;
        }

        // Decoration

        else {
            stats.decoCount++;
        }
    }

    stats.levelLength = maxX;

    return stats;
}
