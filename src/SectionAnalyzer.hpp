#pragma once

enum class SectionType {
    Intro,
    BuildUp,
    Drop,
    Finale
};

class SectionAnalyzer {
public:
    static SectionType getSection(float x, float levelLength);
};
