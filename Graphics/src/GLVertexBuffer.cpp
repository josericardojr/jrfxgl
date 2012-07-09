/*
 * GLVertexBuffer.cpp
 *
 *  Created on: 22/07/2011
 *      Author: josericardo
 */

#include "../inc/GLVertexBuffer.h"

namespace JRFXGL
{
	namespace Graphics
	{
		void GLVertexBuffer::bindBuffer()
		{
			ASSERT2(initialized, "Vertex buffer not initialized!");

			if (binded) return;

			glBindBuffer(GL_ARRAY_BUFFER, oglid);
			binded = true;
		}

		void GLVertexBuffer::unbindBuffer()
		{
			ASSERT2(initialized, "Vertex buffer not initialized!");

			if (binded)
				glBindBuffer(GL_ARRAY_BUFFER, 0);

			binded = false;
		}

		void GLVertexBuffer::setData(GLsizei size, const void* data, GLenum usage)
		{
			ASSERT3(initialized, binded, "Vertex buffer not initialized or binded!");

			glBufferData(GL_ARRAY_BUFFER, size, data, usage);
		}
	}
}
