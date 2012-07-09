/*---------------------------------------------------------------------------
// AbstractAppRunner
//
// Autor: Luis Valente
//
// Classe base para os executadores de aplicação.
//
// ------------------------ */


//---------------
// INCLUDES
//---------------
#include <cassert>
#include <iostream>

#include "SDL.h"
#include "../../Core/inc/AppRunner.h"
#include "../../Util/inc/Error.h"


namespace JRFXGL
{

	namespace App
	{

//	  using namespace std;
	//  using namespace Lua;



	//---------------
	// CLASSES
	//---------------

	/**
	 *
	 */
	AppRunner::AppRunner ()
	 : mIsActive           (true),
	   mAppWasInitialized  (false),   
	   mName               ("App")     
	{}
		

	/**
	 *
	 */
	AppRunner::~AppRunner ()
	{ 
	  shutDown ();
	}


					
	/**
	 * Inicializar a aplicação e executar o game loop.
	 */
	void AppRunner::go ()
	{
	  if (init () )
	  {
		mainLoop ();   
		shutDown ();	
	  }
	  
	}


	/**
	 * Initializar a aplicação.
	 */
	bool AppRunner::init ()
	{ 
	  // carregar configurações
	//  loadSettings ();
		
	  // inicializar subsistemas
	  initSDL    ();
	  initOpenGL ();

	  // Inicializar gestor de log
	  //Util::LogManager::initialize();
	  
	  // inicializar relógios
        mClock.reset ();
        mFrameTimeStopwatch.reset ();  

	  // inicialização personalizada, caso exista alguma coisa
	  // errada, encerrar a aplicação
	  if (OnInit () == false)
	   return false;
	  
	  //
        new Graphics::GUIManager();
	  mAppWasInitialized = true;  
        mFPS = 0;
	  
	  //
	  return true;
	}

	/**
	 * Carregar configuração
	 */
	void AppRunner::loadSettings ()
	{
		// configurações gerais
		//loadConfig ("config.lua");
	}



	/**
	 * Liberar recursos alocados pela aplicação.
	 */
	void AppRunner::shutDown ()
	{  
	//  if (appWasInitialized () )
		// {
			// Executar um flush para o aquivo de log
			//Util::LogManager::finalize();
			
			//
			//mAppWasInitialized = false;
			
			//
			//OnShutDown ();
		// }
		JRFXGL::Util::LogManager::instance()->close();
        //delete Graphics::GUIManager::instance();
	}



	/**
	 * Inicializar a biblioteca SDL.
	 */
	void AppRunner::initSDL ()
	{
	  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
		  Throw2("AppRunner::initSDL", "Unable to start SDL!");
	  
	  SDL_WM_SetCaption (mName.c_str (), mName.c_str ());
	  
	  // exibir/ocultar cursor
	 // SDL_ShowCursor (getConfig().showCursor);
	}


	void AppRunner::initOpenGL ()
	{
	  
	  // configurar SDL para OpenGL  
	  SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);
	  SDL_GL_SetAttribute (SDL_GL_STENCIL_SIZE, 0);
	  SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE,   24);
	  SDL_GL_SetAttribute (SDL_GL_ALPHA_SIZE,   8);

	  int flags = SDL_OPENGL;

	 // if (getConfig().useFullScreen)
//		flags |= SDL_FULLSCREEN;
	//  else
		flags |= SDL_RESIZABLE;


	  // alteração do modo de vídeo  
	  if (SDL_SetVideoMode (800, 600, 32, flags) == 0)
		Throw3 ("AppRunner::initOpenGL", "Unable to set video mode", SDL_GetError () );
	    
	    
	  // Esvaziar a fila de eventos
	  // A mudança de resolução pode causar o envio de mensagens para a fila de eventos (no Windows, pelo menos).
	  // O problema é que se a fila não for esvaziada, não será possível executar chamadas como MessageBox (), 
	  // no Windows (talvez seja algum bug da SDL).
	  SDL_Event event;
	  
	  while (SDL_PollEvent (& event))
		{;}
	    
	  
	  // Trocar os buffers para que a janela apareça com a cor de fundo (preto por padrão) e não com 
	  // o conteúdo das janelas que estão atrás da janela no programa. Isso pode acontecer, por exemplo, caso
	  // se exiba uma MessageBox na inicialização (ou seja, antes do primeiro frame ser desenhado).
	  SDL_GL_SwapBuffers ();
	  

	  // inicialização da biblioteca de extensões do OpenGL 
	  GLenum error = glewInit ();
	  if (error != GLEW_OK)
		  Throw3 ("AppRunner::initOpenGL", "Unable to init Glew!", (char*) glewGetErrorString (error) );
	  
	  // inicializar o controlador do vsync
	 // mVSyncManager.reset (new Ogl::VSyncManager);
	  
	  // desabilitar o vsync se for o caso
	 // if (getConfig().useVSync == false)
		// { mVSyncManager->disableVSync (); }

	  // Recuperar informações da janela
	  SDL_Surface *s = SDL_GetVideoSurface();
	  mWidth = static_cast<float>(s -> w);
	  mHeight = static_cast<float>( s -> h);

	  // Reiniciar o contador de frames
	  mFrameCounter.reset();

	}



	/**
	 * Processar os eventos da SDL.
	 *
	 */
	void AppRunner::processEvents ()
	{   
	   SDL_Event event;

	   
	   while (SDL_PollEvent (& event) )
		 {
			switch (event.type)
			  {
				case SDL_QUIT:
				 OnQuit ();
				 return;

				case SDL_VIDEORESIZE:
				 OnWindowResize (static_cast <float> (event.resize.w), static_cast <float> (event.resize.h) );
				 break;

				case SDL_KEYDOWN:
				 OnKeyDown (event.key.keysym);
				 break;

				case SDL_KEYUP:
				 OnKeyUp (event.key.keysym);
				 break;   

				case SDL_MOUSEBUTTONDOWN:
				 OnMouseDown (event.button);
				 break;

				case SDL_MOUSEBUTTONUP:
				 OnMouseUp (event.button);
				 break;

				case SDL_MOUSEMOTION:
				 OnMouseMove (event.motion);
				 break;
	             
				case SDL_ACTIVEEVENT:            
				{
				  if (1 == event.active.gain)
					OnActivate ();
				  else
					OnDeactivate ();
				}
				break;
	         
			 }

		}
	}



	/**
	 *
	 */

	/**
	 * Main Loop
	 */
	void AppRunner::mainLoop ()
	{
		mRequestQuit = false;

		// Processar eventos pendentes
		processEvents ();

		// Executar o loop até que seja requisitado sua finalização
		while (!mRequestQuit)
		{
            
            // Processar eventos
			processEvents();
            
			// Somente executar a aplicação se ela estiver ativa
			if (isActive() == false)
			{
				if (mFrameTimeStopwatch.isPaused() == false)
					mFrameTimeStopwatch.pause();
                
				continue;
			}
			else
			{
				// executar relógio
				if (mFrameTimeStopwatch.isPaused())
					mFrameTimeStopwatch.resume();
			}
            
			// atualizar a aplicação
			mFrameCounter.update();
            
			// Custom update application
            float f = mFrameTimeStopwatch.getElapsedSeconds();
            
            // Reset stop watch
			mFrameTimeStopwatch.reset();
            
            // Update
			OnUpdate(f);
            


            mStats.update(mFrameCounter.getFramesPerSecond());
            
            
			// Custom render application
			OnRender();
            
			// Custom GUI render
            JRFXGL::Graphics::GUIManager::instance() -> enter2D(mWidth, mHeight);
			glDisable(GL_LIGHTING);
			mStats.show();
            OnGUI();
			JRFXGL::Graphics::GUIManager::instance() -> leave2D();
            
			// Swap buffers
			SDL_GL_SwapBuffers();
		}
	}

	void AppRunner::OnActivate ()
	{
	  mIsActive = true;  
	  mFrameTimeStopwatch.reset ();
	}


	/**
	 *
	 */
	void AppRunner::OnDeactivate ()
	{
	  mIsActive = false;
	}

	 
	/**
	 *  Carregar configuração a partir de arquivo.
	 */
	void AppRunner::loadConfig (const std::string & fileName)
	{  
	//	mAppConfig = Gluff::App::Config::loadConfig (fileName);
	}
        
    void AppRunner::drawGizmo(){
        glMatrixMode(GL_PROJECTION);
    }




	} // end-namespace App
} // end-namespace Gluff


