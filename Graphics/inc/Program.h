//---------------------------------------------------------------------------
#ifndef _PROGRAM_H_
#define _PROGRAM_H_
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// Program
//
// Author: Luis Valente
//
// GLSL GPU programs.
//
// ------------------------ */


// INCLUDES
#include <string>
#include <boost/shared_ptr.hpp>
#include <GL/glew.h>
#include "../../Math/inc/mcMath.h"
#include "Shader.h"
#include "../../Util/inc/Error.h"

namespace JRFXGL
{
	namespace Graphics
	{

	// CLASSES
	   
	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Program
	//
	//  Descrição:
	//     - Represents a gpu program with a vertex/fragment program pair.
	//
	//
	class Program
	{
		public:
	  
			// main constructor, gets the filename for the vp and fp
			Program (const std::string & vertexProgramSourceFilename, const std::string & fragmentProgramSourceFilename);

			// destructor
			~Program();
		  
		public:
			// disable this program
			void disable() const
			  { glUseProgram(0); }

			// uses this program
			void use () const
			 { glUseProgram (mId); }
			 
			// gets a program parameter
			GLint getParam (GLenum param) const;
			
			// gets the info log
			std::string getInfoLog () const;		
			
			// validates the program
			bool validate () const;

		public:

			// binds an attribute to a name
			void bindAttribLocation (GLuint index, const GLchar *name) const
			 { ASSERT1 (name != 0); glBindAttribLocation (mId, index, name); }

			// gets the location of an uniform
			GLint getUniformLocation (const GLchar* name) const
			 { ASSERT1 (name != 0); return glGetUniformLocation (mId, name); }

			// gets the location of an attribute
			GLint getAttribLocation (const GLchar* name) const
			 { ASSERT1 (name != 0); return glGetAttribLocation (mId, name); }

	 
			//
			void setUniform (const GLchar* name, GLint v1)
			 { glUniform1i (getUniformLocation (name), v1); }
			 
			//
			void setUniform (const GLchar* name, GLint v1, GLint v2)
			 { glUniform2i (getUniformLocation (name), v1, v2); }
			 
			//
			void setUniform (const GLchar* name, GLint v1, GLint v2, GLint v3)
			 { glUniform3i (getUniformLocation (name), v1, v2, v3); }
			 
			//
			void setUniform (const GLchar* name, GLint v1, GLint v2, GLint v3, GLint v4)
			 { glUniform4i (getUniformLocation (name), v1, v2, v3, v4); }		 
			 
			//
			void setUniform (const GLchar* name, GLfloat v1)
			 { glUniform1f (getUniformLocation (name), v1); }
			 
			//
			void setUniform (const GLchar* name, GLfloat v1, GLfloat v2)
			 { glUniform2f (getUniformLocation (name), v1, v2); }		 
			 
			//
			void setUniform (const GLchar* name, GLfloat v1, GLfloat v2, GLfloat v3)
			 { glUniform3f (getUniformLocation (name), v1, v2, v3); }
			 
			void setUniform (const GLchar* name, const mc::math::Vec3f& vec)
			{ glUniform3fv (getUniformLocation (name), 1, (float*) &vec); }

			//
			void setUniform (const GLchar* name, GLfloat v1, GLfloat v2, GLfloat v3, GLfloat v4)
			 { glUniform4f (getUniformLocation (name), v1, v2, v3, v4); }

			//
			//void setUniformMatrix( const GLchar* name, “Screen Space Fluid Rendering with Curvature FlowMath::Matrix4& mat)
			 //{ glUniformMatrix4f (getUnformLocation(name), reinterpret_cast<float*>(&mat)); }

		private:

			void attachShader (Shader & s);
			void detachShader (Shader & s);
			void link ();

		private:

			GLuint mId;

			Shader mVertexShader;
			Shader mFragmentShader;


		private:

	};


					

		  
				
				
	//---------------
	// TYPEDEFS
	//---------------

	typedef boost::shared_ptr <Program> ProgramPtr;



	} // end-namespace Ogl
} // end-namespace Gluff



//---------------------------------------------------------------------------
#endif



