/*
 * GLBuffer.cpp
 *
 *  Created on: 25/07/2011
 *      Author: josericardo
 */

#include "../inc/GLBuffer.h"
namespace JRFXGL
{
	namespace Graphics
	{
		GLBuffer::GLBuffer() : initialized(false), binded(false){}

		void GLBuffer::genBuffer()
		{
			glGenBuffersARB(1, &this->oglid);
			initialized = true;
		}

		void GLBuffer::deleteBuffer()
		{
			glDeleteBuffers(1, &oglid);
			initialized = false;
		}

		GLuint GLBuffer::id()
		{
			return oglid;
		}
	}
}
