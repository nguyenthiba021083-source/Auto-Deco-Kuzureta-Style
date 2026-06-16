#include "CityGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void CityGenerator::generate(
    const LayoutStats&
) {
    auto editor =
        EditorLayerBridge::editor;

    if (!editor)
        return;

    for (int i = 0; i < 150; i++) {

        auto obj =
            editor->createObject(
                KuzuretaIDs::CITY_BLOCK,
                {
                    200.f + i * 80.f,
                    60.f
                },
                false
            );

        if (!obj)
            continue;

        obj->setScale(
            2.f +
            ((i % 5) * 0.5f)
        );

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}
