
#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

class $modify(PauseWithImageButton, PauseLayer) {
    bool init(bool p0) {
        if (!PauseLayer::init(p0)) return false;

        auto sprite = CCSprite::create("button.png");
        if (!sprite) {
            log::error("Failed to load button.png");
            return true;
        }

        auto btn = CCMenuItemSpriteExtra::create(
            sprite,
            sprite,
            this,
            menu_selector(PauseWithImageButton::onSettingsButton)
        );

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        btn->setPosition({ winSize.width - 30, winSize.height / 2 }); // yes yes yes what am i doing pls what

        this->m_buttonMenu->addChild(btn);

        return true;
    }

    void onSettingsButton(CCObject*) {
        Mod::get()->openSettingsPopup();
    }
};
