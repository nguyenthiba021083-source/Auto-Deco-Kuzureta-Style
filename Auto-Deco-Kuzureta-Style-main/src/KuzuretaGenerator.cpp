#include "KuzuretaGenerator.hpp"

#include "LayoutAnalyzer.hpp"
#include "TriggerGenerator.hpp"
#include "ParallaxGenerator.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void KuzuretaGenerator::generate() {

    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        log::error("Editor not found");
        return;
    }

    auto stats = LayoutAnalyzer::analyze();

    log::info("====================");
    log::info("KUZURETA GENERATOR");
    log::info("====================");

    log::info(
        "Objects: {}",
        stats.totalObjects
    );

    log::info(
        "Length: {}",
        stats.levelLength
    );

    log::info(
        "Spikes: {}",
        stats.spikeCount
    );

    log::info(
        "Blocks: {}",
        stats.blockCount
    );

    log::info(
        "Deco: {}",
        stats.decoCount
    );

    log::info(
        "Portals: {}",
        stats.portalCount
    );

    log::info(
        "Triggers: {}",
        stats.triggerCount
    );

    log::info(
        "Orbs: {}",
        stats.orbCount
    );

    log::info(
        "Pads: {}",
        stats.padCount
    );

    //----------------------------------
    // PARALLAX
    //----------------------------------

    ParallaxGenerator::generateBackgroundCity();

    ParallaxGenerator::generateFarGlow();
