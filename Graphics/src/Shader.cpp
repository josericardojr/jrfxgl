/*---------------------------------------------------------------------------
//
// Author: Luis Valente
//
// Represents a gpu shader.
//
// ------------------------ */


// INCLUDES
#include "../inc/Shader.h"
#include <boost/scoped_array.hpp>

using namespace std;
using namespace boost;

namespace JRFXGL
{
	namespace Graphics
	{


	// _________________________________________________________________________
	//
	// 
			
	Shader::Shader (GLenum shaderType, const std::string & sourceFilename)
	{
		// debug
		ASSERT2 (shaderType == GL_VERTEX_SHADER || shaderType == GL_FRAGMENT_SHADER, "Ogl::Shader: Invalid shader type");

		// load source
		string source = JRFXGL::Util::FileSystem::loadTextFile (sourceFilename);
		
		// create shader object
		mId = glCreateShader (shaderType);	
		
		// set source
		const char * src = source.c_str();
		glShaderSource (mId, 1, &src, 0);
		
		// compile it
		glCompileShader (mId);

		// get errors
		if (getParam (GL_COMPILE_STATUS) == GL_FALSE)
		{
			std::string error = getInfoLog();			
			// we got an error		
			Throw4 ("Shader::Shader", "Compile failed", sourceFilename, getInfoLog() );
		}
		
	}

	// _________________________________________________________________________
	//
	// 
			
	Shader::~Shader()
	{
		// delete shader
		glDeleteShader (mId);
	}

	// _________________________________________________________________________
	//
	// 
			
	void Shader::compile () const
	{
		glCompileShader (mId);
	}

	// _________________________________________________________________________
	//
	// 
			
	GLint Shader::getParam (GLenum param) const
	{
		GLint p;	
		glGetShaderiv (mId, param, &p);	

		// debug
		ASSERT2 (glGetError() == GL_NO_ERROR, "Invalid param?");
		
		//
		return p;	
	}

	// _________________________________________________________________________
	//
	// 
			
	std::string Shader::getInfoLog () const
	{
		// get info log size
		GLint logSize = getParam (GL_INFO_LOG_LENGTH);
		
		// reserve string for log
		scoped_array <GLchar> log (new char [logSize]);	
		
		// get log
		glGetShaderInfoLog (mId, logSize, 0, log.get());
		
		// 
		return string (log.get());
	}

	} // end-namespace Ogl
} // end-namespace Gluff
