//---------------------------------------------------------------------------
#ifndef __ERROR_H__
#define __ERROR_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// Error
//
// Autor: Luis Valente
//
// Tratamento de erros
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include <cassert>
#include <string>
#include <stdexcept>

namespace JRFXGL
{
	namespace Error
	{

	//---------------
	// MACROS
	//---------------


	// Macros de conveniencia para assert
	#define ASSERT1(expr) assert (expr)

	// Macros de conveniencia para assert
	#define ASSERT2(expr, msg) assert (expr && msg)

	// Macros de conveniencia para assert
	#define ASSERT3(expr, msg1, msg2) assert (expr && msg1 && msg2)

	// Outra macro de conveniência para assert
	#define BREAK_HERE1(msg) assert (!msg)

	// Outra macro de conveniência para assert
	#define BREAK_HERE2(func, msg) assert (!func && msg)

	// Outra macro de conveniência para assert
	#define BREAK_HERE3(func, msg1, msg2) assert (!func && msg1 && msg2)


	// Gerar uma exceção simples
	#define Throw1(msg) { \
		 using namespace std; \
		 string realMsg = string ("[Exception] ") + msg; \
		 throw Error::Exception (realMsg,__FILE__,__LINE__); \
	  } 
	  

	// Gerar exceção, com opção de se especificar um nome de função
	// onde o erro aconteceu
	#define Throw2(funcName, msg) { \
		 using namespace std; \
		 string header = "["#funcName"] " ; \
		 string realMsg = header + msg ; \
		 throw JRFXGL::Error::Exception (realMsg,__FILE__,__LINE__); \
	  }
	  
	// Gerar exceção, com opção de se especificar um nome de função
	// onde o erro aconteceu
	#define Throw3(funcName, msg, param1) { \
		 using namespace std; \
		 string header = "["#funcName"] " ; \
		 string realMsg = header; \
				realMsg += msg; \
				realMsg += "\n"; \
				realMsg += param1; \
		 throw Error::Exception (realMsg,__FILE__,__LINE__); \
	  }
			
			
	// Gerar exceção, com opção de se especificar um nome de função
	// onde o erro aconteceu
	#define Throw4(funcName, msg, param1, param2) { \
		 using namespace std; \
		 string header = "["#funcName"] " ; \
		 string realMsg = header; \
				realMsg += msg; \
				realMsg += "\n"; \
				realMsg += param1; \
				realMsg += param2; \
		 throw Error::Exception (realMsg,__FILE__,__LINE__); \
	  }
			
			


	//---------------
	// CLASSES
	//---------------

	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Exception
	//
	//  Descrição:
	//     - Classe base para as exceções do framework. 
	//
	//

	struct Exception : public std::runtime_error
	{
	  Exception (const std::string & msg, const std::string & filename, int line)
	   : std::runtime_error (msg.c_str ()), 
		 mMessage           (msg)
	  {}
	  
	  virtual ~Exception () throw ()
	   {}
	  
	  virtual const char * what () const throw()
	   { return mMessage.c_str (); }  

	  const std::string & getMessage () const
		 { return mMessage; }
		 
	  const std::string & getFilename () const
		 { return mFilename; }
		 
	  int getLine () const
		 { return mLine; }


	  private:     
		 std::string mMessage;
		 std::string mFilename;
		 int         mLine;
	 
	};


	} // end-namespace Error
} // end-namespace Gluff

//---------------------------------------------------------------------------
#endif

