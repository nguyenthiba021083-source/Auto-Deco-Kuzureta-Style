#include "KuzuretaGenerator.hpp"
#include "LayoutAnalyzer.hpp"

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

void KuzuretaGenerator::generate() {

    auto stats = LayoutAnalyzer::analyze();

    log::info("========== Kuzureta Generator ==========");
    log::info("Total Objects: {}", stats.totalObjects);
    log::info("Level Length: {}", stats.levelLength);

    if (stats.totalObjects < 100) {
        log::info("Layout Size: Small");
    }
    else if (stats.totalObjects < 1000) {
        log::info("Layout Size: Medium");
    }
    else {
        log::info("Layout Size: Large");
    }

    log::info("Cube Count: {}", stats.cubeCount);
    log::info("Ship Count: {}", stats.shipCount);
    log::info("Ball Count: {}", stats.ballCount);
    log::info("UFO Count: {}", stats.ufoCount);
    log::info("Wave Count: {}", stats.waveCount);

    // Kuzureta preset statistics

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

    log::info("Glow Objects: {}", glowCount);
    log::info("Crystal Objects: {}", crystalCount);
    log::info("Chain Objects: {}", chainCount);
    log::info("City Objects: {}", cityCount);
    log::info("Window Objects: {}", windowCount);

    log::info("Using Glow ID: {}", ID_GLOW_CIRCLE);
    log::info("Using Crystal ID: {}", ID_CRYSTAL_A);
    log::info("Using Chain ID: {}", ID_CHAIN_A);
    log::info("Using City ID: {}", ID_CITY_BLOCK);

    log::info("Kuzureta Analysis Complete");
}
