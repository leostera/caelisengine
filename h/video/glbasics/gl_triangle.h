#include "../../CaelisEngine.h"

#include "gl_vector.h"

namespace Caelis
    {
    namespace Video
        {
        namespace Basics
            {
            #ifndef _CAELISENGINE_TRIANGLE_
            #define _CAELISENGINE_TRIANGLE_
                template <class vType>
                class CAELISENGINE_EXPORT Triangle
                    {
                    public:
                        Triangle(Vertex<vType> *vert[3]);
                        Triangle(Triangle<vType> *tri);
                        Triangle(vType x1, vType y1, vType z1, vType x2, vType y2, vType z2, vType x3, vType y3, vType z3);
                        Triangle(vType x1, vType y1, vType z1, vType w1, vType x2, vType y2, vType z2, vType w2, vType x3, vType y3, vType z3, vType w3);
                        ~Triangle();

                        Vertex<vType> *getVertex(int id) { return mVertex[id]; }
                        void setVertex(int id, Vertex<vType> *vert);
                        void freeVertex(int id = -1);

                        void copy(Triangle *tri);
                        void copy(Triangle *tri, int amount);

                        void free();
                        bool getStatus() const { return mBuilt; }

                        /* Operador = Utilizado Para Copiar El Contenido De Otro Triangulo De Esta Misma Clase */
                        Triangle<vType>* operator = (const Triangle<vType> *cv)
                            {
                            if(cv != this)
                                {
                                for(int i=0; i<3; i++)
                                    for(int j=0; j<6; j++)
                                        this[i][j] = cv[i][j];
                                }
                            return *this;
                            }

                        /* Operador + Utilizado Para Sumar El Contenido De 2 Triangulo*/
                        Triangle<vType>* operator + (const Triangle<vType> *cv)
                            {
                            Triangle<vType> *tmp;
                            vType x[3], y[3], z[3], w[3], u, v;
                            x[0] = cv[0][0];
                            x[1] = cv[1][0];
                            x[2] = cv[2][0];
                            y[0] = cv[0][1];
                            y[1] = cv[1][1];
                            y[2] = cv[2][1];
                            z[0] = cv[0][2];
                            z[1] = cv[1][2];
                            z[2] = cv[2][2];
                            w[0] = cv[0][3];
                            w[1] = cv[1][3];
                            w[2] = cv[2][3];

                            vType x2[3], y2[3], z2[3], w2[3], u2, v2;
                            x2[0] = this[0][0];
                            x2[1] = this[1][0];
                            x2[2] = this[2][0];
                            y2[0] = this[0][1];
                            y2[1] = this[1][1];
                            y2[2] = this[2][1];
                            z2[0] = this[0][2];
                            z2[1] = this[1][2];
                            z2[2] = this[2][2];
                            w2[0] = this[0][3];
                            w2[1] = this[1][3];
                            w2[2] = this[2][3];

                            tmp = new Triangle<vType>(x[0] + x2[0],
                                                        y[0] + y2[0],
                                                        z[0] + z2[0],
                                                        w[0] + w2[0],
                                                        x[1] + x2[1],
                                                        y[1] + y2[1],
                                                        z[1] + z2[1],
                                                        w[1] + w2[1],
                                                        x[2] + x2[2],
                                                        y[2] + y2[2],
                                                        z[2] + z2[2],
                                                        w[2] + w2[2]);

                            return tmp;
                            }

                        /* Operador - Utilizado Par Restar El Contenido De 2 Triangulo */
                        Triangle<vType>* operator - (const Triangle<vType> *cv)
                            {
                            Triangle<vType> *tmp;
                            vType x[3], y[3], z[3], w[3], u, v;
                            x[0] = cv[0][0];
                            x[1] = cv[1][0];
                            x[2] = cv[2][0];
                            y[0] = cv[0][1];
                            y[1] = cv[1][1];
                            y[2] = cv[2][1];
                            z[0] = cv[0][2];
                            z[1] = cv[1][2];
                            z[2] = cv[2][2];
                            w[0] = cv[0][3];
                            w[1] = cv[1][3];
                            w[2] = cv[2][3];

                            vType x2[3], y2[3], z2[3], w2[3], u2, v2;
                            x2[0] = this[0][0];
                            x2[1] = this[1][0];
                            x2[2] = this[2][0];
                            y2[0] = this[0][1];
                            y2[1] = this[1][1];
                            y2[2] = this[2][1];
                            z2[0] = this[0][2];
                            z2[1] = this[1][2];
                            z2[2] = this[2][2];
                            w2[0] = this[0][3];
                            w2[1] = this[1][3];
                            w2[2] = this[2][3];

                            tmp = new Triangle<vType>(x[0] - x2[0],
                                                        y[0] - y2[0],
                                                        z[0] - z2[0],
                                                        w[0] - w2[0],
                                                        x[1] - x2[1],
                                                        y[1] - y2[1],
                                                        z[1] - z2[1],
                                                        w[1] - w2[1],
                                                        x[2] - x2[2],
                                                        y[2] - y2[2],
                                                        z[2] - z2[2],
                                                        w[2] - w2[2]);

                            return tmp;
                            }

                        /* Operador += Utilizado Para Añadir El Contenido De 1 Triangulo A Otro */
                        Triangle<vType>* operator += (const Triangle<vType> *cv)
                            {
                            for(int i=0; i<3; i++)
                                for(int j=0; j<6; j++)
                                    this[i][j] += cv[i][j];

                            return *this;
                            }

                        /* Operador -= Utilizado Para Quitar Contenido De 1 Triangulo A Otro */
                        Triangle<vType>* operator -= (const Triangle<vType> *cv)
                            {
                            for(int i=0; i<3; i++)
                                for(int j=0; j<6; j++)
                                    this[i][j] -= cv[i][j];

                            return *this;
                            }

                        /* Operador *= Utilizado Para Multiplicar Un Triangulo */
                        Triangle<vType>* operator *= (const vType nr)
                            {
                            if(nr == 0)
                                {
                                free();
                                }
                            else
                                {
                                for(int i=0; i<3; i++)
                                    for(int j=0; j<6; j++)
                                        this[i][j] *= nr;
                                this[4] *= nr;
                                this[5] *= nr;
                                }
                            return *this;
                            }

                        /* Operador [] Utilizado Para Manejar El Triangulo Como Un Array */
                        vType operator [] (int id)
                            {
                            return mVertex[id];
                            }

                        /* Operador == Utilizado Para Comparar Igualdad 2 Triangulos */
                        bool operator == (const Triangle<vType> *cv)
                           {
                           if(cv != this)
                               {
                               for(int i=0; i<3; i++)
                                    {
                                    for(int j=0; j<6; j++)
                                        if(this[i][j] != cv[i][j]) return false;
                                    }
                               }
                           return true;
                           }

                        /* Operador != Utilizado Para Comparar Diferencia 2 Triangulos */
                        bool operator != (const Triangle<vType> *cv)
                           {
                           if(*this==cv) return false;
                           return true;
                           }

                    private:
                        Vertex<vType> *mVertex[3];
                        bool mBuilt;
                    };

                template <class vType>
                Triangle<vType>::Triangle(Vertex<vType> *vert[3])
                    {
                    for(int i=0; i<3; i++)
                        {
                        mVertex[i] = new Vertex<vType>(vert[i]);
                        }
                    mBuilt = true;
                    }

                template <class vType>
                Triangle<vType>::Triangle(Triangle<vType> *tri)
                    {
                    for(int i=0; i<3; i++)
                        mVertex[i] = new Vertex<vType>();
                    this = tri;
                    mBuilt = true;
                    }

                template <class vType>
                Triangle<vType>::Triangle(vType x1, vType y1, vType z1, vType x2, vType y2, vType z2, vType x3, vType y3, vType z3)
                    {
                    for(int i=0; i<3; i++)
                        mVertex[i] = new Vertex<vType>();
                    this[0][0] = x1;
                    this[0][1] = y1;
                    this[0][2] = z1;
                    this[1][0] = x2;
                    this[1][1] = y2;
                    this[1][2] = z2;
                    this[2][0] = x3;
                    this[2][1] = y3;
                    this[2][2] = z3;
                    mBuilt = true;
                    }

                template <class vType>
                Triangle<vType>::Triangle(vType x1, vType y1, vType z1, vType w1, vType x2, vType y2, vType z2, vType w2, vType x3, vType y3, vType z3, vType w3)
                    {
                    for(int i=0; i<3; i++)
                        mVertex[i] = new Vertex<vType>();
                    this[0][0] = x1;
                    this[0][1] = y1;
                    this[0][2] = z1;
                    this[0][3] = w1;
                    this[1][0] = x2;
                    this[1][1] = y2;
                    this[1][2] = z2;
                    this[1][3] = w2;
                    this[2][0] = x3;
                    this[2][1] = y3;
                    this[2][2] = z3;
                    this[2][3] = w3;
                    mBuilt = true;
                    }

                template <class vType>
                Triangle<vType>::~Triangle()
                    {
                    free();
                    }

                template <class vType>
                void Triangle<vType>::setVertex(int id, Vertex<vType> *vert)
                    {
                    this[id]->copy(vert);
                    }

                template <class vType>
                void Triangle<vType>::freeVertex(int id)
                    {
                    if(id == -1)
                        {
                        delete [] mVertex;
                        }
                    else
                        {
                        delete mVertex[id];
                        }
                    mBuilt = false;
                    }

                template <class vType>
                void Triangle<vType>::copy(Triangle *tri)
                    {
                    for(int i=0; i<3; i++)
                        for(int j=0; j<6; j++)
                            this[i][j] = tri[i][j];
                    mBuilt = true;
                    }

                template <class vType>
                void Triangle<vType>::copy(Triangle *tri, int amount)
                    {
                    for(int i=0; i<amount; i++)
                        for(int j=0; j<6; i++)
                            this[i][j] = tri[i][j];
                    mBuilt = true;
                    }

                template <class vType>
                void Triangle<vType>::free()
                    {
                    if(mVertex)
                        {
                        freeVertex(-1);
                        }
                    }
            #endif
            }
        }
    }
