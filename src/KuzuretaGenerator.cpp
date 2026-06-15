#include "KuzuretaGenerator.hpp"
#include "LayoutAnalyzer.hpp"
#include "TriggerGenerator.hpp"
#include "ParallaxGenerator.hpp"

void KuzuretaGenerator::generate() {

    auto stats = LayoutAnalyzer::analyze();

    // Deco

    ParallaxGenerator::generateBackgroundCity();
    ParallaxGenerator::generateFarGlow();
    ParallaxGenerator::generateNearGlow();
    ParallaxGenerator::generateForegroundDetail();

    // Triggers

    TriggerGenerator::generatePulseTriggers();
    TriggerGenerator::generateMoveTriggers();
    TriggerGenerator::generateAlphaTriggers();
    TriggerGenerator::generateColorTriggers();
}
