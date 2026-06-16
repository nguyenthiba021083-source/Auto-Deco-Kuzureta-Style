#pragma once
#include <string>

struct ImageAnalysisResult {
    int crystalDensity;
    int glowDensity;
    int fogDensity;
    std::string theme;
};

class ImageAnalyzer {
public:
    static ImageAnalysisResult analyze(std::string const& path);
};
