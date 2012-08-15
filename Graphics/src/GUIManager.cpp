#include "../inc/GUIManager.h"
#include "../../Util/inc/Error.h"
#include "GL/glew.h"

namespace JRFXGL
{

	namespace Graphics
	{
		GUIManager::GUIManager()
		{
            
			mSystemFont = new FTGLBitmapFont("resources/arial.ttf");

			// Verificar se carregou corretamente
			if (mSystemFont -> Error())
				Throw3("GUIManager::GUIManager", "Error loading font.", "Arial");

			if (mSystemFont -> FaceSize(16) == false)
				Throw3("GUIManager::GUIManager", "Error setting font size.", "16");
		}

		GUIManager::~GUIManager()
		{
			printf("Deleting GUIManager\n");
			delete mSystemFont;
			printf("GUIManager released.\n");
		}


		// Ativar modo ortografico
		void GUIManager::enter2D(int width, int height)
		{
			// Configurar a matriz de projeção
			glMatrixMode(GL_PROJECTION);
			  glPushMatrix();

			  glLoadIdentity();

			  glOrtho(0, width, height, 0, -1.0f, 1.0f);

			 // Salvar matriz model view
			 glMatrixMode(GL_MODELVIEW);
			 
			 glPushMatrix();

			 glLoadIdentity();

			 // Modo 2D
			 mIn2DMode = true;
		}

		// Desativar modo ortografico
		void GUIManager::leave2D()
		{
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();

			glMatrixMode(GL_MODELVIEW);
			glPopMatrix();

			mIn2DMode = false;
		}

		// Escrever na tela com fonte padrão
		void GUIManager::label(std::string text, int x, int y)
		{
			if (!mIn2DMode)
				Throw2("GUIManager::label", "Projection not in 2D mode!");

			glLoadIdentity();
			glRasterPos2d(x, y);
			mSystemFont -> Render( text.c_str() );
		}


	} // end-namespace GUI

} // end-namespace Gluff
