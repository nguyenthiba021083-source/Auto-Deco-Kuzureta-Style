#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(MyEditorUI, EditorUI) {
public:
    bool init(LevelEditorLayer* editor);
};
