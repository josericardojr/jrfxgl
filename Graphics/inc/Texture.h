/*
 * Texture.h
 *
 *  Created on: 22/08/2011
 *      Author: josericardo
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <boost/shared_ptr.hpp>
#include <GL/glew.h>

namespace JRFXGL {
	namespace Graphics {

		class Texture2D {
		private:
			GLuint id;

		public:
			Texture2D(char* filename);
			~Texture2D();

			void bind();
			void unbind();

			GLuint getID();
		};

		typedef boost::shared_ptr<Texture2D> Texture2DPtr;
	}
}


#endif /* TEXTURE_H_ */
