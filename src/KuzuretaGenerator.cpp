#include "KuzuretaGenerator.hpp"

void KuzuretaGenerator::generate() {
    auto editor = LevelEditorLayer::get();

    if (!editor)
        return;

    float startX = 1000.f;
    float y = 150.f;

    for (int i = 0; i < 10; i++) {
        auto obj = editor->createObject(1, { startX + i * 30.f, y }, false);
        
        if (obj) {
            editor->addObject(obj);
        }
    }
}
