#include "SectionAnalyzer.hpp"

SectionType SectionAnalyzer::getSection(float x, float levelLength) {
    float p = x / levelLength;

    if (p < 0.25f) return SectionType::Intro;
    if (p < 0.50f) return SectionType::BuildUp;
    if (p < 0.80f) return SectionType::Drop;

    return SectionType::Finale;
}
