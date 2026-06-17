#include "ImageDecoPopup.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void ImageDecoPopup::open() {
    FLAlertLayer::create(
        "Auto Deco",
        "Image Deco Popup Loaded",
        "OK"
    )->show();
}
