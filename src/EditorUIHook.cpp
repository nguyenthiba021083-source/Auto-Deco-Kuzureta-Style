#include "EditorUIHook.hpp"
#include "KuzuretaGenerator.hpp"

bool MyEditorUI::init(LevelEditorLayer* editor) {
    if (!EditorUI::init(editor)) {
        return false;
    }

    KuzuretaGenerator::generate();

    return true;
}

void MyEditorUI::onDeco(CCObject*) {
    KuzuretaGenerator::generate();
}
