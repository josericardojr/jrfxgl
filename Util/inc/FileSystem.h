//---------------------------------------------------------------------------
#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
//
// Author: Jose Ricardo
//
// File System Manager
//
// ------------------------ */


// INCLUDES
#include <iostream>
#include <fstream>
#include <string>
#include "Error.h"
/*
#include <boost/shared_ptr.hpp>
#include <GL/glew.h>
#include "Guff/Util/Util.h"
//#include "Guff/NonCopiable.h"
*/

namespace JRFXGL
{
	namespace Util
	{

	// CLASSES
	   
	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Shader
	//
	//  Descrição:
	//     - File System Manager
	//
	//
	class FileSystem
	{
		public:

			// loads a text file
			static std::string loadTextFile(std::string filename);	 

		private:
			//NO_COPIES_PLEASE(Shader);			

	};		

	} // end-namespace Util

} // end-namespace Gluff



//---------------------------------------------------------------------------
#endif



