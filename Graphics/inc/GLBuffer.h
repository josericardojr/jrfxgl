/*
 * GLBuffer.h
 *
 *  Created on: 22/07/2011
 *      Author: josericardo
 */

#ifndef GLBUFFER_H_
#define GLBUFFER_H_

#include <GL/glew.h>

namespace JRFXGL
{
	namespace Graphics
	{
		class GLBuffer
		{
		public:
			GLBuffer();

			void genBuffer();

			virtual void bindBuffer() = 0;

			virtual void unbindBuffer() = 0;

			virtual void setData(GLsizei size, const void* data, GLenum usage) = 0;

			void deleteBuffer();

			GLuint id();

		protected:
			bool         initialized;
			bool         binded;
			GLuint       oglid;
		};
	}
}

#endif /* GLBUFFER_H_ */
