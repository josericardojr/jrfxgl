/*
 * LogManager.cpp
 *
 *  Created on: 25/07/2011
 *      Author: josericardo
 */

#include "../inc/LogManager.h"
//#include <boost/shared_ptr.hpp>


JRFXGL::Util::LogManager* JRFXGL::Util::LogManager::_instance = NULL;

namespace JRFXGL
{
	namespace Util
	{
		LogManager::LogManager()
		{
			textLog = fopen("Output.log", "w");
			fprintf(textLog, "Begin Log");
		}

		LogManager::~LogManager()
		{
			fprintf(textLog, "End Log");
			fclose(textLog);
		}

		void LogManager::close()
		{
			fprintf(textLog, "End Log");
			fclose(textLog);
		}

		LogManager* LogManager::instance()
		{
			if (_instance == NULL)
				_instance = new LogManager();
				//_instance.reset(new LogManager());

			//return _instance.get();
			return _instance;
		}

		void LogManager::log(std::string s){
			fprintf(textLog, "%s", s.c_str());
		}

		void LogManager::log(float f){
			fprintf(textLog, "%f", f);
		}

		void LogManager::log(int i){
			fprintf(textLog, "%d", i);
		}

		void LogManager::log(mc::math::Vec3f& vec){
			fprintf(textLog, "X:%f Y:%f Z:%f", vec.x, vec.y, vec.z);
		}
	}
}
