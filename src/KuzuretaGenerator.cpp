#include "KuzuretaGenerator.hpp"
#include "LayoutAnalyzer.hpp"
#include "EditorLayerBridge.hpp"
#include "TriggerGenerator.hpp"
#include "ParallaxGenerator.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

static int s_group = 100;
static int s_color = 10;

static int nextGroup() {
    return s_group++;
}

static int nextColor() {
    return s_color++;
}

static float randScale(
    float min,
    float max
) {
    return min +
        (float)rand() / RAND_MAX *
        (max - min);
}

static float randRotation() {
    return rand() % 360;
}

static GameObject* createDeco(
    LevelEditorLayer* editor,
    int id,
    float x,
    float y
) {

    auto obj =
        editor->createObject(
            id,
            {x,y},
            false
        );

    if (!obj)
        return nullptr;

    obj->setScale(
        randScale(0.8f, 2.5f)
    );

    obj->setRotation(
        randRotation()
    );

    obj->m_groupID = nextGroup();

    obj->m_colorID = nextColor();

    obj->m_zLayer =
        ZLayer::Top;

    editor->addObject(obj);

    return obj;
}

void KuzuretaGenerator::generate() {

    auto editor =
        EditorLayerBridge::editor;

    if (!editor)
        return;

    auto stats =
        LayoutAnalyzer::analyze();

    float len =
        stats.levelLength + 1000.f;

    //--------------------------------
    // Background Glow
    //--------------------------------

    for (
        float x = 0;
        x < len;
        x += 350
    ) {

        createDeco(
            editor,
            1006,
            x,
            320
        );
    }

    //--------------------------------
    // Crystal Layer
    //--------------------------------

    for (
        float x = 150;
        x < len;
        x += 220
    ) {

        createDeco(
            editor,
            1732,
            x,
            120
        );

        createDeco(
            editor,
            1733,
            x + 50,
            150
        );
    }

    //--------------------------------
    // Chain Layer
    //--------------------------------

    for (
        float x = 0;
        x < len;
        x += 280
    ) {

        for (
            float y = 500;
            y > 0;
            y -= 40
        ) {

            createDeco(
                editor,
                102,
                x,
                y
            );
        }
    }

    //--------------------------------
    // Buildings
    //--------------------------------

    for (
        float x = 0;
        x < len;
        x += 120
    ) {

        int h =
            3 + rand() % 10;

        for (
            int i = 0;
            i < h;
            i++
        ) {

            createDeco(
                editor,
                211,
                x,
                i * 30
            );
        }
    }

    //--------------------------------
    // Parallax
    //--------------------------------

    ParallaxGenerator::
        generateBackgroundCity();

    ParallaxGenerator::
        generateFarGlow();

    ParallaxGenerator::
        generateNearGlow();

    ParallaxGenerator::
        generateForegroundDetail();

    //--------------------------------
    // Triggers
    //--------------------------------

    TriggerGenerator::
        generatePulseTriggers();

    TriggerGenerator::
        generateMoveTriggers();

    TriggerGenerator::
        generateAlphaTriggers();

    TriggerGenerator::
        generateColorTriggers();

    log::info(
        "Kuzureta AI Deco Complete"
    );
}
