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

    auto sprite =
        CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");

    auto btn = CCMenuItemSpriteExtra::create(
        sprite,
        this,
        menu_selector(MyEditorUI::onDeco)
    );

    btn->setScale(1.3f);

    // Góc trên bên trái
    btn->setPosition({-180.f, 100.f});

    auto menu = CCMenu::create();
    menu->setPosition({0, 0});
    menu->addChild(btn);

    this->addChild(menu, 999);

    log::info("AUTO DECO BUTTON ADDED");

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
