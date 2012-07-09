//---------------------------------------------------------------------------
#ifndef __SHADER_H__
#define __SHADER_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
//
// Author: Luis Valente
//
// GLSL shader programs.
//
// ------------------------ */


// INCLUDES
#include <string>
#include <boost/shared_ptr.hpp>
#include <GL/glew.h>
#include "../../Util/inc/Error.h"
#include "../../Util/inc/FileSystem.h"

namespace JRFXGL
{
	namespace Graphics
	{

	// CLASSES
	   
	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Shader
	//
	//  Descrição:
	//     - Represents a gpu shader (vp or fp).
	//
	//
	class Shader
	{
		public:
	  
			// main constructor, loads shader from file
			Shader (GLenum shaderType, const std::string & sourceFilename);

			// destructor
			~Shader();
		  
		public:

			// compiles the shader
			void compile () const;

			// gets a parameter
			GLint getParam (GLenum param) const;

			// gets the info log
			std::string getInfoLog () const;
			 

		private:

			GLuint getId () const
			 { return mId; }
			 
		private:

			GLuint mId;

		private:
			friend class Program;

	};

			
	//---------------
	// TYPEDEFS
	//---------------

	typedef boost::shared_ptr <Shader> ShaderPtr;

	} // end-namespace Ogl

} // end-namespace Gluff



//---------------------------------------------------------------------------
#endif



