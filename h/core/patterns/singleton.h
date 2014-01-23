#ifndef _CAELISENGINE_SINGLETON_
#define _CAELISENGINE_SINGLETON_

namespace Caelis
    {
    namespace Core
        {
        namespace Patterns
            {
            template<typename T>
            class CAELISENGINE_EXPORT ISingleton
                {
                private:
                    static T* mInstance;

                public:
                    virtual ~ISingleton() { }
                    inline static void erase()
                        {
                        if( ISingleton::mInstance != 0)
                            {
                            delete mInstance;
                            }
                        }

                    inline static T* getInstance()
                        {
                        if ( ISingleton::mInstance == 0 )
                            {
                            mInstance = new T;
                            }
                        return mInstance;
                        }
                };
            template <typename T> T* ISingleton <T>::mInstance = 0;
            }
        }
    }
#endif
