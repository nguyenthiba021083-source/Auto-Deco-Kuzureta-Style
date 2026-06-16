#include "ImageAnalyzer.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "thirdparty/stb_image.h"

ImageAnalysisResult ImageAnalyzer::analyze(std::string const& path) {
    ImageAnalysisResult result{};

    int w = 0;
    int h = 0;
    int channels = 0;

    auto data = stbi_load(
        path.c_str(),
        &w,
        &h,
        &channels,
        3
    );

    if (!data) {
        result.theme = "UNKNOWN";
        return result;
    }

    long long r = 0;
    long long g = 0;
    long long b = 0;

    int pixels = w * h;

    for (int i = 0; i < pixels * 3; i += 3) {
        r += data[i];
        g += data[i + 1];
        b += data[i + 2];
    }

    stbi_image_free(data);

    r /= pixels;
    g /= pixels;
    b /= pixels;

    result.crystalDensity = static_cast<int>(b * 100 / 255);
    result.glowDensity    = static_cast<int>((r + g) * 50 / 255);
    result.fogDensity     = static_cast<int>((255 - (r + g + b) / 3) * 100 / 255);

    if (b > r && b > g)
        result.theme = "CRYSTAL";
    else if (r > 170 && g > 170)
        result.theme = "GLOW";
    else if (r < 80 && g < 80 && b < 80)
        result.theme = "DARK";
    else
        result.theme = "KUZURETA";

    return result;
}
