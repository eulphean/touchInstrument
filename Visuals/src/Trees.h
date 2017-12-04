#pragma once

#include "ofMain.h"

class Trees {
  public:
    void setup();
    void update();
    void draw();
    void drawMesh();
    void resetMaskPosition();
  
    ofImage img;
    ofMesh mesh;
    glm::vec2 center;
  
    ofFbo drawFbo;
    ofFbo maskFbo;
  
    int maskY;
    const int endTimeForMask = 120; // 60 seconds.
};

