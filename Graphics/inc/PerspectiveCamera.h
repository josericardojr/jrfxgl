//---------------------------------------------------------------------------
#ifndef __PERSPECTIVECAMERA_H__
#define __PERSPECTIVECAMERA_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// PerspectiveCamera
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
	//  Descri��o:
	//		- Abstra��o para c�meras.
	//
	//
	//
	class PerspectiveCamera
	{
	  
	  public:  
	  
		PerspectiveCamera (unsigned int id = 0);


	  public:

		 // Aplicar a transforma��o de c�mera.
		 //		 		
		virtual void applyTransform () = 0;


		 // Reiniciar o estado da c�mera para um estado padr�o
		 //
		 virtual void  reset();
		   
		   
		   
	  public:
	  
	  
		 // Aplicar a proje��o associada com a c�mera.
		 //
		void applyProjection ()
		  { mProjection.apply (); }    
	      
	      
		// Alterar a rela��o de aspecto da proje��o
		// utilizada pela c�mera.
		//
		void setAspectRatio (float aspectRatio)
		  { mProjection.setAspectRatio (aspectRatio); }
	      
	    
	    
		// Alterar a proje��o utilizada pela c�mera.
		//
		void setProjection (PerspectiveProjection & projection)
		  { mProjection = projection; }
	      
	      
	    
		// Retornar o objeto que implementa a proje��o usada pela c�mera.
		//
		PerspectiveProjection & getProjection ()
		  { return mProjection; }
	      
	      
	  public:    
	    
		// Retornar o identificador da c�mera
		unsigned int getId () const
		  { return mId; }     
	      
		// Determinar um identificador para a c�mera
		void setId (unsigned int id)
		  { mId = id; }
	       
	  
	  public:
	  
		 mc::math::Vec3f    position;   // posi��o atual da c�mera
		 mc::math::Quatf    orientation;
	     
		 mc::math::Matrix4f view;       // matriz que representa a transforma��o de c�mera
	       
	  
	  protected:   

		 PerspectiveProjection mProjection;  // proje��o usada pela c�mera     
		 unsigned int mId;                   // identificador da c�mera
		   
	};
			



	} // end-namespace Ogl
} // end-namespace Gluff



//---------------------------------------------------------------------------
#endif

