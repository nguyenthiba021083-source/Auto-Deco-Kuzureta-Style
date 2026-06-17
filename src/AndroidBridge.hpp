#pragma once
#include <string>

class AndroidBridge {
public:
    static void openImagePicker();
    static std::string getSelectedImage();
    static void setSelectedImage(std::string const& path);
};
