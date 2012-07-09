//
//  Primitives.cpp
//  JRFXGL
//
//  Created by Jose Ricardo da Silva Junior on 17/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "../inc/Primitives.h"

namespace JRFXGL {
    namespace Graphics {
        
        void Geometry::DrawWireBox(mc::math::Vec3f pos, mc::math::Vec3f extends, mc::math::Vec3f color){
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glBegin(GL_QUADS);
            mc::math::Vec3f middle(extends.x / 2.0f, extends.y / 2.0f, extends.z / 2.0f);
            
            glColor3f(color.x, color.y, color.z);               /*      This is the top face*/
            glVertex3f(middle.x, middle.y, middle.z);
            glVertex3f(middle.x, middle.y, -middle.z);
            glVertex3f(-middle.x, middle.y, -middle.z);
            glVertex3f(-middle.x, middle.y, middle.z);
            
            /*      This is the front face*/
            glVertex3f(middle.x, middle.y, middle.z);
            glVertex3f(-middle.x, middle.y, middle.z);
            glVertex3f(-middle.x, -middle.y, middle.z);
            glVertex3f(middle.x, -middle.y, middle.z);
            
            /*      This is the right face*/
            glVertex3f(middle.x, middle.y, middle.z);
            glVertex3f(middle.x, -middle.y, middle.z);
            glVertex3f(middle.x, -middle.y, -middle.z);
            glVertex3f(middle.x, middle.y, -middle.z);
            
            /*      This is the left face*/
            glVertex3f(-middle.x, middle.y, middle.z);
            glVertex3f(-middle.x, middle.y, -middle.z);
            glVertex3f(-middle.x, -middle.y, -middle.z);
            glVertex3f(-middle.x, -middle.y, middle.z);
            
            /*      This is the bottom face*/
            glVertex3f(middle.x, -middle.y, middle.z);
            glVertex3f(-middle.x, -middle.y, middle.z);
            glVertex3f(-middle.x, -middle.y, -middle.z);
            glVertex3f(middle.x, -middle.y, -middle.z);
            
            /*      This is the back face*/
            glVertex3f(middle.x, middle.y, -middle.z);
            glVertex3f(middle.x, -middle.y, -middle.z);
            glVertex3f(-middle.x, -middle.y, -middle.z);
            glVertex3f(-middle.x, -middle.y, -middle.z);            
            glEnd();
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
    }
}