//
//  effect.cpp
//  emptyExample
//
//  Created by Mark van de Korput on 16-04-19.
//
//

#include "effects.hpp"
#include "shader_manager.hpp"
#include "video_manager.hpp"


using namespace of2030::effects;

int Effect::cidCounter = 0;

Effect::Effect() : startTime(NO_TIME), endTime(NO_TIME), type(EffectType::OFF) {
    // every effect instance gets a unique cid (client-side-id)
    cid = cidCounter;
    cidCounter++;
}

void Effect::setup(Context &context){
  // make sure the effect has a start time;
  // if it didn't get a startTime from the creator,
  // simple take the current time from the context
  if(!hasStartTime()){
      startTime = context.time;
  }

  // try to calculate endTime from startTime and duration
  // if endTime wasn't specified
  if(hasDuration() && hasStartTime() && !hasEndTime()){
      endTime = startTime + duration;
  }
}

void Effect::draw(Context &context){
    // ofBackground(effect.color);
}

float Effect::getDuration(){
    if(hasDuration())
        return duration;

    if(hasStartTime() and hasEndTime())
        return endTime - startTime;

    return -1.0;
}


Off::Off(){
  type = EffectType::OFF;
}

void Off::draw(Context &context){
    ofBackground(0);
}




Color::Color(){
    type = EffectType::COLOR;
    color = ofColor::black;
}

void Color::draw(Context &context){
    ofBackground(color);
}




Cursor::Cursor(){
    type = EffectType::CURSOR;
    duration = 3.0;
}

void Cursor::draw(Context &context){
    int idx = context.client_index;
    int client_count = context.client_count;

    float duration = getDuration();
    float effectTime = context.time - startTime;
    float localDuration = duration / client_count;
    float localStart = localDuration * idx;

    if(effectTime < localStart)
    // nothing for us to do (yet)
    return;

    float localEffectTime = effectTime - localStart;

    if(localEffectTime > localDuration)
    // our part is done
    return;

    float localProgress = localEffectTime / localDuration;

    ofSetColor(255);
    ofDrawRectangle(localProgress * context.fbo->getWidth(),
                    0,
                    3,
                    context.fbo->getHeight());
}


Stars::Stars(){
    type = EffectType::STARS;
    duration = 3.0;
}

void Stars::setup(Context &context){
    Effect::setup(context);
    shader = ShaderManager::instance()->get("Starfield01");
}

void Stars::draw(Context &context){
    float progress = ofMap(context.time, startTime, endTime, 250.0f, -50.0f);
    float treshold = ofMap(context.time, startTime, endTime, 0.99999f, 0.96f);

    ofSetColor(255);
    shader->begin();
    shader->setUniform2f("iPos", ofVec2f(0.0f, progress));
    shader->setUniform1f("iThreshold", treshold);
    ofDrawRectangle(0, 0, context.fbo->getWidth(), context.fbo->getHeight());
    shader->end();
}



Vid::Vid(){
    type = EffectType::VID;
    duration = 3.0f;
}

void Vid::setup(Context &context){
    Effect::setup(context);
    video_player = VideoManager::instance()->get("fingers.mov", true);
    // video_player->setLoopState(OF_LOOP_NORMAL);
    // TODO; loop? when to stop loop?
    // notify manager when done?
    video_player->play();
}

void Vid::draw(Context &context){
    video_player->update();
    video_player->draw(0,0);
}
