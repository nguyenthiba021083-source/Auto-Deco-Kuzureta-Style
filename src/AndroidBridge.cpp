#include "AndroidBridge.hpp"

static std::string gSelectedImage;

void AndroidBridge::openImagePicker() {
    // TODO: Android Gallery Picker
}

std::string AndroidBridge::getSelectedImage() {
    return gSelectedImage;
}

void AndroidBridge::setSelectedImage(std::string const& path) {
    gSelectedImage = path;
}
