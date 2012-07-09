//---------------------------------------------------------------------------
#ifndef _GUFF_OGL_LIGHT_H_
#define _GUFF_OGL_LIGHT_H_
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// Light
//
// Autor: Luis Valente
//
// Encapsulamento de fontes de luz
//
// ------------------------ */


//---------------
// INCLUDES
//---------------
#include <GL/glew.h>
#include "../../Math/inc/mcMath.h"


namespace JRFXGL
{
	namespace Graphics
	{


	//---------------
	// CLASSES
	//---------------

	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  LightSource
	//
	//  Descrição:
	//     - Representa uma fonte de luz.
	//
	//


		class LightSource 
		{    
			public:

			 GLenum              id;
			 mc::math::Vec4f     diffuseColor;
			 mc::math::Vec4f     ambientColor;
			 mc::math::Vec4f     specularColor;
			 

		 public:  
			 
			 virtual void apply () = 0;	 
			   
			public:
			 
			 void enable ()
				{ glEnable (id); }


			 void disable ()
				{ glDisable (id); }		
			 
				
			 void applyColors ()
				{
					glLightfv (id, GL_DIFFUSE,  diffuseColor.getArray());
					glLightfv (id, GL_AMBIENT,  ambientColor.getArray());
					glLightfv (id, GL_SPECULAR, specularColor.getArray());
				}				
				
			protected:		

				LightSource (GLenum identifier = GL_LIGHT0) : id(identifier),
					diffuseColor(mc::math::Vec4f(1.0f, 1.0f, 1.0f, 1.0f)),
					ambientColor(mc::math::Vec4f(0.2f, 0.2f, 0.2f, 1.0f)),
					specularColor(mc::math::Vec4f(0.0f, 0.0f, 0.0f, 1.0f))
				{
				}

		};


		/////////////////////////////////////////////////////////////////////////////////////
		//
		//  DirectionalLight
		//
		//  Descrição:
		//     - Representa uma fonte de luz direcional.
		//
		//
		class DirectionalLight : public LightSource
		{
			public:
		  
			mc::math::Vec3f direction;
			 
			public:
		  
				DirectionalLight (GLenum identifier = GL_LIGHT0) :
						LightSource(identifier)
						{
							direction = mc::math::Vec3f(0.0f, 0.0f, 1.0f);
						}

			public:
		  
		  
			 void apply ()
				{
					applyDirection ();
					applyColors ();		
				}
				
				
			 void applyDirection ()
				{
					glLightfv (id, GL_POSITION, mc::math::Vec4f(direction, 0.0f).getArray());
				}		
			 
		  

		};


		/////////////////////////////////////////////////////////////////////////////////////
		//
		//  PointLight
		//
		//  Descrição:
		//     - Representa uma fonte de luz pontual.
		//
		//
		class PointLight : public LightSource
		{
			public:
		  
			mc::math::Vec3f position;
			 
			public:
		  
			 PointLight (GLenum identifier = GL_LIGHT0);

			public:
		  
		  
			 void apply ()
				{
					applyPosition ();
					applyColors ();		
				}
				
				
			 void applyPosition ()
				{
					//glLightfv (id, GL_POSITION, (const float*) mc::math::Vec4f(position, 1.0f).getArray());
				} 
		  


		};


		/////////////////////////////////////////////////////////////////////////////////////
		//
		//  SpotLight
		//
		//  Descrição:
		//     - Representa uma fonte de luz spot.
		//
		//
		class SpotLight : public LightSource
		{
			public:
		  
			 mc::math::Vec3f position;
			 mc::math::Vec3f direction;
			 GLfloat         cutOffAngle;
		 
			 
			public:
		  
			 SpotLight (GLenum identifier = GL_LIGHT0);

			public:  
		  
			 void apply ()
				{
					applyPosition ();
					applySpot ();
					applyColors ();		
				}		
				
			 void applyPosition ()
				{
					glLightfv (id, GL_POSITION, mc::math::Vec4f(position, 1.0f).getArray());
				} 		
			
			 void applySpot ()
				{
					glLightfv (id, GL_SPOT_DIRECTION, direction.getArray());
					glLightf  (id, GL_SPOT_CUTOFF, cutOffAngle);
				}

			 
		};


	//---------------
	// FUNCTIONS
	//---------------

	// Builds a matrix for planar shadow projection
	//void BuildShadowMatrix (const Math::Plane & plane, const Math::Vector3 lightPosition, Math::Matrix4 & result);


	} // end-namespace Ogl
}


//---------------------------------------------------------------------------
#endif











