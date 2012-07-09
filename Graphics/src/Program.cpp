/*---------------------------------------------------------------------------
//
// Author: Luis Valente
//
// Represents a gpu program with a vertex/fragment program pair.
//
// ------------------------ */


// INCLUDES
#include "../inc/Program.h"
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

	Program::Program (const std::string & vertexProgramSourceFilename, const std::string & fragmentProgramSourceFilename)
	: mId             (glCreateProgram() ), 
	  mVertexShader   (GL_VERTEX_SHADER, vertexProgramSourceFilename),
	  mFragmentShader (GL_FRAGMENT_SHADER, fragmentProgramSourceFilename)
	{
		// attach shaders
		attachShader (mVertexShader);
		attachShader (mFragmentShader);
		
		// link
		link ();
	}

	// _________________________________________________________________________
	//
	// 

	Program::~Program()
	{
		// detach shaders
		detachShader (mFragmentShader);
		detachShader (mVertexShader);
		
		// delete gl program
		glDeleteProgram (mId);
	}
		  
		
	// _________________________________________________________________________
	//
	// 

	void Program::attachShader (Shader & s)
	{
		glAttachShader (mId, s.getId () );
	}

	// _________________________________________________________________________
	//
	// 

	void Program::detachShader (Shader & s)
	{
		glDetachShader (mId, s.getId () );
	}

	// _________________________________________________________________________
	//
	// 

	void Program::link ()
	{
		// link
		glLinkProgram (mId);
		
		// check errors
		if (getParam (GL_LINK_STATUS) != GL_TRUE)
		{
			// we got an error		
			Throw3 ("Program::link ", "Link failed", getInfoLog() );
		}
	}

	// _________________________________________________________________________
	//
	// 
			
	GLint Program::getParam (GLenum param) const
	{
		GLint p;	
		glGetProgramiv (mId, param, &p);	

		// debug
		ASSERT2 (glGetError() == GL_NO_ERROR, "Invalid param?");
		
		//
		return p;	
	}

	// _________________________________________________________________________
	//
	// 
			
	std::string Program::getInfoLog () const
	{
		// get info log size
		GLint logSize = getParam (GL_INFO_LOG_LENGTH);
		
		// reserve string for log
		scoped_array <GLchar> log (new char [logSize]);	
		
		// get log
		glGetProgramInfoLog (mId, logSize, 0, log.get());
		
		// 
		return string (log.get());
	}

	// _________________________________________________________________________
	//
	// 
			
	bool Program::validate () const
	{
		// do
		glValidateProgram (mId);
		
		// query
		return (getParam (GL_VALIDATE_STATUS) == GL_TRUE);	
	}



	} // end-namespace Ogl
} // end-namespace Gluff

