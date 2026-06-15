#include "EditorUIHook.hpp"
#include "KuzuretaGenerator.hpp"

bool MyEditorUI::init(LevelEditorLayer* editor) {
    if (!EditorUI::init(editor)) {
        return false;
    }

    auto btn = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png"),
        this,
        menu_selector(MyEditorUI::onDeco)
    );

    btn->setPosition({220.f, -90.f});

    if (auto menu = this->getChildByType<CCMenu>(0)) {
        menu->addChild(btn);
    }

    return true;
}

void MyEditorUI::onDeco(CCObject*) {
    KuzuretaGenerator::generate();
}
