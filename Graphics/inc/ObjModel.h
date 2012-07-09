#ifndef __OBJMODEL_H__

#define __OBJMODEL_H__

/*****************************/
#include "../../Math/inc/mcMath.h"
#include "../../Util/inc/Error.h"
#include "Mesh.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glew.h>
/*****************************/

namespace JRFXGL
{
	namespace Graphics
	{
		namespace ModelTypes
		{
			typedef mc::math::Vec3f Vertex;
			typedef mc::math::Vec3f Normal;

			typedef struct _TexCoord {
				float u, v;
			} TexCoord;

			typedef struct _Triangle {
				int vertex[3];
				int normal[3];
				int texCoord[3];
			} Triangle;


			class ObjModel : public JRFXGL::Graphics::Mesh
			{
			public:
				
				ObjModel(std::string filename, bool useVBO = false) : mUseVBO(useVBO),
					mNumVertex(0), mNumNormal(0), mNumTexCoord(0), mNumTriangle(0) {

						loadModel(filename);
				}			

				virtual ~ObjModel();
				
				virtual void render();

			private:
				void loadModel(std::string filename);		

				private:					
					int              mNumVertex;
					int              mNumNormal;
					int              mNumTexCoord;
					int              mNumTriangle;
					bool             mUseVBO;

					Vertex*          mVertexArray;
					Normal*          mNormalArray;
					TexCoord*        mTexCoordArray;
					Triangle*        mTriangleArray;
			};
		}
	}
}



#endif
