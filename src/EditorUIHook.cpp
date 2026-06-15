#include "EditorUIHook.hpp"

bool MyEditorUI::init(LevelEditorLayer* editor) {
    if (!EditorUI::init(editor)) {
        return false;
    }

    log::info("Auto-Deco-Kuzureta-Style: EditorUI loaded");

    return true;
}
