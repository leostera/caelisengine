#include "../../CaelisEngine.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Basics
            {
            #ifndef _CAELISENGINE_VERTEX_
            #define _CAELISENGINE_VERTEX_
                template <class vType>
                class CAELISENGINE_EXPORT Vertex
                    {
                    public:
                        Vertex()
                            {
                            set();
                            }
                        Vertex(Vertex<vType> *cv)
                            {
                            set(cv);
                            }
                        Vertex(vType x, vType y, vType z=1, vType w=1)
                            {
                            set(x,y,z,w);
                            }
                        ~Vertex()
                            {
                            free();
                            }

                        void set(vType x=0, vType y=0, vType z = 1, vType w = 1)
                            {
                            data[0] = x;
                            data[1] = y;
                            data[2] = z;
                            data[3] = w;
                            mBuilt = true;
                            }
                        void set(Vertex<vType> *cv)
                            {
                            for(int i=0; i<4; i++)
                                data[i] = cv[i];
                            mBuilt = true;
                            return true;
                            }

                        void free()
                            {
                            for(int i=0; i<4; i++)
                                data[i] = 0;
                            mBuilt = false;
                            }

                        vType x() {return data[0];}
                        vType y() {return data[1];}
                        vType z() {return data[2];}
                        vType w() {return data[3];}

                        vType getCoord() const { return data; }

                        void x(vType nr) {data[0] = nr;}
                        void y(vType nr) {data[1] = nr;}
                        void z(vType nr) {data[2] = nr;}
                        void w(vType nr) {data[3] = nr;}

                        void inc_x(vType nr)	{data[0] += nr;}
                        void inc_y(vType nr)	{data[1] += nr;}
                        void inc_z(vType nr)	{data[2] += nr;}
                        void inc_w(vType nr)	{data[3] += nr;}

                        void dec_x(vType nr)	{data[0] -= nr;}
                        void dec_y(vType nr)	{data[1] -= nr;}
                        void dec_z(vType nr)	{data[2] -= nr;}
                        void dec_w(vType nr)	{data[3] -= nr;}

                        bool getStatus() const { return mBuilt; }

                        vType getLength() const
                            {
                            return sqrt(data[0]*data[0] + data[1]*data[1] + data[2]*data[2] + data[3]*data[3]);
                            }

                        /* Operador = Utilizado Para Copiar El Contenido De Otro Vector De Esta Misma Clase */
                        Vertex<vType>* operator = (const Vertex<vType> *cv)
                            {
                                if(cv != this)
                                    {
                                    for(int i=0; i<4; i++)
                                        this[i] = cv[i];
                                    }
                                return *this;
                                }

                            /* Operador + Utilizado Para Sumar El Contenido De 2 Vectores*/
                        Vertex<vType>* operator + (const Vertex<vType> *cv)
                            {
                                Vertex<vType> *tmp = new Vertex<vType>();

                                tmp->set(this[0] + cv[0],
                                        this[1] + cv[1],
                                         this[2] + cv[2],
                                        this[3] + cv[3]);
                                return tmp;
                                }

                        /* Operador - Utilizado Par Restar El Contenido De 2 Vectores */
                        Vertex<vType>* operator - (const Vertex<vType> *cv)
                            {
                                Vertex<vType> *tmp = new Vertex<vType>(this[0] - cv[0],
                                                                        this[1] - cv[1],
                                                                         this[2] - cv[2],
                                                                        this[3] - cv[3]);
                                return tmp;
                                }

                        /* Operador += Utilizado Para Añadir El Contenido De 1 Vector A Otro */
                        Vertex<vType>* operator += (const Vertex<vType> *cv)
                            {
                                for(int i=0; i<4; i++)
                                    this[i] += cv[i];

                                return *this;
                                }

                        /* Operador -= Utilizado Para Quitar Contenido De 1 Vector A Otro */
                        Vertex<vType>* operator -= (const Vertex<vType> *cv)
                            {
                                for(int i=0; i<4; i++)
                                    this[i] -= cv[i];

                                return *this;
                                }

                            /* Operador *= Utilizado Para Multiplicar Un Vector */
                        Vertex<vType>* operator *= (const vType nr)
                            {
                            if(nr == 0)
                                {
                                free();
                                }
                            else
                                {
                                for(int i=0; i<4; i++)
                                    this[i] *= nr;
                                }
                            return *this;
                            }

                        /* Operador [] Utilizado Para Manejar El Vector Como Un Array */
                        vType operator [] (int id)
                            {
                            return data[id];
                            }

                        /* Operador == Utilizado Para Comparar Igualdad 2 Vectores */
                        bool operator == (const Vertex<vType> *cv)
                           {
                           if(cv != this)
                               {
                               for(int i=0; i<4; i++)
                                    if(cv[i] != this[i]) return false;
                               }
                           return true;
                           }

                        /* Operador == Utilizado Para Comparar Diferencia 2 Vectores */
                        bool operator != (const Vertex<vType> *cv)
                           {
                           if(*this==cv) return false;
                           return true;
                           }

                    private:

                        bool mBuilt;
                        vType data[4];
                    };
            #endif
            }
        }
    }

