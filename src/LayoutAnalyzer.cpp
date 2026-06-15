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

    stats.totalObjects = objects->count();

    CCObject* obj;

    CCARRAY_FOREACH(objects, obj) {

        auto gameObj = static_cast<GameObject*>(obj);

        int id = gameObj->m_objectID;

        if (id == 12)
            stats.shipCount++;

        if (id == 13)
            stats.ballCount++;

        if (id == 47)
            stats.waveCount++;
    }

    log::info("Objects: {}", stats.totalObjects);

    return stats;
}
