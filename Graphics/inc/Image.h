//---------------------------------------------------------------------------
#ifndef _IMAGE_H_
#define _IMAGE_H_
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// Image
//
// Autor: Luis Valente
//
// Manipulação de arquivos de imagens
//
// ------------------------ */


//---------------
// INCLUDES
//---------------
#include <string>
#include <memory>
#include <stdexcept>
#include <boost/shared_ptr.hpp>
#include <FreeImage.h>
#include <GL/glew.h>


namespace JRFXGL
{
	namespace Graphics
	{


	//---------------
	// CLASSES
	//---------------

	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Initializer
	//
	//  Descrição:
	//     -  Usado para inicializar e finalizar automaticamente a DevIL.
	//				
	//
	//

	class Initializer
	{
	  public:
	      
		  Initializer ();
		 ~Initializer ();
		 
	  private:

		 static volatile bool  sWasInitialized;
	   static volatile long  sUseCount;    
	        
	};




	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Image
	//
	//  Descrição:
	//     - Representa uma imagem da DevIL.
	//
	//
	class Image
	{
		public:    
		   Image (const std::string & filename);

			 ~Image(){ 
				 FreeImage_Unload(mBMap); 
				 glDeleteTextures(1, &mId);
			 }
	              
		public:
	    
		   // Selecionar a imagem para uso
		   void bind () const
			 { glBindTexture(GL_TEXTURE_2D, mId); }

			 void unbind()
			 { glBindTexture(GL_TEXTURE_2D, 0); }
	        
		   // Carregar um arquivo de imagem
		   void load (const std::string & filename);  

			 // Desenhtar textura
			 void render( float posX, float posY, int width, int height, int sWidth, int sHeight);

	              
		public:    
	       
			GLsizei getWidth() const 
			{ return FreeImage_GetWidth(mBMap); }

			GLsizei getHeight() const
			{ return FreeImage_GetHeight(mBMap); }

		 //  ILint getBytesPerPixel() const
		//	{ bind (); return ilGetInteger (IL_IMAGE_BYTES_PER_PIXEL); }

			 GLint getFormat() const
			{ 
				FREE_IMAGE_COLOR_TYPE type = FreeImage_GetColorType(mBMap);

				switch (type)
				{
				case FIC_RGB:
					return GL_RGB;
				case FIC_RGBALPHA:
					return GL_RGBA;
				}

				return 0;
			}
				

		  // ILint getBufferType() const
		//	{ bind (); return ilGetInteger (IL_IMAGE_TYPE); }

			 BYTE * getData() const
			 { return FreeImage_GetBits(mBMap); }
		   
		private:	
		   //ImageObjectPtr mImageObject;  
			FIBITMAP*            mBMap;
			GLuint               mId;

	  private:
	     
		  // este campo é utilizado para inicializar automaticamente a biblioteca
			static const Initializer sImageLibraryInitializer;
	};



	//---------------
	// TYPEDEFS
	//---------------

	typedef boost::shared_ptr <Image> ImagePtr;
	typedef std::auto_ptr <Initializer> InitializerAutoPtr;




	} // end-namespace Ogl
} // end-namespace Gluff



//---------------------------------------------------------------------------
#endif










