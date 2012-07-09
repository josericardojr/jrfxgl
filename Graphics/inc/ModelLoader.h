#ifndef __MODELLOADER_H__

#define __MODELLOADER_H__

#include "ObjModel.h"


namespace JRFXGL
{
	namespace Graphics
	{
		/* 
		 * Classe responsável pelo carregamento de modelos
		 */
		class ModelLoader
		{
		public:
			static Mesh* loadObjModel(std::string filename)
			{
				return new ModelTypes::ObjModel(filename);
			}
		};
	}
}


#endif
