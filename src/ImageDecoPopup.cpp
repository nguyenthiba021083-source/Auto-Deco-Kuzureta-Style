#include "ImageDecoPopup.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

void ImageDecoPopup::open() {
    FLAlertLayer::create(
        "Build From Image",
        "Popup Opened",
        "OK"
    )->show();
}
