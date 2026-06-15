LayoutStats LayoutAnalyzer::analyze() {
    LayoutStats stats;

    auto editor = EditorLayerBridge::editor;

    if (!editor)
        return stats;

    auto objects = editor->m_objects;

    if (!objects)
        return stats;

    stats.totalObjects = objects->count();

    CCObject* obj = nullptr;

    CCARRAY_FOREACH(objects, obj) {

        auto gameObj = static_cast<GameObject*>(obj);

        if (!gameObj)
            continue;

        int id = gameObj->m_objectID;

        if (id == 12)
            stats.shipCount++;

        else if (id == 13)
            stats.ballCount++;

        else if (id == 47)
            stats.waveCount++;
    }

    return stats;
}
