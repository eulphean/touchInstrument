#include "Osc.h"

void Osc::setup() {
  // Setup OSC.
  receive.setup(PORT);
  
  // Setup Audio Player.
  audioPlayer.addSample("/Users/amaykataria/Documents/of_v20170714_osx_release/apps/TouchInstrument/ParabolicSound/bin/data/1.wav");
}

void Osc::update() {
    // Touch OSC updates.
  while (receive.hasWaitingMessages()) {
    ofxOscMessage m;
    // Set the next message.
    #pragma warning(disable: WARNING_CODE)
    receive.getNextMessage(&m);
    
    processAudioSignals(m);
    processOscillatorSignals(m);
  }
}

void Osc::processAudioSignals(ofxOscMessage &m){
    // Play/pause a sample.
    if (m.getAddress() == "/Audio/playpause") {
      int val = m.getArgAsInt(0);
      if (val) {
        audioPlayer.play();
      } else {
        audioPlayer.pause();
      }
    }
  
    if (m.getAddress() == "/Audio/delay") {
      int val = m.getArgAsInt(0);
      if (val) {
        audioPlayer.addAudioEffect(sDelay);
      } else {
        audioPlayer.removeAudioEffect(sDelay);
      }
    }
  
    if (m.getAddress() == "/Audio/pitch") {
      int val = m.getArgAsInt(0);
      if (val) {
        audioPlayer.addAudioEffect(sPitch);
      } else {
        audioPlayer.removeAudioEffect(sPitch);
      }
    }
  
    if (m.getAddress() == "/Audio/decimation") {
      int val = m.getArgAsInt(0);
      if (val) {
        audioPlayer.addAudioEffect(sDecimation);
      } else {
        audioPlayer.removeAudioEffect(sDecimation);
      }
    }
  
    // Rotary knob float values. 
    if (m.getAddress() == "/Audio/gain") {
      float val = m.getArgAsFloat(0);
      audioPlayer.setAudioSampleGain(val);
    }
}

void Osc::processOscillatorSignals(ofxOscMessage &m) {
  if (m.getAddress() == "/Oscillator/sine") {
    int val = m.getArgAsInt(0);
    if (val) {
      audioPlayer.startOscillator(sine);
    } else {
      audioPlayer.stopOscillator(sine);
    }
  }
  
  if (m.getAddress() == "/Oscillator/square") {
    int val = m.getArgAsInt(0);
    if (val) {
      audioPlayer.startOscillator(square);
    } else {
      audioPlayer.stopOscillator(square);
    }
  }

  if (m.getAddress() == "/Oscillator/triangle") {
    int val = m.getArgAsInt(0);
    if (val) {
      audioPlayer.startOscillator(triangle);
    } else {
      audioPlayer.stopOscillator(triangle);
    }
  }

  if (m.getAddress() == "/Oscillator/effect/pitch") {
    // Change pitch.
  }

  if (m.getAddress() == "/Oscillator/effect/delay") {
    // Change delay.
  }
  
  // Rotary knob. Float values
  if (m.getAddress() == "/Oscillator/gain") {
    float val = m.getArgAsFloat(0);
    audioPlayer.setOscillatorGain(val);
  }
}
