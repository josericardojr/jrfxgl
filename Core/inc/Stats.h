//
//  Stats.h
//  JRFXGL
//
//  Created by Jose Ricardo da Silva Junior on 09/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef __STATS_H__

#define __STATS_H__

#include <sstream>
#include "../../Graphics/inc/GUIManager.h"

namespace JRFXGL {
    
    namespace App {
        
        class Stats {
            
        public:
            Stats() {
            }
            
            void update(int fps) {
                mFPS.str("");
                mFPS << "FPS: " << fps;
                
                mFrameTime.str("");
                mFrameTime << "Frame in sec: " << 1.0f / fps;
                
            }
            
            void show() {  
                JRFXGL::Graphics::GUIManager::instance()->label(mFPS.str(), 10, 500);
                JRFXGL::Graphics::GUIManager::instance()->label(mFrameTime.str(), 10, 600);
            }
            
        private:
            std::stringstream mFrameTime;
            std::stringstream mFPS;
        };
    }
}

#endif