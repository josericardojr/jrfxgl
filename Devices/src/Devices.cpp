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
#include "../inc/Devices.h"
//#include "../../Inc/Util/Util.h"

namespace JRFXGL
{

	namespace Input
	{

	//---------------
	// CLASSES
	//---------------

	/**
	 *
	 */
	Keyboard::Keyboard ()
	 : mKeys (0)
	 { update (); }
	 

	/**
	 *
	 */
	Mouse::Mouse ()
	 : mMouseX (0),
	   mMouseY (0),
	   mState  (0)
	{ update (); }   



	//---------------
	// FUNCTIONS
	//---------------


	/**
	 * Positionar o cursor do mouse no centro da tela
	 */
/*	void CenterMouseOnScreen ()
	{  
	  using namespace Util;
	  
	  int mx = 0;
	  int my = 0;
	  
	  GetWindowDimensions (mx, my);

	  SDL_WarpMouse (mx/2, my/2);

	}*/

	/**
	 * Exibir o cursor do mouse
	 */
	void ShowMouseCursor ()
	{ SDL_ShowCursor (1); }


	/**
	 * Esconder o cursor do mouse
	 */ 
	void HideMouseCursor ()
	{ SDL_ShowCursor (0); }




	} // end-namespace Input
} // end-namespace Gluff


