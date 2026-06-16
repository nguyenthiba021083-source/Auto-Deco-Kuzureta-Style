#include <Geode/Geode.hpp>

#include "ImageAnalyzer.hpp"
#include "StyleClassifier.hpp"
#include "LayoutAnalyzer.hpp"

#include "KuzuretaGenerator.hpp"
#include "CrystalGenerator.hpp"
#include "GlowGenerator.hpp"

using namespace geode::prelude;

class ImageDecoPopup : public FLAlertLayer {
public:
    static void show() {

        auto analysis =
            ImageAnalyzer::analyze(
                "/storage/emulated/0/Pictures/build.png"
            );

        auto theme =
            StyleClassifier::classify(
                analysis
            );

        auto stats =
            LayoutAnalyzer::analyze();

        if (theme == "CRYSTAL") {
            CrystalGenerator::generate(stats);
        }
        else if (theme == "GLOW") {
            GlowGenerator::generate(stats);
        }
        else {
            KuzuretaGenerator::generate();
        }

        FLAlertLayer::create(
            "Build From Image",
            ("Theme: " + theme).c_str(),
            "OK"
        )->show();
    }
};
