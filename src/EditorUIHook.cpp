#include "EditorUIHook.hpp"

bool MyEditorUI::init(LevelEditorLayer* editor) {
    if (!EditorUI::init(editor)) {
        return false;
    }

    log::info("Editor opened");

    return true;
}
