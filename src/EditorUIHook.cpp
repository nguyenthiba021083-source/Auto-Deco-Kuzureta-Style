#include "EditorUIHook.hpp"
#include "KuzuretaGenerator.hpp"
#include "EditorLayerBridge.hpp"

bool MyEditorUI::init(LevelEditorLayer* editor) {

    if (!EditorUI::init(editor)) {
        return false;
    }

    EditorLayerBridge::editor = editor;

    auto btn = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName(
            "GJ_plusBtn_001.png"
        ),
        this,
        menu_selector(MyEditorUI::onDeco)
    );

    btn->setPosition({220.f, -90.f});

    if (auto menu = this->getChildByType<CCMenu>(0)) {
        menu->addChild(btn);
    }

    log::info("Kuzureta button created");

    return true;
}

void MyEditorUI::onDeco(CCObject*) {

    log::info("Starting Kuzureta Generator");

    KuzuretaGenerator::generate();
}
