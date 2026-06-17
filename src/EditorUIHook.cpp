#include "ImageDecoPopup.cpp"
#include "EditorUIHook.hpp"

#include "EditorLayerBridge.hpp"
#include "ImageAnalyzer.hpp"
#include "StyleClassifier.hpp"
#include "LayoutAnalyzer.hpp"

#include "KuzuretaGenerator.hpp"
#include "CrystalGenerator.hpp"
#include "GlowGenerator.hpp"

#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

bool MyEditorUI::init(LevelEditorLayer* editor) {
    if (!EditorUI::init(editor))
        return false;

    EditorLayerBridge::editor = editor;

    auto sprite =
        CCSprite::createWithSpriteFrameName(
            "GJ_plusBtn_001.png"
        );

    if (!sprite) {
        log::error("SPRITE NULL");
        return true;
    }

    auto menu = CCMenu::create();
    menu->setPosition({0.f, 0.f});

    auto btn = CCMenuItemSpriteExtra::create(
        sprite,
        this,
        menu_selector(MyEditorUI::onDeco)
    );

    btn->setPosition({150.f, 120.f});

    menu->addChild(btn);
    this->addChild(menu);

    log::info("BUILD FROM IMAGE READY");

    return true;
}


void MyEditorUI::onDeco(CCObject*) {
    ImageDecoPopup::open();
}

