#include "ImageDecoPopup.hpp"

#include "ImageAnalyzer.hpp"
#include "LayoutAnalyzer.hpp"
#include "CrystalGenerator.hpp"
#include "GlowGenerator.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>

using namespace geode::prelude;

void ImageDecoPopup::open() {
    geode::utils::file::pick(
        geode::utils::file::PickMode::OpenFile,
        {}
    ).listen([](auto result) {

        if (!result) {
            FLAlertLayer::create(
                "Build From Image",
                "No image selected",
                "OK"
            )->show();
            return;
        }

        auto path = result.unwrap();

        auto analysis =
            ImageAnalyzer::analyze(
                path.string()
            );

        auto stats =
            LayoutAnalyzer::analyze();

        if (analysis.theme == "CRYSTAL") {
            CrystalGenerator::generate(stats);
        }
        else if (analysis.theme == "GLOW") {
            GlowGenerator::generate(stats);
        }
        else {
            KuzuretaGenerator::generate();
        }

        std::string message =
            "Theme: " +
            analysis.theme +
            "\nCrystal: " +
            std::to_string(
                analysis.crystalDensity
            ) +
            "%\nGlow: " +
            std::to_string(
                analysis.glowDensity
            ) +
            "%\nFog: " +
            std::to_string(
                analysis.fogDensity
            ) +
            "%";

        FLAlertLayer::create(
            "Build From Image",
            message.c_str(),
            "OK"
        )->show();
    });
}
