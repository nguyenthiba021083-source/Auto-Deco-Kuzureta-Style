#include "ImageDecoPopup.hpp"
#include "ImageAnalyzer.hpp"
#include "LayoutAnalyzer.hpp"
#include "StyleClassifier.hpp"

#include "CrystalGenerator.hpp"
#include "GlowGenerator.hpp"
#include "KuzuretaGenerator.hpp"

#include <Geode/Geode.hpp>
#include <Geode/ui/TextInput.hpp>

using namespace geode::prelude;

class BuildPopup : public FLAlertLayer {
public:
    TextInput* m_input;

    static BuildPopup* create() {
        auto ret = new BuildPopup();
        if (ret && ret->init(
            nullptr,
            "Build From Image",
            "",
            "Close"
        )) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

    bool init(
        FLAlertLayerProtocol*,
        char const* title,
        std::string const&,
        char const* btn
    ) {
        if (!FLAlertLayer::init(nullptr, title, btn, nullptr, 300.f))
            return false;

        m_input = TextInput::create(
            220.f,
            "Image Path"
        );

        m_input->setPosition({150.f,120.f});
        m_mainLayer->addChild(m_input);

        auto buildBtn =
            CCMenuItemSpriteExtra::create(
                ButtonSprite::create("BUILD"),
                this,
                menu_selector(BuildPopup::onBuild)
            );

        m_buttonMenu->addChild(buildBtn);
        buildBtn->setPosition({0.f,-40.f});

        return true;
    }

    void onBuild(CCObject*) {
        auto path = m_input->getString();

        auto result =
            ImageAnalyzer::analyze(path);

        auto stats =
            LayoutAnalyzer::analyze();

        if (result.theme == "CRYSTAL") {
            CrystalGenerator::generate(stats);
        }
        else if (result.theme == "GLOW") {
            GlowGenerator::generate(stats);
        }
        else {
            KuzuretaGenerator::generate();
        }

        FLAlertLayer::create(
            "Build Complete",
            result.theme.c_str(),
            "OK"
        )->show();
    }
};

void ImageDecoPopup::open() {
    BuildPopup::create()->show();
}
