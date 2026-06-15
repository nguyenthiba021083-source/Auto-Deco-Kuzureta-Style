#include "KuzuretaGenerator.hpp"
#include "LayoutAnalyzer.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

constexpr int ID_GLOW_CIRCLE  = 1006;
constexpr int ID_GLOW_EDGE    = 915;

constexpr int ID_CHAIN_A      = 102;
constexpr int ID_CHAIN_B      = 103;

constexpr int ID_LINE_THIN    = 1613;

constexpr int ID_CRYSTAL_A    = 1732;
constexpr int ID_CRYSTAL_B    = 1733;

constexpr int ID_CITY_BLOCK   = 211;
constexpr int ID_WINDOW_LIGHT = 673;

void KuzuretaGenerator::generate() {

    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        log::error("EditorLayer not found");
        return;
    }

    auto stats = LayoutAnalyzer::analyze();

    log::info("========== KUZURETA ==========");
    log::info("Objects {}", stats.totalObjects);

    float startX = 1000.f;

    int glowCount = 80;
    int crystalCount = 30;
    int chainCount = 20;

    if (stats.totalObjects > 1000) {
        glowCount = 200;
        crystalCount = 80;
        chainCount = 50;
    }

    for (int i = 0; i < glowCount; i++) {

        float x = startX + i * 40.f;
        float y = 250.f;

        auto obj = editor->createObject(
            ID_GLOW_CIRCLE,
            {x, y},
            false
        );

        if (obj)
            editor->addObject(obj);
    }

    for (int i = 0; i < crystalCount; i++) {

        float x = startX + i * 70.f;
        float y = 120.f;

        auto obj = editor->createObject(
            ID_CRYSTAL_A,
            {x, y},
            false
        );

        if (obj)
            editor->addObject(obj);
    }

    for (int i = 0; i < chainCount; i++) {

        float x = startX + i * 120.f;
        float y = 400.f;

        auto obj = editor->createObject(
            ID_CHAIN_A,
            {x, y},
            false
        );

        if (obj)
            editor->addObject(obj);
    }

    log::info("Kuzureta generation finished");
}
