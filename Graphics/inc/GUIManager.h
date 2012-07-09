//---------------------------------------------------------------------------
#ifndef __GUIMANAGER_H__
#define __GUIMANAGER_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// GUIManager
//
// Autor: Jose Ricardo
//
// Exibi��o de elementos 2D.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include <string>
#include <boost/scoped_ptr.hpp>

#include <FTGL/ftgl.h>

namespace JRFXGL
{

	namespace Graphics
	{

	//---------------
	// CLASSES
	//---------------

	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  FrameCounter
	//
	//  Descri��o:
	//     - Classe para gerenciamento de GUI.
	//
	//


	class GUIManager
	{
	  public:
		  
		  // Recuperar inst�ncia
		  static GUIManager* instance()
		  {
			  return _instance;
		  }
		

		  // Entra no modo 2D
		  void enter2D(int width, int height);

		  // Sai do modo 2D
		  void leave2D();

	   public:
		  
		  // Escrever um texto na tela
		  void label(std::string text, int x, int y);

	public:
		GUIManager();

		~GUIManager();

			
	  private:  		 
		  // Verificar se a proje��o est� configurada corretamente
		  bool                      mIn2DMode;	

		  // Fonte padr�o do sistema
		  FTFont*                   mSystemFont;
          static GUIManager* _instance;
	};




	} // end-namespace Graphics

} // end-namespace JRFXGL

//---------------------------------------------------------------------------
#endif

