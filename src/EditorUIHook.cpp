#include "EditorUIHook.hpp"
#include "KuzuretaGenerator.hpp"
#include "EditorLayerBridge.hpp"

using namespace geode::prelude;

bool MyEditorUI::init(LevelEditorLayer* editor) {
    if (!EditorUI::init(editor))
        return false;

    // Save editor reference
    EditorLayerBridge::editor = editor;

    auto sprite =
        CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");

    auto btn = CCMenuItemSpriteExtra::create(
        sprite,
        this,
        menu_selector(MyEditorUI::onDeco)
    );

    btn->setScale(1.1f);
    btn->setPosition({220.f, -90.f});

    if (auto menu = this->getChildByType<CCMenu>(0)) {
        menu->addChild(btn);
    }

    log::info("Auto Deco Kuzureta loaded");

    return true;
}

void MyEditorUI::onDeco(CCObject*) {
    FLAlertLayer::create(
        "Auto Deco",
        "Generating Kuzureta Style...",
        "OK"
    )->show();

    KuzuretaGenerator::generate();
}
