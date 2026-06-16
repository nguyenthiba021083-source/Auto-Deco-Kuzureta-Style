#pragma once

#include <string>
#include "ImageAnalyzer.hpp"

class StyleClassifier {
public:
    static std::string classify(
        ImageAnalysisResult const& result
    );
};
