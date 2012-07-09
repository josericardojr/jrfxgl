/*
 * GLFrameBuffer.h
 *
 *  Created on: 22/08/2011
 *      Author: josericardo
 */

#ifndef GLFRAMEBUFFER_H_
#define GLFRAMEBUFFER_H_

namespace JRFXGL {
	namespace Graphics {



		class GLFrameBuffer {

			 /* Texturas suportadas pelo framebuffer
			 *
			 * Este enum foi criado para permitir uma possível implementação usando DirectX
			 */
			enum TextureTarget { TEXTURE_2D };

		public:
			/**
			 * bind this FBO as current render target
			 */
			void bind();

			/**
			 * Anexa uma textura ao FBO no "attachment"
			 */
			virtual void attachTexture(
					GLenum texTarget,
					GLuint texId,
					GLenum attachment = GL_COLOR_ATTACHMENT0,
					int mipLevel = 0,
					int zSlice = 0
			);

			/**
			 * Free any resource bound to the "attachment" point of this FBO
			 */
			void unattach( GLenum attachment );

			/**
			 * Free any resources bound to any attachment points of this FBO
			 */
			void unattachAll();

			/**
			 * Retorna o ID do FBO
			 */
			GLuint getID() {
				return fboID;
			}


		private:
			GLuint fboID;
		};
	}
}

#endif /* GLFRAMEBUFFER_H_ */
