#include "../h/CaelisEngine.h"

using namespace Caelis;

System::System()
    {
    mSceneManager = Scene::SceneManager::getInstance();
    mVideoManager = Video::VideoManager::getInstance();
    mResourceManager = Resources::ResourceManager::getInstance();

    mIsRunning = true;
    mFirstTime = true;
    mCaptionRequired = false;

    Core::Log::getInstance()->write(2,"CSystem Singleton Created.");
    }

System::~System()
    {
    Core::Log::getInstance()->write(2,"CSystem Singleton Destroyed.");

    mSceneManager->erase();
    mVideoManager->erase();
    mResourceManager->erase();

    Core::Log::getInstance()->erase();
    }

void System::run()
    {

    }

void System::needCaption(bool need)
    {
    mCaptionRequired = need;
    }

void System::needFlip(bool need)
    {
    mFlipRequired = need;
    }

void System::needFpsCounting(bool need)
    {
    mFpsCountingRequired = need;
    }
