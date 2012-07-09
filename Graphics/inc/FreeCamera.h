//---------------------------------------------------------------------------
#ifndef __FREECAMERA_H__
#define __FREECAMERA_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// FreeCamera
//
// Autor: Luis Valente
//
// C�meras para OpenGL.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include "../../Math/inc/mcMath.h"
#include "PerspectiveCamera.h"


//---------------
// CLASSES
//---------------

namespace JRFXGL
{

	namespace Graphics
	{


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  FreeCamera
	//
	//  Descri��o:
	//		- Representa uma c�mera com 6 graus de liberdade.
	//
	//
	//


	class FreeCamera : public PerspectiveCamera
	{
	  public:
	    
		 FreeCamera (unsigned int camId = 0);

	  public:
	    
		 // Aplicar a transforma��o de c�mera
		 void applyTransform ();    
		 
		 
		 // Reiniciar o estado da c�mera para um estado padr�o
		 void reset ();
	    
	  public:
	    
	            
		 // Rotacionar `ang` graus em torno do eixo especificado      
		void rotate (float ang, const mc::math::Vec3f & axis);


		// Aplicar uma transforma��o de transla��o
		void translate (mc::math::Vec3f& displace);
	      
	      
	  public:    
	          
	      
		 // Retornar o vetor com a dire��o para onde a c�mera aponta, em coordenadas do mundo
		//Math::Vector3 getViewVector () const
			//{ return Math::Vector3 (-localZ.x, -localZ.y, -localZ.z); }
	        
	      
	      
	};



	} // end-namespace Ogl
} // end-namespace Gluff





//---------------------------------------------------------------------------
#endif

