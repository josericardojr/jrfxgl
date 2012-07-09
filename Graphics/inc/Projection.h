//---------------------------------------------------------------------------
#ifndef __PROJECTION_H__
#define __PROJECTION_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------	
// Projection
//
// Autor: Luis Valente
//
// Abstra��o para proje��es.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
//#include "boost/shared_ptr.hpp"

namespace JRFXGL
{

	namespace Graphics
	{

	//---------------
	// CLASSES
	//---------------

	class Projection;

	//typedef boost::shared_ptr <Projection> ProjectionPtr;



	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Projection
	//
	//  Descri��o:
	//     - Representa uma proje��o 3D.
	//
	//

	class Projection
	{
	  public:

		   Projection ()
				: mAspectRatio (1.0f),
				  mWidth(1),
				  mHeight(1)
				{}			
				
		public:
			
			
		  // Alterar a raz�o de aspecto (largura/altura) da proje��o
		  //
		  void setAspectRatio (float aspect)
			  { mAspectRatio = aspect > 0.0f ? aspect : 1.0f; }
			  
			  
		  // Alterar a raz�o de aspecto (largura/altura) da proje��o
		  //
		  void setAspectRatio (int viewWidth, int viewHeight)
			  { 
                 mWidth = viewWidth;
				 mHeight = viewHeight;

				 if (mWidth == 0)
					mWidth = 1;
					
				 mAspectRatio = (float)mWidth / (float)mHeight;
			  }


			  
		  // Retornar a raz�o de aspecto da proje��o
		  //
		  float getAspectRatio () const
			  { return mAspectRatio; }

		  // Retornar largura da viewport
		  int getWidth ()
		      { return mWidth; }

		  // Retornar altura da viewport
		  int getHeight ()
		      { return mHeight; }


		  // Aplicar a proje��o
		  //
			virtual void apply () = 0;	
			
			
			// Criar uma c�pia da proje��o
			//
			//virtual ProjectionPtr clone () = 0;
			
			
		protected:
			
			float mAspectRatio;  // raz�o entre largura e altura da viewport		
			int   mWidth;        // Largura da viewport
			int   mHeight;       // Altura da viewport

	};


	//---------------
	// TYPEDEFS
	//---------------





	} // end-namespace Ogl
} // end-namespace Gluff


//---------------------------------------------------------------------------
#endif

