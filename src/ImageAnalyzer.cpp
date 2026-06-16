#include "ImageAnalyzer.hpp"

ImageAnalysisResult ImageAnalyzer::analyze(std::string const& path) {
    ImageAnalysisResult result;

    result.crystalDensity = 60;
    result.glowDensity = 70;
    result.fogDensity = 50;

    if (path.find("crystal") != std::string::npos)
        result.theme = "CRYSTAL";
    else if (path.find("city") != std::string::npos)
        result.theme = "CITY";
    else
        result.theme = "KUZURETA_FANTASY";

    return result;
}
