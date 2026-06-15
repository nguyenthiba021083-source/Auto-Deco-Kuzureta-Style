#include "KuzuretaGenerator.hpp"
#include "LayoutAnalyzer.hpp"

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

    auto stats = LayoutAnalyzer::analyze();

    log::info("========== KUZURETA ANALYZER ==========");
    log::info("Objects: {}", stats.totalObjects);
    log::info("Cube: {}", stats.cubeCount);
    log::info("Ship: {}", stats.shipCount);
    log::info("Ball: {}", stats.ballCount);
    log::info("UFO: {}", stats.ufoCount);
    log::info("Wave: {}", stats.waveCount);

    int glowCount = 200;
    int crystalCount = 80;
    int chainCount = 50;
    int cityCount = 40;

    if (stats.totalObjects < 100) {
        glowCount = 80;
        crystalCount = 30;
        chainCount = 20;
        cityCount = 15;
    }

    else if (stats.totalObjects < 1000) {
        glowCount = 150;
        crystalCount = 60;
        chainCount = 35;
        cityCount = 30;
    }

    log::info("========== KUZURETA PRESET ==========");
    log::info("Glow {}", glowCount);
    log::info("Crystal {}", crystalCount);
    log::info("Chain {}", chainCount);
    log::info("City {}", cityCount);

    log::info("Glow ID {}", ID_GLOW_CIRCLE);
    log::info("Glow Edge ID {}", ID_GLOW_EDGE);

    log::info("Crystal A {}", ID_CRYSTAL_A);
    log::info("Crystal B {}", ID_CRYSTAL_B);

    log::info("Chain A {}", ID_CHAIN_A);
    log::info("Chain B {}", ID_CHAIN_B);

    log::info("Line {}", ID_LINE_THIN);

    log::info("City Block {}", ID_CITY_BLOCK);
    log::info("Window {}", ID_WINDOW_LIGHT);

    // ====================================
    // REAL DECORATION GENERATION HERE
    // ====================================

    auto editor = LevelEditorLayer::get();

    if (!editor) {
        log::error("Editor not found");
        return;
    }

    float startX = 1000.f;

    for (int i = 0; i < glowCount; i++) {

        float x = startX + i * 30.f;
        float y = 200.f + (i % 5) * 40.f;

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
        float y = 100.f;

        auto obj = editor->createObject(
            ID_CRYSTAL_A,
            {x, y},
            false
        );

        if (obj)
            editor->addObject(obj);
    }

    log::info("Kuzureta generation complete");
}
