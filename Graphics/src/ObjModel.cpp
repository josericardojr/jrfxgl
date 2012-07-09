#include "../inc/ObjModel.h"

namespace JRFXGL
{
	namespace Graphics
	{
		namespace ModelTypes
		{

			ObjModel::~ObjModel()
			{
					delete mVertexArray;
					delete mNormalArray;
					delete mTexCoordArray;
					delete mTriangleArray;
			}

			void ObjModel::render()
			{
				mMaterial -> apply();

				if (mUseVBO)
				{
				}
				else
				{
					glBegin(GL_TRIANGLES);
					{
						for (int i = 0; i < mNumTriangle; i++)
						{
							glNormal3fv(mNormalArray[mTriangleArray[i].normal[0] - 1].getArray()); glVertex3fv(mVertexArray[mTriangleArray[i].vertex[0] - 1].getArray());
							glNormal3fv(mNormalArray[mTriangleArray[i].normal[1] - 1].getArray()); glVertex3fv(mVertexArray[mTriangleArray[i].vertex[1] - 1].getArray());
							glNormal3fv(mNormalArray[mTriangleArray[i].normal[2] - 1].getArray()); glVertex3fv(mVertexArray[mTriangleArray[i].vertex[2] - 1].getArray());
						}
					}
					glEnd();
				}
			}
			
			void ObjModel::loadModel(std::string filename)
			{
				using namespace std;

				std::ifstream file;
				file.open(filename.c_str());

				if (!file.is_open())
					Throw2("ObjModel::loadModel", "Error opening file!");

				std::string buffer;

				while (!file.eof())
				{
					getline(file, buffer);

					if(buffer.substr(0,2) == "vn")
						mNumNormal++;
					else if(buffer.substr(0,2) == "vt")
						mNumTexCoord++;
					else if(buffer.substr(0,1) == "v")
						mNumVertex++;
					else if(buffer.substr(0,1) == "f")
						mNumTriangle++;
				}

				// Criar modelo
				mVertexArray   = (Vertex*) malloc(sizeof(Vertex)*mNumVertex);
				mNormalArray   = (Normal*) malloc(sizeof(Normal)*mNumNormal);
				mTexCoordArray = (TexCoord*) malloc(sizeof(TexCoord)*mNumTexCoord);
				mTriangleArray = (Triangle*) malloc(sizeof(Triangle)*mNumTriangle);

				file.close();

				file.open(filename.c_str());
				file.clear();

				//hear are the counters...
				int nC, vC, tC, fC;
				nC = vC = tC = fC = 0;

				while (!file.eof())
				{
					getline(file, buffer);
					istringstream line(buffer);
					string temp;
					string f1, f2, f3;

					if(buffer.substr(0,2) == "vn")
					{
						line >> temp >> f1 >> f2 >> f3;
						mNormalArray[nC].x = atof(f1.c_str());
						mNormalArray[nC].y = atof(f2.c_str());
						mNormalArray[nC].z = atof(f3.c_str());
						nC++;
					}					
					else if(buffer.substr(0,2) == "vt")
					{
						line >> temp >> f1 >> f2;
						mTexCoordArray[tC].u = atof(f1.c_str());
						mTexCoordArray[tC].v = atof(f2.c_str());
						tC++;
					}
					else if(buffer.substr(0,1) == "v")
					{
						line >> temp >> f1 >> f2 >> f3;
						mVertexArray[vC].x = atof(f1.c_str());
						mVertexArray[vC].y = atof(f2.c_str());
						mVertexArray[vC].z = atof(f3.c_str());
						vC++;
					}				
					else if(buffer.substr(0,1) == "f")
					{

						line >> temp >> f1 >> f2 >> f3;						

						// Verificar se temos coordenada de textura
						if (mNumTexCoord == 0)
							sscanf(buffer.c_str(), "f %d//%d %d//%d %d//%d",
								&mTriangleArray[fC].vertex[0], &mTriangleArray[fC].normal[0],
								&mTriangleArray[fC].vertex[1], &mTriangleArray[fC].normal[1],
								&mTriangleArray[fC].vertex[2], &mTriangleArray[fC].normal[2]);
						else
							sscanf(buffer.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d",
								&mTriangleArray[fC].vertex[0], &mTriangleArray[fC].texCoord[0], &mTriangleArray[fC].normal[0],
								&mTriangleArray[fC].vertex[1], &mTriangleArray[fC].texCoord[1], &mTriangleArray[fC].normal[1],
								&mTriangleArray[fC].vertex[2], &mTriangleArray[fC].texCoord[2], &mTriangleArray[fC].normal[2] );

						fC++;
					}
				}

				file.close();

			}
		}

	}
}
