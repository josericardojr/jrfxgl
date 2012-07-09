//---------------------------------------------------------------------------
#ifndef __FPSCAMERACONTROLLER_H__
#define __FPSCAMERACONTROLLER_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// FreeCameraController
//
// Autor: Jose Ricardo
//
// Controlador usado pelo usu�rio para interagir com a aplica��o, sem restri��o de movimento.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include <memory>
#include <SDL.h>
//#include "../../Inc/Math/Vector3.h"
#include "FreeCamera.h"
#include "../../Devices/inc/Devices.h"


//---------------
// CLASSES
//---------------

namespace JRFXGL
{

	namespace Graphics
	{


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  ControllerKeys
	//
	//  Descri��o:
	//		- Representa a configura��o de teclas para a FreeCameraController.
	//
	//
	//
	struct ControllerKeys
	{
	  SDLKey forward;
	  SDLKey backward;
	  SDLKey strafeLeft;
	  SDLKey strafeRight;
	  
	  public:
		 
		 ControllerKeys ();	 
	  
	};


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  FPSCameraController
	//
	//  Descri��o:
	//		- Controlador sem restri��es para movimenta��o no cen�rio.
	//
	//
	//
	class FPSCameraController
	{
	  public:
	  
		float               speed;
		float               mouseSpeed;
		mc::math::Vec4f     position;
	        
	  
	  public:  
	  
		 FPSCameraController ();
	     
	  public:
	  
		 // atualizar a posi��o/orienta��o da c�mera
		 void update (float time);        
		 
		 
		 // reiniciar o controlador
		 void reset ();	 
		 
		 // reiniciar o posicionamento/orienta��o do mouse
		 void resetOrientation ();	 	 
		 
	 
		 // recuperar a c�mera usada pelo programa
		 Graphics::FreeCamera & getCamera ()
			{ return mCamera; }
			
		     
	     
	  private:
	  
		void rotateByMouse (float time);  
	    
	    
	  private:
	  
		Input::Keyboard          mKeyboard;
		Input::Mouse             mMouse;
		FreeCamera               mCamera;
		ControllerKeys           mKeyConfig;
		float                    mMouseRotationX;
	    
	    	   
	};
			


	} // end-namespace App

} // end-namespace Gluff



//---------------------------------------------------------------------------
#endif

