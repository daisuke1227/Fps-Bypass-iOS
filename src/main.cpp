#include <Geode/Geode.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class $modify(PauseWithImageButton, PauseLayer) {
public:
    void customSetup() override;
    void onSettingsButton(cocos2d::CCObject*);
};

void PauseWithImageButton::customSetup() {
    PauseLayer::customSetup();
    std::string resourcePath = Mod::get()->getResourcesPath() + "button.png";
    auto sprite = cocos2d::CCSprite::create(resourcePath.c_str());
    if (!sprite) {
        log::error("Failed to load '%s'", resourcePath.c_str());
        return;
    }
    auto button = CCMenuItemSpriteExtra::create(
        sprite,
        sprite,
        this,
        menu_selector(PauseWithImageButton::onSettingsButton)
    );
    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    button->setPosition({ winSize.width - 40.f, winSize.height / 2 });
    auto menu = cocos2d::CCMenu::create();
    menu->addChild(button);
    menu->setPosition({0, 0});
    this->addChild(menu);
}

void PauseWithImageButton::onSettingsButton(cocos2d::CCObject*) {
    geode::openSettingsPopup(Mod::get(), true);
}
