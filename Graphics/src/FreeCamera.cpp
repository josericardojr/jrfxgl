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
#include <GL/glew.h>
#include "../inc/FreeCamera.h"

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
	FreeCamera::FreeCamera (unsigned int camId)
	: PerspectiveCamera (camId)
	{ reset ();}


//46868
	//86916
	/**
	 *
	 */
	void FreeCamera::rotate (float ang, const mc::math::Vec3f& axis)
	{
		mc::math::Quatf q; q.setValue(axis, ang);

		orientation = q * orientation;
		orientation.normalizeQuaternion();
	}
	   
	      

	      
	/**
	 * 
	 */
	void FreeCamera::translate (mc::math::Vec3f& displace)
	{ 
	  position += displace;
	}


	/**
	 *
	 */      
	void FreeCamera::applyTransform () 
	{
		mProjection.apply();
		mc::math::Matrix4f rot;
		orientation.getValue(rot);
		rot.transpose();
		glMultMatrixf(rot.getArray());
		glTranslatef(-position.x, -position.y, -position.z);
	}


	/**
	 * Reiniciar o estado da câmera para um estado padrão.
	 */
	void FreeCamera::reset ()
	{
	  orientation = mc::math::Quatf(0, 0, 0, 1);
	  
	  position.zero();
	}

	} // end-namespace Ogl
} // end-namespace Gluff

