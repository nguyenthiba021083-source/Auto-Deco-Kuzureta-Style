#pragma once

struct LayoutStats {
    int totalObjects = 0;

    int cubeCount = 0;
    int shipCount = 0;
    int ballCount = 0;
    int ufoCount = 0;
    int waveCount = 0;

    float levelLength = 0.f;
};

class LayoutAnalyzer {
public:
    static LayoutStats analyze();
};
