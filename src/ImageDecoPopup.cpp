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

            FLAlertLayer::create(
                "DEBUG PATH",
                path.string().c_str(),
                "OK"
            )->show();

            return;
        }
    );
}
