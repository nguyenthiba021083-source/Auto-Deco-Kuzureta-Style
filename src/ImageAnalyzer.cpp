#include "ImageAnalyzer.hpp"

ImageAnalysisResult ImageAnalyzer::analyze(std::string const& path) {
    ImageAnalysisResult result;

    if (path.find("crystal") != std::string::npos) {
        result.crystalDensity = 100;
        result.glowDensity = 40;
        result.fogDensity = 20;
        result.theme = "CRYSTAL";
    }
    else if (path.find("glow") != std::string::npos) {
        result.crystalDensity = 20;
        result.glowDensity = 100;
        result.fogDensity = 40;
        result.theme = "GLOW";
    }
    else {
        result.crystalDensity = 70;
        result.glowDensity = 70;
        result.fogDensity = 70;
        result.theme = "KUZURETA";
    }

    return result;
}
