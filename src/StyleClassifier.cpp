#include "StyleClassifier.hpp"

std::string StyleClassifier::classify(
    ImageAnalysisResult const& result
) {
    if (result.theme == "CRYSTAL")
        return "CRYSTAL";

    if (result.theme == "GLOW")
        return "GLOW";

    if (result.theme == "DARK")
        return "DARK";

    return "KUZURETA";
}
