/*---------------------------------------------------------------------------
// FpsController
//
// Autor: Luis Valente
//
// Controlador usado pelo usu�rio para interagir com a aplica��o.
//
// ------------------------ */


//---------------
// INCLUDES
//---------------
#include "../inc/FPSCameraController.h"


namespace JRFXGL
{

	namespace Graphics
	{

	using namespace std;
//	using namespace Math;
//	using namespace Input;
//	using namespace Util;

	//---------------
	// CLASSES
	//---------------


	/**
	 *
	 */
	ControllerKeys::ControllerKeys ()
	 :  forward     (SDLK_w),
		backward    (SDLK_s),
		strafeLeft  (SDLK_a),
		strafeRight (SDLK_d)    
	{}

	 
	//---------------
	// CLASSES
	//---------------

	/**
	 *
	 */
	FPSCameraController::FPSCameraController ()
	 : speed           (30.0f),
	   mouseSpeed      (1.0f),
	   mMouseRotationX (0)
	{
        reset();
	}


	/**
	 *
	 */
	void FPSCameraController::update (float time)
	{
		// Update keyboard
		mKeyboard.update();

		// Update mouse
		mMouse.update();

	   // Os vetores que correspondem aos movimentos lateral e "pra frente" s�o recuperados, e a checagem
	   // pelos movimentos � feita a seguir
	   //
	   mc::math::Vec3f strafe = mCamera.orientation.applyToVec3(mc::math::Vec3f(1, 0, 0)); strafe *= (speed * time);
	   mc::math::Vec3f forward = mCamera.orientation.applyToVec3(mc::math::Vec3f(0, 0, -1)); forward *= (speed * time);

	   mc::math::Vec3f position = mCamera.position;
	      
	   if (mKeyboard.isKeyDown (mKeyConfig.forward) )
       {  position += forward; }
		 
	   if (mKeyboard.isKeyDown (mKeyConfig.backward) )
		 { position -= forward; }	 
		 
	   if (mKeyboard.isKeyDown (mKeyConfig.strafeLeft) )
		 { position -= strafe; }	 
	   
	   if (mKeyboard.isKeyDown (mKeyConfig.strafeRight) )
		 { position += strafe; }
		 	 
	   
	   // As rota��es ser�o feitas pelo mouse
	   rotateByMouse (time);
	   
	   mCamera.position = position;   
	}


	/**
	 *
	 */
	void FPSCameraController::rotateByMouse (float time)
	{
	  // recuperam-se a posi��o do mouse e o tamaho da viewport
	  int mouseX;
	  int mouseY;
	  int middleX;
	  int middleY;
	  
	  middleX = mCamera.getProjection().getWidth() / 2;
	  middleY = mCamera.getProjection().getHeight() / 2;  
        
	  
	  mouseX = mMouse.getMouseX();
	  mouseY = mMouse.getMouseY();
	  
	  
	  // se n�o houve altera��o na posi��o do mouse, nada h� a fazer
	  if ( (middleX == mouseX) && (middleY == mouseY) )
		return;
	    
	  // posiciona-se o cursor no centro da tela (� o ponto de refer�ncia
	  mMouse.setPosition(middleX, middleY);
	    

	  // Calcular o valor dos �ngulos para as rota��es. Embora o c�lculo faz parecer que
	  // o resultado da conta � um �ngulo em radiano, isso � totalmente arbitr�rio. Como esse valor
	  // � bem pequeno, "converte-se" o valor para graus para se ter um valor razo�vel
	  //
	  float rotX = mc::math::deg2rad( float (mouseY - middleY) / float (middleY) ) * mouseSpeed;
	  float rotY = mc::math::deg2rad( float (mouseX - middleX) / float (middleX) ) * mouseSpeed;
	  
	  mMouseRotationX = rotX;
	  
	  
	  // Esta checagem � feita para n�o deixar a c�mera virar de cabe�a para baixo
	  if (mMouseRotationX > 80.0f)
		{ mMouseRotationX = 80.0f; return; }
	  
	  if (mMouseRotationX < -80.0f)
		{ mMouseRotationX = -80.0f; return; }
	  

	  mc::math::Vec3f vX = mCamera.orientation.applyToVec3(mc::math::Vec3f(1, 0, 0));

	  mCamera.rotate (rotX, vX);
	  mCamera.rotate (rotY, mc::math::Vec3f(0, 1, 0));
	    
	}



	/**
	 *
	 */
	void FPSCameraController::reset ()
	{ 
		int middleX = mCamera.getProjection().getWidth() / 2;
		int middleY = mCamera.getProjection().getHeight() / 2;  

		// posiciona-se o cursor no centro da tela (� o ponto de refer�ncia
		mMouse.setPosition(middleX, middleY);

		resetOrientation ();  
		mCamera.position = mc::math::Vec3f(0, 0, 0);
	} 

	/**
	 *
	 */
	void FPSCameraController::resetOrientation ()
	{
		mc::math::Vec3f pos = mCamera.position;
	  
	  mCamera.reset ();
	  mMouseRotationX  = 0;    
	  mCamera.position = pos;
	}




	} // end-namespace App

} // end-namespace Gluff
