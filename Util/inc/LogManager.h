//---------------------------------------------------------------------------
#ifndef __LOGMANAGER_H__
#define __LOGMANAGER_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// Util
//
// Autor: Jos� Ricardo
//
// Fun��es para gerar Log em tela ou sa�da em v�deo
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include "../../Math/inc/mcMath.h"
#include <fstream>

namespace JRFXGL
{

	namespace Util 
	{
		class LogManager
		{
		private:
			FILE* textLog;
			//static boost::shared_ptr<LogManager> _instance;
			static LogManager* _instance;

		private:
			LogManager();

		public:
			
			~LogManager();

			static LogManager* instance();

			void log(std::string s);

			void log(float f);

			void log(int i);
			
			void log(mc::math::Vec3f& vec);

			void close();
		};
	} // end-namespace Util
} // end-namespace Guff

#endif
