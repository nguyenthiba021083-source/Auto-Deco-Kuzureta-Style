#include "ImageDecoPopup.hpp"
#include "ImageAnalyzer.hpp"

#include <Geode/Geode.hpp>
#include <Geode/ui/TextInput.hpp>

using namespace geode::prelude;

class BuildPopup : public Popup<> {
protected:
    TextInput* m_input;

    bool setup() override {
        setTitle("Build From Image");

        m_input = TextInput::create(
            240.f,
            "Image Path"
        );

        m_input->setPosition({
            m_size.width / 2,
            m_size.height / 2
        });

        addChild(m_input);

        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Build"),
            this,
            menu_selector(BuildPopup::onBuild)
        );

        m_buttonMenu->addChild(btn);
        btn->setPosition({0.f, -40.f});

        return true;
    }

    void onBuild(CCObject*) {
        std::string path = m_input->getString();

        auto result =
            ImageAnalyzer::analyze(path);

        FLAlertLayer::create(
            "Image Result",
            ("Theme: " + result.theme).c_str(),
            "OK"
        )->show();
    }

public:
    static BuildPopup* create() {
        auto ret = new BuildPopup();

        if (
            ret &&
            ret->initAnchored(
                320.f,
                220.f
            )
        ) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};

void ImageDecoPopup::open() {
    BuildPopup::create()->show();
}
