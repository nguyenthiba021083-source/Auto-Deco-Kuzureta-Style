#include "ImageDecoPopup.hpp"

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
                log::error("pick failed");
                return;
            }

            auto picked = result.unwrap();

            if (!picked.has_value()) {
                log::info("no file selected");
                return;
            }

            auto path = picked.value();

            log::info(
                "picked file = {}",
                path.string()
            );
        }
    );
}
