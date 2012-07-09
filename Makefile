

MACHINE= $(shell uname -s)

ifeq ($(MACHINE),Darwin)
    OPENGL_INC= 
    #OPENGL_LIB= -framework OpenGL
    SDL_INC= -I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE
    SDL_LIB= -L/opt/local/lib -lSDLmain -lSDL_image -lSDL -framework Cocoa
else
    OPENGL_INC= -I/usr/X11R6/include
    OPENGL_LIB= -I/usr/lib64 -lGL -lGLU
    SDL_INC= `sdl-config --cflags`
    SDL_LIB= `sdl-config --libs`
endif


#CUDPP_INC = -I/Users/josericardo/HGRepo/Projetos/cudpp/release1.1/cudpp/include
#CUDPP_LIB = -L/Users/josericardo/HGRepo/Projetos/cudpp/lib -lcudpp
    
PROJECTDIR   := $(CURDIR)
ROOTDIR		 := /Developer/GPU\ Computing
CUDA_SDK_DIR := $(ROOTDIR)/C

SRCDIR     := $(PROJECTDIR)
ROOTBINDIR := $(PROJECTDIR)
BINDIR     := $(PROJECTDIR)
ROOTOBJDIR := $(ROOTBINDIR)
LIBDIR     := $(CUDA_SDK_DIR)/lib
COMMONDIR  := $(CUDA_SDK_DIR)/common
SHAREDDIR  := $(ROOTDIR)/shared
CUDPPDIR   := $(COMMONDIR)/inc/cudpp


INCLUDES :=   $(OPENGL_INC) $(SDL_INC) -I/opt/local/include -Iinc -I/opt/local/include/freetype2
LIB :=  $(OPENGL_LIB) $(SDL_LIB) -lGLEW -lGL -lfreeimage -lfreetype -lftgl 


USECUDPP = 0

verbose=0

USEGLLIB=1
USEGLUT=1
x86_64=1
#dbg=1

# add command line parameters so we can target multiple architectures
GENCODE_SM10 := -gencode=arch=compute_10,code=\"sm_10,compute_10\"
GENCODE_SM11 := -gencode=arch=compute_11,code=\"sm_11,compute_11\"
GENCODE_SM12 := -gencode=arch=compute_12,code=\"sm_12,compute_12\"
GENCODE_SM20 := -gencode=arch=compute_20,code=\"sm_20,compute_20\"

GENCODE_ARCH    := $(GENCODE_SM12)

#NVCCFLAGS := -D__RECURSION_GPU__
#NVCCFLAGS := --dryrun
#NVCCFLAGS += -DCUDA -DNVCC -D_CUDA -D__CUDA__ -D__APPLE__
#CXXFLAGS := -D__APPLE__
CXXFLAGS += -c -Wall -shared -L/Users/josericardo/Projects/Eclipse/JRFXGL -m64 -fPIC
LINKFLAGS = -shared -m64
DYLINKFLAGS = 

# Add source files here
EXECUTABLE	:= libJRFXGL.so

# CUDA source files (compiled with cudacc)
CUFILES		:= 	

# CUDA dependency files
CU_DEPS		:= 

# C/C++ source files (compiled with gcc / g++)
CCFILES	 := Core/src/AppRunner.cpp \
            Graphics/src/ObjModel.cpp \
            Graphics/src/ObjModelLoader.cpp \
            Graphics/src/PerspectiveProjection.cpp \
            Graphics/src/PerspectiveCamera.cpp \
            Graphics/src/FreeCamera.cpp \
            Graphics/src/Texture.cpp \
            Graphics/src/FPSCameraController.cpp \
            Graphics/src/framebufferObject.cpp \
            Graphics/src/GUIManager.cpp \
            Graphics/src/Node.cpp \
            Graphics/src/Image.cpp \
            Graphics/src/GLBuffer.cpp \
            Graphics/src/GLVertexBuffer.cpp \
            Graphics/src/Shader.cpp \
            Graphics/src/Program.cpp \
	    Graphics/src/Primitives.cpp \
            Devices/src/Devices.cpp \
            Util/src/LogManager.cpp \
            Util/src/Clock.cpp \
            Util/src/StopWatch.cpp \
            Util/src/FrameCounter.cpp \
            Util/src/FileSystem.cpp
		    
	

################################################################################
# Rules and targets	

include common_custom.mk

	
	
