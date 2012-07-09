#ifndef __MATERIAL_H__

#define __MATERIAL_H__

/* 
 * Classe base para implementa��o de materiais
 */

namespace JRFXGL
{
	namespace Graphics
	{
		class Material
		{
		public:
			virtual ~Material(){}

			virtual void apply(){}

			virtual void disable(){}

		};
	}
}

#endif
