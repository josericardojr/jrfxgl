//---------------------------------------------------------------------------
#ifndef __PERSPECTIVEPROJECTION_H__
#define __PERSPECTIVEPROJECTION_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// PerspectiveProjection
//
// Autor: Luis Valente
//
// Proje��es em perspectiva.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include <GL/glew.h>
#include "Projection.h"
#include <stdio.h>

namespace JRFXGL
{

	namespace Graphics
	{

	//---------------
	// CLASSES
	//---------------


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  PerspectiveProjection
	//
	//  Descri��o:
	//     - Representa uma proje��o em perspectiva de um ponto.
	//
	//

	class PerspectiveProjection : public Projection
	{
	  protected:
	  
		 float fovX;          // campo de vis�o na dire��o do eixo X.
		 float nearPlane;     
		 float farPlane;


	  public:
	  
		  PerspectiveProjection ()
			  : fovX(60.0f),
			    nearPlane(1.0f),
			    farPlane(1000.0f)
		  {}

		  void setPlanes(float _near, float _far)
		  {
			  nearPlane = _near;
			  farPlane = _far;
		  }

		 PerspectiveProjection (float fieldOfViewX, float nearClippingPlane, float farClippingPlane)
			 : fovX(fieldOfViewX),
			   nearPlane(nearClippingPlane),
			   farPlane(farClippingPlane)
		 {}


		 void apply ()
			{
				glMatrixMode (GL_PROJECTION);
				printf("%f, %f, %f, %f\n", fovX, mAspectRatio, nearPlane, farPlane);
				glLoadIdentity ();				
				gluPerspective (fovX, mAspectRatio, nearPlane, farPlane);
				
				glMatrixMode (GL_MODELVIEW);
				glLoadIdentity ();
			}	

		 void setFovX(float angle)
		 {
			 fovX = angle;
		 }

	public:
		static const PerspectiveProjection DEFAULT_PROJECTION;

	};




	} // end-namespace Ogl
} // end-namespace Gluff




//---------------------------------------------------------------------------
#endif

