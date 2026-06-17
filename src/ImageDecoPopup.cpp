cd ~/Auto-Deco-Kuzureta-Style

cat > src/ImageDecoPopup.cpp << 'EOF'
#include "ImageDecoPopup.hpp"

#include "ImageAnalyzer.hpp"
#include "LayoutAnalyzer.hpp"
#include "CrystalGenerator.hpp"
#include "GlowGenerator.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/utils/async.hpp>

using namespace geode::prelude;

void ImageDecoPopup::open() {

    auto future = geode::utils::file::pick(
        geode::utils::file::PickMode::OpenFile,
        {}
    );

    geode::async::spawn(
        std::move(future),
        [](geode::utils::file::PickResult result) {

            if (!result) {
                FLAlertLayer::create(
                    "Error",
                    "Failed to open file picker",
                    "OK"
                )->show();
                return;
            }

            auto picked = result.unwrap();

            if (!picked.has_value()) {
                FLAlertLayer::create(
                    "Cancelled",
                    "No image selected",
                    "OK"
                )->show();
                return;
            }

            auto path = picked.value();

            auto imageResult =
                ImageAnalyzer::analyze(
                    path.string()
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
    );
}
EOF
