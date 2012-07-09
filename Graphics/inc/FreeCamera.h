//---------------------------------------------------------------------------
#ifndef __FREECAMERA_H__
#define __FREECAMERA_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// FreeCamera
//
// Autor: Luis Valente
//
// Câmeras para OpenGL.
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
	//  Descrição:
	//		- Representa uma câmera com 6 graus de liberdade.
	//
	//
	//


	class FreeCamera : public PerspectiveCamera
	{
	  public:
	    
		 FreeCamera (unsigned int camId = 0);

	  public:
	    
		 // Aplicar a transformação de câmera
		 void applyTransform ();    
		 
		 
		 // Reiniciar o estado da câmera para um estado padrão
		 void reset ();
	    
	  public:
	    
	            
		 // Rotacionar `ang` graus em torno do eixo especificado      
		void rotate (float ang, const mc::math::Vec3f & axis);


		// Aplicar uma transformação de translação
		void translate (mc::math::Vec3f& displace);
	      
	      
	  public:    
	          
	      
		 // Retornar o vetor com a direção para onde a câmera aponta, em coordenadas do mundo
		//Math::Vector3 getViewVector () const
			//{ return Math::Vector3 (-localZ.x, -localZ.y, -localZ.z); }
	        
	      
	      
	};



	} // end-namespace Ogl
} // end-namespace Gluff





//---------------------------------------------------------------------------
#endif

