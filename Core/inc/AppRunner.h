//---------------------------------------------------------------------------
#ifndef __APP_RUNNER_H__
#define __APP_RUNNER_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// AbstractAppRunner
//
// Autor: Luis Valente
//
// Classe base para os executadores de aplicação.
//
// ------------------------ */

#include <string>

#include "GL/glew.h"
#include "SDL.h"
#include "../../Util/inc/Clock.h"
#include "../../Util/inc/StopWatch.h"
#include "../../Util/inc/FrameCounter.h"
#include "../../Util/inc/LogManager.h"
#include "../../Graphics/inc/GUIManager.h"
#include "Stats.h"

/*#include "../../Inc/App/Config.h"
#include "../../Inc/Sys/Clock.h"
#include "../../Inc/Sys/Stopwatch.h"
#include "../../Inc/Ogl/VSyncManager.h"
#include "../../Inc/Util/LogManager.h"
#include "../../Inc/Util/FrameCounter.h"*/


namespace JRFXGL
{

	namespace App
	{


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  AppRunner
	//
	//  Descrição:
	//     - Esqueleto para classes que executam aplicações. Algumas operações
	//		comuns (inicialização de sub-sistemas) já estão implementadas.
	//
	//


	class AppRunner
	{
	  public:
		virtual ~AppRunner ();
		
	  protected:    
		AppRunner ();
	    
	  public:
	  
		// inicializar e executar a aplicação.
		virtual void go ();

		// recuperar largura da janela
		int getWidth(){ return mWidth; }

		// recuperar altura da janela
		int getHeight(){ return mHeight; }

		// setar título da janela
		void setCaption(char* caption)
		{ 
			mName = std::string(caption);
			SDL_WM_SetCaption (mName.c_str (), mName.c_str ());
		}

		 
	  protected:	 
	  
		// implementação do game loop
		virtual void mainLoop ();
		
		// carregar configurações da aplicação
		virtual void loadSettings ();
		
	  protected:
	  
		// processar eventos de aplicação
		void processEvents ();	 
		 
		 
		// verificar se a aplicação está ativa
		bool isActive () const
		 { return mIsActive; }		 
		 
		 
		// verificar se a aplicação foi inicializa corretamente
		bool appWasInitialized () const
		 { return mAppWasInitialized; }
		 
		 
		// recuperar o relógio
        Util::Clock & getClock ()
		 { return mClock; }
		 
		 
		// recuperar o cronômetro
		Util::Stopwatch & getStopwatch ()
		 { return mFrameTimeStopwatch; }
		 
		
		// recuperar configuração da aplicação
//		App::Config & getConfig ()
//		 { return mAppConfig; }
		 
		 
		// carregar configuração a partir de arquivo
		void loadConfig (const std::string & fileName);
		
		 
		// recuperar gerente de vsync
//		Ogl::VSyncManager * getVSyncManager ()
//		 { return mVSyncManager.get (); }
		 
		 
		//
		std::string getName () const
		 { return mName; }
		 
		 
		//
		void setName (const std::string & name)
		 { mName = name; }
        
        int getFPS(){
            return mFPS;
        }
        
        void showGizmo(bool visible){
            mShowGizmo = visible;
        }
        

		
	  protected:
	  
		// eventos que a classe pode tratar
		virtual bool OnInit       () { return true; }
		virtual void OnShutDown   () {}
		
		// eventos de sistema
		virtual void OnActivate     ();
		virtual void OnDeactivate   ();	
		virtual void OnQuit         () { mRequestQuit = true; }
		virtual void OnWindowResize (float width, float height) {}
		virtual void OnMouseDown    (const SDL_MouseButtonEvent & event) {}
		virtual void OnMouseUp      (const SDL_MouseButtonEvent & event) {}
		virtual void OnMouseMove    (const SDL_MouseMotionEvent & event) {}
		virtual void OnKeyDown      (const SDL_keysym & keysym) {}
		virtual void OnKeyUp        (const SDL_keysym & keysym) {}
		virtual void OnRender       () {}
		virtual void OnGUI          () {}
		virtual void OnUpdate       (float dt) {}
				
	  private:
	  
		 bool init          ();
		 void initSDL       ();
		 void initOpenGL    ();
		 void shutDown      ();	 
         void drawGizmo     ();
        
        //void createGrid();
		 
	  private:
	  
         int                      mWidth;
		 int                      mHeight;
         int                      mFPS;

		 bool                     mIsActive;
         bool                     mShowGizmo;
		 bool                     mAppWasInitialized;	
		 std::string              mName;
		 
		 Util::Clock              mClock;
        Stats                     mStats;
			
		 //App::Config              mAppConfig;
		 //Ogl::VSyncManagerPtr     mVSyncManager;

	   protected:
		 bool                     mRequestQuit;

		 Util::Stopwatch          mFrameTimeStopwatch;
		 Util::FrameCounter       mFrameCounter;

	};


	} // end-namespace App

} // end-namespace Gluff



//---------------------------------------------------------------------------
#endif

