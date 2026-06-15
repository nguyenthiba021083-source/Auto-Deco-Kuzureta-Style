#include "KuzuretaGenerator.hpp"
#include "LayoutAnalyzer.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

constexpr int ID_GLOW_CIRCLE   = 1006;
constexpr int ID_GLOW_EDGE     = 915;

constexpr int ID_CHAIN_A       = 102;
constexpr int ID_CHAIN_B       = 103;

constexpr int ID_LINE_THIN     = 1613;

constexpr int ID_CRYSTAL_A     = 1732;
constexpr int ID_CRYSTAL_B     = 1733;

constexpr int ID_CITY_BLOCK    = 211;
constexpr int ID_WINDOW_LIGHT  = 673;

static void spawnDeco(
    LevelEditorLayer* editor,
    int objectID,
    float x,
    float y
) {
    auto obj = editor->createObject(
        objectID,
        { x, y },
        false
    );

    if (obj) {
        editor->addObject(obj);
    }
}

void KuzuretaGenerator::generate() {

    auto stats = LayoutAnalyzer::analyze();

    log::info("========== Kuzureta Generator ==========");
    log::info("Objects: {}", stats.totalObjects);
    log::info("Length: {}", stats.levelLength);

    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        log::error("EditorLayerBridge editor is null");
        return;
    }

    int glowCount = 200;
    int crystalCount = 80;
    int chainCount = 50;
    int cityCount = 40;
    int windowCount = 120;

    if (stats.totalObjects < 100) {
        glowCount = 80;
        crystalCount = 30;
        chainCount = 20;
        cityCount = 15;
        windowCount = 40;
    }
    else if (stats.totalObjects < 1000) {
        glowCount = 150;
        crystalCount = 60;
        chainCount = 35;
        cityCount = 25;
        windowCount = 80;
    }

    float startX = 1000.f;
    float baseY = 150.f;

    log::info("Generating Glow");

    for (int i = 0; i < glowCount; i++) {

        spawnDeco(
            editor,
            ID_GLOW_CIRCLE,
            startX + i * 120.f,
            baseY + 180.f
        );
    }

    log::info("Generating Crystal");

    for (int i = 0; i < crystalCount; i++) {

        spawnDeco(
            editor,
            (i % 2 == 0 ? ID_CRYSTAL_A : ID_CRYSTAL_B),
            startX + i * 300.f,
            baseY - 50.f
        );
    }

    log::info("Generating Chains");

    for (int i = 0; i < chainCount; i++) {

        spawnDeco(
            editor,
            (i % 2 == 0 ? ID_CHAIN_A : ID_CHAIN_B),
            startX + i * 200.f,
            baseY + 350.f
        );
    }

    log::info("Generating Glow Edge");

    for (int i = 0; i < glowCount / 2; i++) {

        spawnDeco(
            editor,
            ID_GLOW_EDGE,
            startX + i * 140.f,
            baseY + 50.f
        );
    }

    log::info("Generating City");

    for (int i = 0; i < cityCount; i++) {

        spawnDeco(
            editor,
            ID_CITY_BLOCK,
            startX + i * 250.f,
            baseY - 200.f
        );
    }

    log::info("Generating Windows");

    for (int i = 0; i < windowCount; i++) {

        spawnDeco(
            editor,
            ID_WINDOW_LIGHT,
            startX + i * 80.f,
            baseY - 180.f
        );
    }

    log::info("Generating Grid Lines");

    for (int i = 0; i < 100; i++) {

        spawnDeco(
            editor,
            ID_LINE_THIN,
            startX + i * 100.f,
            baseY + 100.f
        );
    }

    log::info("========== Kuzureta Deco Complete ==========");
}
