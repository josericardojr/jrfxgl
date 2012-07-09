/*
 * JRFXGL_API.h
 *
 *  Created on: 23/07/2011
 *      Author: josericardo
 */

#ifndef JRFXGL_API_H_
#define JRFXGL_API_H_

#ifdef CUDA
	#include <host_defines.h>
	#define JRFXGL_API __host__ __device__
	#define JRFXGL_API_INLINE JRFXGL_API inline
#else
	#define JRFXGL_API
	#define JRFXGL_API_INLINE
#endif

#ifdef WIN32
	#include <Windows.h>
	#ifdef max
		#undef max
	#endif
	#ifdef min
		#undef min
	#endif
#endif


#endif /* JRFXGL_API_H_ */
