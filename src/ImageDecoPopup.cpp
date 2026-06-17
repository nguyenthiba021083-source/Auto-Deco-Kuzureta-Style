#include "ImageDecoPopup.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

void ImageDecoPopup::open() {
    FLAlertLayer::create(
        "Build From Image",
        "Nhap duong dan anh se duoc them sau",
        "OK"
    )->show();
}
