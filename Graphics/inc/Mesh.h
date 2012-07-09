#ifndef __MESH_H__

#define __MESH_H__

/* 
 * Classe base para implementação de modelos
 */

/*****************************/
#include "Material.h"
#include <boost/shared_ptr.hpp>
/*****************************/

namespace JRFXGL
{
	namespace Graphics
	{
		class Mesh
		{
		public:
			virtual ~Mesh(){}

			virtual void render() = 0;

			void setMaterial(boost::shared_ptr<Material> m){
				mMaterial = m;
			}

		protected:
			boost::shared_ptr<Material>      mMaterial;
		};
	}
}

#endif
