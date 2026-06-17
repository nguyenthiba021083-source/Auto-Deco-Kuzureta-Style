#include "ImageDecoPopup.hpp"

#include "ImageAnalyzer.hpp"
#include "LayoutAnalyzer.hpp"
#include "CrystalGenerator.hpp"
#include "GlowGenerator.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void ImageDecoPopup::open() {
    std::string path =
        "/storage/emulated/0/Pictures/build.png";

    auto result = ImageAnalyzer::analyze(path);
    auto stats = LayoutAnalyzer::analyze();

    if (result.theme == "CRYSTAL") {
        CrystalGenerator::generate(stats);
    }
    else if (result.theme == "GLOW") {
        GlowGenerator::generate(stats);
    }
    else {
        KuzuretaGenerator::generate();
    }

    FLAlertLayer::create(
        "Build From Image",
        ("Theme: " + result.theme).c_str(),
        "OK"
    )->show();
}
