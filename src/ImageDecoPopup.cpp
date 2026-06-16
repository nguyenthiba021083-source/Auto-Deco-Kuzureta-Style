#include <Geode/Geode.hpp>
#include <Geode/ui/TextInput.hpp>

#include "ImageAnalyzer.hpp"

using namespace geode::prelude;

class ImageDecoPopup : public Popup<> {
protected:
    TextInput* m_input = nullptr;

public:
    static ImageDecoPopup* create() {
        auto ret = new ImageDecoPopup();
        if (ret && ret->initAnchored(320.f, 220.f)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

    bool setup() override {
        this->setTitle("Build From Image");

        m_input = TextInput::create(
            260.f,
            "Image Path"
        );

        m_input->setPosition({
            m_size.width / 2,
            m_size.height / 2 + 20.f
        });

        this->m_mainLayer->addChild(m_input);

        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Build"),
            this,
            menu_selector(ImageDecoPopup::onAnalyze)
        );

        m_buttonMenu->addChild(btn);
        btn->setPosition({0.f, -40.f});

        return true;
    }

    void onAnalyze(CCObject*) {
        std::string path =
            m_input->getString();

        auto result =
            ImageAnalyzer::analyze(path);

        FLAlertLayer::create(
            "Image Build",
            ("Theme: " + result.theme).c_str(),
            "OK"
        )->show();
    }
};
