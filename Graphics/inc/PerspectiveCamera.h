//---------------------------------------------------------------------------
#ifndef __PERSPECTIVECAMERA_H__
#define __PERSPECTIVECAMERA_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// PerspectiveCamera
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
#include "PerspectiveProjection.h"
 

//---------------
// CLASSES
//---------------


namespace JRFXGL
{

	namespace Graphics
	{


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  PerspectiveCamera
	//
	//  Descrição:
	//		- Abstração para câmeras.
	//
	//
	//
	class PerspectiveCamera
	{
	  
	  public:  
	  
		PerspectiveCamera (unsigned int id = 0);


	  public:

		 // Aplicar a transformação de câmera.
		 //		 		
		virtual void applyTransform () = 0;


		 // Reiniciar o estado da câmera para um estado padrão
		 //
		 virtual void   ;
		   
		   
		   
	  public:
	  
	  
		 // Aplicar a projeção associada com a câmera.
		 //
		void applyProjection ()
		  { mProjection.apply (); }    
	      
	      
		// Alterar a relação de aspecto da projeção
		// utilizada pela câmera.
		//
		void setAspectRatio (float aspectRatio)
		  { mProjection.setAspectRatio (aspectRatio); }
	      
	    
	    
		// Alterar a projeção utilizada pela câmera.
		//
		void setProjection (PerspectiveProjection & projection)
		  { mProjection = projection; }
	      
	      
	    
		// Retornar o objeto que implementa a projeção usada pela câmera.
		//
		PerspectiveProjection & getProjection ()
		  { return mProjection; }
	      
	      
	  public:    
	    
		// Retornar o identificador da câmera
		unsigned int getId () const
		  { return mId; }     
	      
		// Determinar um identificador para a câmera
		void setId (unsigned int id)
		  { mId = id; }
	       
	  
	  public:
	  
		 mc::math::Vec3f    position;   // posição atual da câmera
		 mc::math::Quatf    orientation;
	     
		 mc::math::Matrix4f view;       // matriz que representa a transformação de câmera
	       
	  
	  protected:   

		 PerspectiveProjection mProjection;  // projeção usada pela câmera     
		 unsigned int mId;                   // identificador da câmera
		   
	};
			



	} // end-namespace Ogl
} // end-namespace Gluff



//---------------------------------------------------------------------------
#endif

