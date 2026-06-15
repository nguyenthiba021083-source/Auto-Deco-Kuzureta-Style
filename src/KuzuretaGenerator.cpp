#include "KuzuretaGenerator.hpp"

void KuzuretaGenerator::generate() {
    for (int i = 0; i < 50; i++) {
        createGlow(1000.f + i * 30.f, 200.f);
    }

    for (int i = 0; i < 20; i++) {
        createCrystal(1200.f + i * 80.f, 250.f);
    }

    for (int i = 0; i < 10; i++) {
        createChain(1500.f + i * 150.f, 300.f);
    }
}
