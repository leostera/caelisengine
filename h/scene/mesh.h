#ifndef _CAELISENGINE_MESH_
#define _CAELISENGINE_MESH_

#include "../CaelisEngine.h"

#include "../video/glbasics.h"

namespace Caelis
    {
    namespace Scene
        {
        enum MeshType
            {
            MESH_ASCII=0
            };

         class CAELISENGINE_EXPORT CMesh : public Video::Basics::IRenderData
            {
            private:
                Video::Basics::Vertex<float>* mVertices;
                int mCantVertices;

                Video::Basics::Triangle<float>* mTriangles;
                int mCantTriangles;

                Video::Basics::UVMap<float>* mVerticesCoords;
                int mCantVerticesCoords;

                Video::Basics::UVMap<float>* mTrianglesCoords;
                int mCantTriangleCoord;

                Video::Basics::Normal<float>* mNormals;
                int mCantNormals;

                int mDisplayListID;

            public:
                CMesh();
                ~CMesh();

                void load(char* file, MeshType type);

                void buildDisplayList();
            };
        }
    }
#endif
