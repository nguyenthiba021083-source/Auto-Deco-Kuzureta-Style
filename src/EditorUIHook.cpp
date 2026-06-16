#include "EditorUIHook.hpp"
#include "KuzuretaGenerator.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

bool MyEditorUI::init(LevelEditorLayer* editor) {
    if (!EditorUI::init(editor))
        return false;

    EditorLayerBridge::editor = editor;

    auto sprite = CCSprite::createWithSpriteFrameName(
        "GJ_plusBtn_001.png"
    );

    auto btn = CCMenuItemSpriteExtra::create(
        sprite,
        this,
        menu_selector(MyEditorUI::onDeco)
    );

    btn->setScale(2.0f);

    auto winSize =
        CCDirector::sharedDirector()->getWinSize();

    btn->setPosition({
        winSize.width / 2.f,
        winSize.height / 2.f
    });

    auto menu = CCMenu::create();
    menu->setPosition({0, 0});
    menu->addChild(btn);

    this->addChild(menu, 9999);

    log::info("AUTO DECO BUTTON CREATED");

    return true;
}

void MyEditorUI::onDeco(CCObject*) {
    FLAlertLayer::create(
        "Auto Deco",
        "Button Works!",
        "OK"
    )->show();

    KuzuretaGenerator::generate();
}
