#ifndef _CAELISENGINE_H_
#define _CAELISENGINE_H_

#ifdef BUILD_DLL
    #define CAELISENGINE_EXPORT __declspec(dllexport)
#else
    #define CAELISENGINE_EXPORT
#endif

#ifndef _CAELISENGINE_DEPENDENCIES_
#define _CAELISENGINE_DEPENDENCIES_

//External APIs Header Files
    #include "../../dependencies/SDL/SDL.h"
    #include "../../dependencies/SDL/SDL_image.h"

    #include "../../dependencies/OpenGL/gl.h"
    #include "../../dependencies/OpenGL/glu.h"
    #include "../../dependencies/OpenGL/glext.h"

    #include "../../dependencies/OpenAL/al.h"
    #include "../../dependencies/OpenAL/alut.h"
    #include "../../dependencies/OpenAL/alctypes.h"
    #include "../../dependencies/OpenAL/altypes.h"
    #include "../../dependencies/OpenAL/alc.h"

//Standart C/C++ Header Files
    #include <stdlib.h>
    #include <fstream>
    #include <stdarg.h>
    #include <ctime>
    #include <string>
    #include <map>
    #include <vector>
    #include <list>
    #include <math.h>

    #ifdef _WIN32
        #include <windows.h>
        #include <wingdi.h>
        #pragma comment(lib,"Gdi32.lib")
    #endif

#endif

    #define BUILDSTAMP CaelisEngine v __TIMESTAMP__

    #include "core/patterns.h"

   // #include "core/exception.h" //Not Implemented Yet

    #include "core/time_timer.h"
    #include "core/time_alarm.h"
    #include "core/log.h"
    #include "core/multithread_main.h"
    #include "core/io.h"

    #include "scene/scenemanager.h"

    #include "video/videomanager.h"

    #include "audio/basics.h"
    #include "audio/audio.h"

    #include "resources/resourcemanager.h"

    #include "core/instance_base.h"
    #include "core/instancemanager.h"

    #include "base_system.h"

#endif
