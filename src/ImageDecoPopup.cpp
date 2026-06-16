#include <Geode/Geode.hpp>
#include "ImageAnalyzer.hpp"

using namespace geode::prelude;

class ImageDecoPopup : public Popup<> {
public:
    static ImageDecoPopup* create() {
        auto ret = new ImageDecoPopup();
        if (ret && ret->initAnchored(260.f, 180.f)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

    bool setup() override {
        this->setTitle("Build From Image");

        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Analyze"),
            this,
            menu_selector(ImageDecoPopup::onAnalyze)
        );

        m_buttonMenu->addChild(btn);
        btn->setPosition({0.f, 0.f});

        return true;
    }

    void onAnalyze(CCObject*) {
        auto result = ImageAnalyzer::analyze("kuzureta");

        FLAlertLayer::create(
            "Image Build",
            ("Theme: " + result.theme).c_str(),
            "OK"
        )->show();
    }
};
