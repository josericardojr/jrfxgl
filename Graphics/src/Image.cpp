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
#include "../inc/Image.h"
#include "../../Util/inc/Error.h"

namespace JRFXGL
{
	namespace Graphics
	{


	//---------------
	// STATICS
	//---------------

	// campos static da classe Initializer
	volatile bool Initializer::sWasInitialized = false;
	volatile long Initializer::sUseCount       = 0;


	// campo static da classe Image
	const Initializer Image::sImageLibraryInitializer;



	//---------------
	// CLASSES
	//---------------

	/**
	 * Inicializar a biblioteca DevIL.
	 *
	 */
	Initializer::Initializer ()
	{
	  if (sWasInitialized == false)
		{
		  sWasInitialized = true;
			FreeImage_Initialise();
		}
	  
	  ++sUseCount;
	}

	/**
	 * Finalizar o uso da biblioteca DevIL.
	 *
	 */
	Initializer::~Initializer ()
	{
	  --sUseCount;
	  
	  if (0 == sUseCount)
		{
			FreeImage_DeInitialise();
		  sWasInitialized = false;
		}
	    
	}




	/**
	 * 
	 */
	Image::Image (const std::string & filename)
	{	load (filename); }


	/**
	 * Carregar o arquivo de nome especificado.
	 */
	void Image::load (const std::string & filename)
	{ 
		mBMap = FreeImage_Load( FreeImage_GetFileType(filename.c_str()), filename.c_str());

		if (!mBMap)
			Throw3 ("FreeImage::Image::load", "Error loading image", filename);
	}

	void Image::render(float posX, float posY, int width, int height, int sWidth, int sHeight)
	{
		//Gluff::Util::Shapes::DrawTexture(mId, posX, posY, width, height, sWidth, sHeight);
	}


	} // end-namespace Ogl
} // end-namespace Gluff
