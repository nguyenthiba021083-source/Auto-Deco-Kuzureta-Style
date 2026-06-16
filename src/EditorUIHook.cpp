#include "LayoutAnalyzer.hpp"
#include "GlowGenerator.hpp"
#include "CrystalGenerator.hpp"
#include "KuzuretaGenerator.hpp"
#include "EditorUIHook.hpp"
#include "EditorLayerBridge.hpp"
#include "ImageAnalyzer.hpp"

#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

bool MyEditorUI::init(LevelEditorLayer* editor) {
    if (!EditorUI::init(editor))
        return false;

    EditorLayerBridge::editor = editor;

    auto sprite =
        CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");

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

    log::info("AUTO DECO BUTTON CREATED");

    return true;
}

void MyEditorUI::onDeco(CCObject*) {
    auto result = ImageAnalyzer::analyze("kuzureta");

    log::info(
        "Theme={} crystal={} glow={} fog={}",
        result.theme,
        result.crystalDensity,
        result.glowDensity,
        result.fogDensity
    );

    KuzuretaGenerator::generate();

    FLAlertLayer::create(
        "Build From Image",
        result.theme.c_str(),
        "OK"
    )->show();
}
