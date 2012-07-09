//---------------------------------------------------------------------------
#ifndef __PROJECTION_H__
#define __PROJECTION_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------	
// Projection
//
// Autor: Luis Valente
//
// Abstração para projeções.
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
	//  Descrição:
	//     - Representa uma projeção 3D.
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
			
			
		  // Alterar a razão de aspecto (largura/altura) da projeção
		  //
		  void setAspectRatio (float aspect)
			  { mAspectRatio = aspect > 0.0f ? aspect : 1.0f; }
			  
			  
		  // Alterar a razão de aspecto (largura/altura) da projeção
		  //
		  void setAspectRatio (int viewWidth, int viewHeight)
			  { 
                 mWidth = viewWidth;
				 mHeight = viewHeight;

				 if (mWidth == 0)
					mWidth = 1;
					
				 mAspectRatio = (float)mWidth / (float)mHeight;
			  }


			  
		  // Retornar a razão de aspecto da projeção
		  //
		  float getAspectRatio () const
			  { return mAspectRatio; }

		  // Retornar largura da viewport
		  int getWidth ()
		      { return mWidth; }

		  // Retornar altura da viewport
		  int getHeight ()
		      { return mHeight; }


		  // Aplicar a projeção
		  //
			virtual void apply () = 0;	
			
			
			// Criar uma cópia da projeção
			//
			//virtual ProjectionPtr clone () = 0;
			
			
		protected:
			
			float mAspectRatio;  // razão entre largura e altura da viewport		
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

