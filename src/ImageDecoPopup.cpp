#include "ImageDecoPopup.hpp"

#include "ImageAnalyzer.hpp"
#include "LayoutAnalyzer.hpp"
#include "CrystalGenerator.hpp"
#include "GlowGenerator.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void ImageDecoPopup::open() {
    auto imageResult =
        ImageAnalyzer::analyze(
            "/storage/emulated/0/Pictures/build.png"
        );

    auto stats =
        LayoutAnalyzer::analyze();

    if (imageResult.theme == "CRYSTAL") {
        CrystalGenerator::generate(stats);
    }
    else if (imageResult.theme == "GLOW") {
        GlowGenerator::generate(stats);
    }
    else {
        KuzuretaGenerator::generate();
    }

    FLAlertLayer::create(
        "Build From Image",
        ("Theme: " + imageResult.theme).c_str(),
        "OK"
    )->show();
}
