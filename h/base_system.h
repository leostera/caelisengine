#ifndef _CAELISENGINE_SYSTEM_
#define _CAELISENGINE_SYSTEM_

#include "CaelisEngine.h"

using namespace Caelis;

class CAELISENGINE_EXPORT System : public Core::Patterns::ISingleton<System>
    {
    private:
        Scene::SceneManager* mSceneManager;
        Video::VideoManager* mVideoManager;
        Resources::ResourceManager* mResourceManager;

        bool mCaptionRequired;
        bool mFlipRequired;
        bool mFpsCountingRequired;
        bool mIsRunning;
        bool mFirstTime;

    public:
        System();
        ~System();

        void needCaption(bool need=true);
        void needFlip(bool need=true);
        void needFpsCounting(bool need=true);

        void run();
    };
#endif
