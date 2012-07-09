/*---------------------------------------------------------------------------
// FpsController
//
// Autor: Luis Valente
//
// Controlador usado pelo usuário para interagir com a aplicação.
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

	   // Os vetores que correspondem aos movimentos lateral e "pra frente" são recuperados, e a checagem
	   // pelos movimentos é feita a seguir
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
		 	 
	   
	   // As rotações serão feitas pelo mouse
	   rotateByMouse (time);
	   
	   mCamera.position = position;   
	}


	/**
	 *
	 */
	void FPSCameraController::rotateByMouse (float time)
	{
	  // recuperam-se a posição do mouse e o tamaho da viewport
	  int mouseX;
	  int mouseY;
	  int middleX;
	  int middleY;
	  
	  middleX = mCamera.getProjection().getWidth() / 2;
	  middleY = mCamera.getProjection().getHeight() / 2;  
        
	  
	  mouseX = mMouse.getMouseX();
	  mouseY = mMouse.getMouseY();
	  
	  
	  // se não houve alteração na posição do mouse, nada há a fazer
	  if ( (middleX == mouseX) && (middleY == mouseY) )
		return;
	    
	  // posiciona-se o cursor no centro da tela (é o ponto de referência
	  mMouse.setPosition(middleX, middleY);
	    

	  // Calcular o valor dos ângulos para as rotações. Embora o cálculo faz parecer que
	  // o resultado da conta é um ângulo em radiano, isso é totalmente arbitrário. Como esse valor
	  // é bem pequeno, "converte-se" o valor para graus para se ter um valor razoável
	  //
	  float rotX = mc::math::deg2rad( float (mouseY - middleY) / float (middleY) ) * mouseSpeed;
	  float rotY = mc::math::deg2rad( float (mouseX - middleX) / float (middleX) ) * mouseSpeed;
	  
	  mMouseRotationX = rotX;
	  
	  
	  // Esta checagem é feita para não deixar a câmera virar de cabeça para baixo
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

		// posiciona-se o cursor no centro da tela (é o ponto de referência
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
