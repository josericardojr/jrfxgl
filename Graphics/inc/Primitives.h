//
//  Primitives.h
//  JRFXGL
//
//  Created by Jose Ricardo da Silva Junior on 17/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef __GEOMETRY_H__

#define __GEOMETRY_H__

#include "Mesh.h"
#include "../../Math/inc/mcMath.h"
#include <GL/glew.h>

namespace JRFXGL {
    
    namespace Graphics {
        
        class Geometry {
            
        public:
            static void DrawWireBox(mc::math::Vec3f pos, mc::math::Vec3f extends, mc::math::Vec3f color);
        };
        
    }
    
}

#endif