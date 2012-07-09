/*
 * Node.cpp
 *
 *  Created on: 13/07/2011
 *      Author: josericardo
 */

#include "../inc/Node.h"

namespace JRFXGL
{
	namespace Graphics
	{
		Node::Node() : position(mc::math::Vec3f(0, 0, 0)),
				orientation(mc::math::Quatf(0, 0, 0, 1))
		{
		}

		void Node::appyTransform()
		{
			mc::math::Matrix4f rot; orientation.getValue(rot);
			glMultMatrixf(rot.getArray());
			glTranslatef(position.x, position.y, position.z);
		}
	}
}
