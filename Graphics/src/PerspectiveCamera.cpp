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
#include "../inc/PerspectiveCamera.h"

namespace JRFXGL
{


namespace Graphics
{
	//---------------
	// CLASSES
	//---------------


	/**
	 *
	 */
	PerspectiveCamera::PerspectiveCamera (unsigned int camId)
	  : position    (mc::math::Vec3f(0, 0, 0)),
		mProjection (PerspectiveProjection::DEFAULT_PROJECTION),
		mId         (camId)
	  {}    
	   

	/**
	 *
	 */
	void PerspectiveCamera::reset ()
	{
	  orientation = mc::math::Quatf(0, 0, 0, 1);
	  
	  position = mc::math::Vec3f(0, 0, 0);
	}
	 
	 
	} // end-namespace Ogl
} // end-namespace Gluff

