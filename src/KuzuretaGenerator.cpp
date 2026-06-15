#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void KuzuretaGenerator::generate() {

    log::info("========== Auto-Deco-Kuzureta ==========");

    log::info("Glow Circle ID: {}", KuzuretaIDs::GLOW_CIRCLE);
    log::info("Glow Edge ID: {}", KuzuretaIDs::GLOW_EDGE);

    log::info("Chain A ID: {}", KuzuretaIDs::CHAIN_A);
    log::info("Chain B ID: {}", KuzuretaIDs::CHAIN_B);

    log::info("Line ID: {}", KuzuretaIDs::LINE_THIN);

    log::info("Crystal A ID: {}", KuzuretaIDs::CRYSTAL_A);
    log::info("Crystal B ID: {}", KuzuretaIDs::CRYSTAL_B);

    log::info("City Block ID: {}", KuzuretaIDs::CITY_BLOCK);
    log::info("Window Light ID: {}", KuzuretaIDs::WINDOW_LIGHT);

    log::info("Generating Kuzureta Style...");

    for (int i = 0; i < 200; i++) {
        log::debug("Glow {}", i);
    }

    for (int i = 0; i < 80; i++) {
        log::debug("Crystal {}", i);
    }

    for (int i = 0; i < 50; i++) {
        log::debug("Chain {}", i);
    }

    log::info("Generation Finished");
}
