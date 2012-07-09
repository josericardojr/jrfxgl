/*---------------------------------------------------------------------------
//
// Author: Jose Ricardo
//
// File System Manager
//
// ------------------------ */


// INCLUDES
#include "../inc/FileSystem.h"
#include <boost/scoped_array.hpp>

namespace JRFXGL
{
	namespace Util
	{
		std::string FileSystem::loadTextFile(std::string filename)
		{
			// create stream
			std::ifstream stream (filename.c_str() );
		
			// is it valid ?
			if (!stream)
				Throw3 ("FileSystem::loadTextFile", "Load failed!", filename);
		
			// load it
			std::string txt;
		
			while (!stream.eof () )
			{
				std::string tmp;
				std::getline (stream, tmp);
			
				txt += tmp;
				txt += "\n";
			}

			stream.close();
		
			return txt;	
		}
	}
}
