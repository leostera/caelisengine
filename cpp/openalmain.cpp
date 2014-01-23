#include "../h/CaelisEngine.h"

using namespace Caelis::Audio;

OpenALMain::OpenALMain()
    {
    mDevice = NULL;
    Core::Log::getInstance()->write(2,"[OpenALMain]-> Singleton created");
    ALfloat pos[] = { 0.0, 0.0, 0.0 };
    ALfloat vel[] = { 0.0, 0.0, 0.0 };
    ALfloat ori[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };
    mListener = new Basics::CSoundListener(pos,vel,ori,1.0);
    };

OpenALMain::~OpenALMain()
    {
    Core::Log::getInstance()->write(2,"[OpenALMain]-> Singleton destroyed");
    delete mListener;
    };

bool OpenALMain::init()
    {
    if(alutInit(NULL,NULL)==false)
        {
        Core::Log::getInstance()->write(2,"[OpenALMain]-> error initializating OpenAL. Couldn't create device.");
        return false;
        }
    Core::Log::getInstance()->write(2,"[OpenALMain]-> Initiliazation Completed Succesfully. ");
    return true;
    }

void OpenALMain::kill()
    {
    alutExit();
    }

void OpenALMain::changeDevice(ALCubyte * device)
    {
   /* alcCloseDevice(mDevice);
    mDevice = NULL;
    mDevice = alcOpenDevice(device);*/
    }

ALCcontext * OpenALMain::createContext(int* attributes)
    {
    return alcCreateContext(mDevice, attributes);
    }

void OpenALMain::suspendContext(ALCcontext * context)
    {
    alcSuspendContext(context);
    }

void OpenALMain::activateContext(ALCcontext * context)
    {
    alcMakeContextCurrent(context);
    }

void OpenALMain::killContext(ALCcontext * context)
    {
    alcDestroyContext(context);
    }

ALCcontext* OpenALMain::getActiveContext()
    {
    return alcGetCurrentContext();
    }

ALCenum OpenALMain::getError()
    {
    return alcGetError(NULL);
    }

void OpenALMain::enable(ALenum capability)
    {
    alEnable(capability);
    }

void OpenALMain::disable(ALenum capability)
    {
    alDisable(capability);
    }
