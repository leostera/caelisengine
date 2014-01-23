#include "../CaelisEngine.h"

namespace Caelis
    {
    namespace Core
        {
        namespace Exception
            {
            class IBase
                {
                public:
                Base() {}
                virtual ~Base() {}
                virtual const char* what()=0;
                };

            class SDL : public IBase
                {
                public:
                SDL() {}
                ~SDL() {}
                virtual const char* what() {}
                };

            class SDL_Init : public SDL {};
                class SDL_WasInited : public SDL_Init { };
                class SDL_SubsystemWasInited : public SDL_Init { };
            class SDL_DeInit : public SDL {};
                class SDL_WasNotInited : public SDL_Init { };
                class SDL_SubsystemWasNotInited : public SDL_Init { };

            class SDL_Video : public SDL {};
                class SDL_NullSurface : public SDL_Video {};
                class SDL_BadSurface : public SDL_Video {};
                class SDL_NullRect : public SDL_Video {};
                class SDL_BadRect : public SDL_Video {};
                class SDL_BadColor : public SDL_Video {};
                class SDL_BadPixel : public SDL_Video {};
                class SDL_NullCaption : public SDL_Video {};
                class SDL_OpenGL_BadAttribute : public SDL_Video {};
                class SDL_Fliped : public SDL_Video {};

            class SDL_WindowHandling : public SDL {};
                class SDL_Iconified : public SDL_WindowHandling {};
                class SDL_Fullscreened : public SDL_WindowHandling {};

            class SDL_Config : public SDL_Init {};
                class SDL_BadConfig : public SDL_Config {};
                class SDL_NoConfig : public SDL_Config {};

            class SDL_Multithreading : public SDL {};
                class SDL_Mutexs : public SDL_Multithreading {};
                    class SDL_BadMutex : public SDL_Mutexs {};
                    class SDL_NoMutex : public SDL_Mutexs {};
                    class SDL_LockedMutex : public SDL_Mutexs {};
                    class SDL_UnlockedMutex : public SDL_Mutexs {};
                class SDL_BadThreadData: public SDL_Multithreading {};
                class SDL_BadThreadName : public SDL_Multithreading {};
                class SDL_BadThread : public SDL_Multithreading {};
                class SDL_NoThreadData : public SDL_Multithreading {};
                class SDL_NoThreadName : public SDL_Multithreading {};
                class SDL_NoThread : public SDL_Multithreading {};

            class SDL_Timing : public SDL {};

            class SDL_Input : public SDL {};
                class SDL_Keyboard : public SDL_Input {};
                    class SDL_BadKeyFilter : public SDL_Keyboard {};
                    class SDL_BadKey : public SDL_Keyboard {};
                    class SDL_NoKey : public SDL_Keyboard {};
                    class SDL_BadKeyMod : public SDL_Keyboard {};
                    class SDL_BadEvent : public SDL_Input {};
                    class SDL_NoEvent : public SDL_Input {};
                class SDL_Mouse : public SDL_Input {};
                    class SDL_BadPos : public SDL_Mouse {};
                class SDL_Joystick : public SDL_Input {};
                    /*
                    Joystick exceptions
                    */
                class SDL_EventFiltering : public SDL_Input {};
                    class SDL_BadEventFilter : public SDL_EventFiltering {};
                    class SDL_NoEventFilter : public SDL_EventFiltering {};


            class OpenGL : public IBase
                {
                public:
                OpenGL() {};
                ~OpenGL() {};
                virtual const char* what() {};
                };

            class OpenGL_Init : public OpenGL {};
            class OpenGL_DeInit : public OpenGL {};

            class OpenGL_Mesh : public OpenGL {};
                class OpenGL_LoadMesh : public OpenGL_Mesh {};
                    class OpenGL_GoodMeshData : public OpenGL_LoadMesh {};
                    class OpenGL_BadMeshData : public OpenGL_LoadMesh {};
                class OpenGL_FreeMesh : public OpenGL_Mesh {};
                class OpenGL_SaveMesh : public OpenGL_Mesh {};
                    class OpenGL_NoMeshData : public OpenGL_FreeMesh, OpenGL_SaveMesh {};


            class OpenGL_Render : public OpenGL {};
                class OpenGL_NoMeshes : public OpenGL_Render {};
                class OpenGL_BadRenderData : public OpenGL_Render {};


            class OpenAL : public IBase                {
                public:
                OpenAL() {};
                ~OpenAL() {};
                virtual const char* what() {};
                };

            class OpenAL_Init : public OpenAL {};
                class OpenAL_AlreadyOpened : public OpenAL_Init {};
            class OpenAL_DeInit : public OpenAL {};
                class OpenAL_NotOpened : public OpenAL_DeInit{};

            class OpenAL_Context : public OpenAL {};
                class OpenAL_BadContext : public OpenAL_Context {};
                class OpenAL_NoContext : public OpenAL_Context {};


            class OpenAL_BadAttribute : public OpenAL {};

            class OpenAL_Device : public OpenAL {};
                class OpenAL_BadDevice : public OpenAL_Device {};

            class OpenAL_Sound : public OpenAL {};
                class OpenAL_NoSound: public OpenAL_Sound {};
                class OpenAL_BadSound : public OpenAL_Sound {};
            };
        };
    };
