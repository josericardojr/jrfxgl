//---------------------------------------------------------------------------
#ifndef __INPUTDEVICES_H__
#define __INPUTDEVICES_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// Devices
//
// Autor: Luis Valente
//
// Encapsulamento dos dispositivos oferecidos pela SDL.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include "SDL.h"

namespace JRFXGL
{

	namespace Input
	{

	//---------------
	// CLASSES
	//---------------


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Keyboard
	//
	//  Descrição:
	//     - Encapsula o teclado.
	//
	//

	class Keyboard
	{
	public:

	 // Atualizar o estado do teclado
	 //
	 void update ()
		{ mKeys = SDL_GetKeyState (0); }
		
		
	 // Verificar se alguma tecla foi pressionada
	 //	 		
	 bool isKeyDown (SDLKey key) const
		{ return mKeys [key] != 0; }


	public:
	 
	 Keyboard ();

	private:

	 Uint8 * mKeys;
	 
	};



	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Mouse
	//
	//  Descrição:
	//     - Encapsula o mouse.
	//
	//

	class Mouse
	{
	public:

	 // Atualizar o estado do teclado
	 //
	 void update ()
		{ mState = SDL_GetMouseState (& mMouseX, & mMouseY); }

	 // Setar posição do mouse
	 void setPosition (int x, int y)
	    { SDL_WarpMouse(x, y); }
		
		
	 // Verificar se algum botão foi pressionado
	 //	 		
	 bool isButtonDown (Uint8 button) const
		{ return (mState & SDL_BUTTON (button)) != 0; }
		
	 
	 // Recuperar a posição Y atual do mouse
	 //
	 int getMouseX () const	 
		{ return mMouseX; }		
		
		
	 // Recuperar a posição Y atual do mouse
	 //
	 int getMouseY () const
		{ return mMouseY; }				



	public:

	 Mouse ();	 
	 
	private:

	 int    mMouseX;
	 int    mMouseY;
	 Uint8  mState;
	 
	};

	//---------------
	// FUNCTIONS
	//---------------

	// Centralizar o mouse na janela da aplicação
	void CenterMouseOnScreen ();

	// Exibir o cursor do mouse
	void ShowMouseCursor ();

	// Esconder o cursor do mouse;
	void HideMouseCursor ();




	} // end-namespace Input
} // end-namespace Gluff

//---------------------------------------------------------------------------
#endif

