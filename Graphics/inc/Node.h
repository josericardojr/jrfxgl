/*
 * Node.h
 *
 *  Created on: 13/07/2011
 *      Author: josericardo
 */

#ifndef NODE_H_
#define NODE_H_

#include <GL/glew.h>
#include "../../Math/inc/mcMath.h"
#include "Mesh.h"

namespace JRFXGL
{
	namespace Graphics
	{
		class Node
		{
		private:
			mc::math::Vec3f position;
			mc::math::Quatf orientation;
			Mesh*           mesh;

		public:
			Node();

		public:
			void              setPosition(mc::math::Vec3f& pos) {position = pos; }
			mc::math::Vec3f&  getPosition(){ return position; }
			mc::math::Quatf&  getOrientation(){ return orientation; }

			void attachEntity(Mesh* m){ mesh = m; }
			Mesh* getEntity(){ return mesh; }

			void appyTransform();
		};
	}
}

#endif /* NODE_H_ */
