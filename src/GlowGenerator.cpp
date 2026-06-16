#include "GlowGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void GlowGenerator::generate(const LayoutStats& stats) {
    auto editor = EditorLayerBridge::editor;
    if (!editor) return;

    for (float x = stats.startX; x < stats.endX; x += 120.f) {
        auto obj = editor->createObject(
            KuzuretaIDs::GLOW_CIRCLE,
            {x, stats.avgY + 100.f},
            false
        );

        if (!obj) continue;

        obj->setScale(2.5f);

        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}
