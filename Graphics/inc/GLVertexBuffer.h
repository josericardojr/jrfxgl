/*
 * GLVertexBuffer.h
 *
 *  Created on: 22/07/2011
 *      Author: josericardo
 */

#include "../../Util/inc/Error.h"
#include "GLBuffer.h"

#ifndef GLVERTEXBUFFER_H_
#define GLVERTEXBUFFER_H_

namespace JRFXGL
{
	namespace Graphics
	{
		class GLVertexBuffer : public GLBuffer
		{
		public:
			void bindBuffer();

			void unbindBuffer();

			void setData(GLsizei size, const void* data, GLenum usage);
		};
	}
}

#endif /* GLVERTEXBUFFER_H_ */
