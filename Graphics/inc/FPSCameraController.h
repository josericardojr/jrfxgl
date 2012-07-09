//---------------------------------------------------------------------------
#ifndef __FPSCAMERACONTROLLER_H__
#define __FPSCAMERACONTROLLER_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// FreeCameraController
//
// Autor: Jose Ricardo
//
// Controlador usado pelo usuário para interagir com a aplicação, sem restrição de movimento.
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
	//  Descrição:
	//		- Representa a configuração de teclas para a FreeCameraController.
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
	//  Descrição:
	//		- Controlador sem restrições para movimentação no cenário.
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
	  
		 // atualizar a posição/orientação da câmera
		 void update (float time);        
		 
		 
		 // reiniciar o controlador
		 void reset ();	 
		 
		 // reiniciar o posicionamento/orientação do mouse
		 void resetOrientation ();	 	 
		 
	 
		 // recuperar a câmera usada pelo programa
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

