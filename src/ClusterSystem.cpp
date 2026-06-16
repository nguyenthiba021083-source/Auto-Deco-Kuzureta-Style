#include "ClusterSystem.hpp"
#include "LayoutAnalyzer.hpp"

static ClusterData gCluster;

ClusterData* getCluster() {
    return &gCluster;
}

void generateCluster(const LayoutStats& stats) {
    gCluster.centerX = (stats.startX + stats.endX) * 0.5f;
    gCluster.centerY = stats.avgY;
    gCluster.density = 30;
}
