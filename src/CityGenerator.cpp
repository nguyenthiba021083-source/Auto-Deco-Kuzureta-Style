#include "CityGenerator.hpp"
#include "EditorLayerBridge.hpp"
#include "KuzuretaGenerator.hpp"
#include "ThemeSystem.hpp"
#include "ClusterSystem.hpp"
#include "DensitySystem.hpp"
#include "TemplateDatabase.hpp"

#include <Geode/Geode.hpp>
#include <cstdlib>

using namespace geode::prelude;

void CityGenerator::generate(const LayoutStats&) {
    auto editor = EditorLayerBridge::editor;
    if (!editor) return;

    for (int i = 0; i < 100; i++) {
        auto obj = editor->createObject(
            KuzuretaIDs::CITY_BLOCK,
            {200.f + i * 120.f, 60.f},
            false
        );

        if (!obj) continue;

        obj->setScale(2.f + rand() % 4);

        editor->addChild(obj);
        editor->m_objects->addObject(obj);
        editor->addSpecial(obj);
        editor->objectMoved(obj);
    }
}
