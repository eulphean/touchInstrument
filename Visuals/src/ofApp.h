#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxProcessFFT.h"
#include "ofxKsmrFragmentFx.h"
#include "Stripes.h"
#include "Trees.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
    void setupFbos();
    void updateFbos();
    void drawNoiseFbo();
  
    // Master mixer.
    ofxPanel gui;
    ofxGuiGroup mixer;
    ofxFloatSlider treesAlpha, stripesAlpha, noiseAlpha;
  
    // Stripes mixer.
    ofxGuiGroup stripeMixer;
    ofxFloatSlider offset, rotation, blend;
  
    // Effects mixer.
    ofxGuiGroup noiseGroup;
    ofxFloatSlider noiseVolume;
    
    // -------- Visuals -----------
  
    // Stripes.
    Stripes stripeModule;
    // Trees.
    Trees treeModule;
  
    // FBOs
    ofFbo::Settings settings;
    ofFbo stripeFbo;
    ofFbo treeFbo;
    ofFbo emptyNoiseFbo;
  
    // Noise FX
    ofxKsmrFragmentFx noiseFx;
  
    // KSMR
    //ofFbo original;
    //ofxKsmrFragmentFx	fx;
};
