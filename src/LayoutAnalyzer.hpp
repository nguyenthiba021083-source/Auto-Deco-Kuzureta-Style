#pragma once

struct LayoutStats {
    int totalObjects = 0;

    int spikeCount = 0;
    int blockCount = 0;
    int decoCount = 0;
    int portalCount = 0;
    int triggerCount = 0;
    int orbCount = 0;
    int padCount = 0;

    float levelLength = 0.f;

    // Kuzureta generators
    float startX = 0.f;
    float endX = 10000.f;
    float avgY = 250.f;
};

class LayoutAnalyzer {
public:
    static LayoutStats analyze();
};
