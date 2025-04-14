#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/Popup.hpp>
#include <Geode/ui/GeodeUI.hpp>
        // Load custom image
        auto sprite = CCSprite::create("pbutton.png");
        if (!sprite) {
            log::error("Could not load pbutton.png");
            return;
        }

        // Create button from sprite
        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            sprite,
            this,
            menu_selector(PauseWithImageButton::onSettingsButton)
        );

        // Position on screen
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        button->setPosition({winSize.width - 40.f, winSize.height / 2});

        // Add to the PauseLayer's menu
        auto menu = CCMenu::create();
        menu->addChild(button);
        menu->setPosition(CCPointZero);
        this->addChild(menu);
    }

    void onSettingsButton(CCObject*) {
        // Create your mod's settings popup manually
        auto popup = geode::createQuickSettingsPopup(Mod::get());
        popup->show();
    }
};
