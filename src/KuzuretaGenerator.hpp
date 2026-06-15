#pragma once

class KuzuretaGenerator {
public:
    static void generate();

private:
    static void createGlow(float x, float y);
    static void createCrystal(float x, float y);
    static void createChain(float x, float y);
};
