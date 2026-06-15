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

static GameObject* createObj(
    LevelEditorLayer* editor,
    int id,
    float x,
    float y,
    float scale = 1.f,
    float rotation = 0.f
) {
    auto obj = editor->createObject(
        id,
        { x, y },
        false
    );

    if (!obj)
        return nullptr;

    obj->setScale(scale);
    obj->setRotation(rotation);

    editor->addObject(obj);

    return obj;
}

void KuzuretaGenerator::generate() {

    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        log::error("Editor not found");
        return;
    }

    auto stats = LayoutAnalyzer::analyze();

    log::info("==============================");
    log::info("KUZURETA GENERATOR");
    log::info("==============================");

    log::info("Objects: {}", stats.totalObjects);
    log::info("Length : {}", stats.levelLength);

    if (stats.totalObjects < 100) {
        log::info("Layout Size: Small");
    }
    else if (stats.totalObjects < 1000) {
        log::info("Layout Size: Medium");
    }
    else {
        log::info("Layout Size: Large");
    }

    //--------------------------------------------------
    // GLOW BACKGROUND
    //--------------------------------------------------

    for (
        float x = 0.f;
        x < stats.levelLength + 1000.f;
        x += 400.f
    ) {

        createObj(
            editor,
            ID_GLOW_CIRCLE,
            x,
            250.f,
            6.f
        );
    }

    //--------------------------------------------------
    // GLOW EDGE
    //--------------------------------------------------

    for (
        float x = 0.f;
        x < stats.levelLength + 1000.f;
        x += 120.f
    ) {

        createObj(
            editor,
            ID_GLOW_EDGE,
            x,
            100.f,
            1.5f
        );
    }

    //--------------------------------------------------
    // CHAINS
    //--------------------------------------------------

    for (
        float x = 0.f;
        x < stats.levelLength + 1000.f;
        x += 300.f
    ) {

        for (
            float y = 450.f;
            y > 0.f;
            y -= 40.f
        ) {

            createObj(
                editor,
                ID_CHAIN_A,
                x,
                y
            );
        }
    }

    //--------------------------------------------------
    // THIN LINES
    //--------------------------------------------------

    for (
        float x = 0.f;
        x < stats.levelLength + 1000.f;
        x += 200.f
    ) {

        createObj(
            editor,
            ID_LINE_THIN,
            x,
            220.f,
            3.f
        );
    }

    //--------------------------------------------------
    // CRYSTALS
    //--------------------------------------------------

    for (
        float x = 200.f;
        x < stats.levelLength;
        x += 250.f
    ) {

        createObj(
            editor,
            ID_CRYSTAL_A,
            x,
            120.f,
            1.5f
        );

        createObj(
            editor,
            ID_CRYSTAL_B,
            x + 60.f,
            160.f,
            1.2f
        );
    }

    //--------------------------------------------------
    // CITY BUILDINGS
    //--------------------------------------------------

    for (
        float x = 0.f;
        x < stats.levelLength + 1000.f;
        x += 120.f
    ) {

        float height =
            100.f + (rand() % 250);

        for (
            float y = 0.f;
            y < height;
            y += 30.f
        ) {

            createObj(
                editor,
                ID_CITY_BLOCK,
                x,
                y
            );
        }
    }

    //--------------------------------------------------
    // WINDOWS
    //--------------------------------------------------

    for (
        float x = 0.f;
        x < stats.levelLength + 1000.f;
        x += 120.f
    ) {

        for (
            float y = 30.f;
            y < 250.f;
            y += 60.f
        ) {

            createObj(
                editor,
                ID_WINDOW_LIGHT,
                x,
                y
            );
        }
    }

    log::info("Kuzureta Deco Generated!");
}
