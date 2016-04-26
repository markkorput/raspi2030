//
//  renderer.cpp
//  emptyExample
//
//  Created by Mark van de Korput on 16-04-19.
//
//

#include "ofMain.h"
#include "renderer.hpp"

using namespace of2030;
using namespace of2030::effects;

Renderer* Renderer::singleton = NULL;

Renderer* Renderer::instance(){
    if (!singleton){   // Only allow one instance of class to be generated.
        singleton = new Renderer();
    }
    return singleton;
}

Renderer::Renderer(){
    fbo = NULL;
    player = NULL;
    client_info = NULL;
    m_bPrivateFbo = false;
    m_bRegistered = false;
}

Renderer::~Renderer(){
    destroy();
}

void Renderer::setup(){
    if(fbo == NULL){
        fbo = new ofFbo();
        m_bPrivateFbo = true;
    }

    if(!fbo->isAllocated()){
        fbo->allocate(WIDTH, HEIGHT);
    }

    if(!player){
        player = Player::instance();
    }

    if(!client_info){
        client_info = ClientInfo::instance();
    }

    registerRealtimeEffectCallback();
}

void Renderer::destroy(){
    if(m_bRegistered)
      registerRealtimeEffectCallback(false);

    if(fbo && m_bPrivateFbo){
        delete fbo;
        fbo = NULL;
        m_bPrivateFbo = false;
    }
}

void Renderer::draw(){
    fbo->begin();

    int size = player->active_effects.size();
    // ofLogVerbose() << "[Renderer] active effects: " << size;

    Context context;
    context.time = player->getTime();
    context.client_id = client_info->id;
    context.client_index = client_info->index;
    context.client_count = client_info->count;

    context.fbo = fbo;

    for(int i=0; i<size; i++){
        Effect* effect = player->active_effects[i];
        effect->draw(context);
    }

    fbo->end();
    fbo->draw(0,0);
}

void Renderer::registerRealtimeEffectCallback(bool reg){
    if(reg){
        ofAddListener(player->realtime_composition.newEffectEvent, this, &Renderer::onRealtimeEffect);
        m_bRegistered = true;
    } else {
        ofRemoveListener(player->realtime_composition.newEffectEvent, this, &Renderer::onRealtimeEffect);
        m_bRegistered = false;
    }
}

void Renderer::onRealtimeEffect(Effect &effect){
    Context context;
    context.time = player->getTime();
    context.client_id = client_info->id;
    context.client_index = client_info->index;
    context.client_count = client_info->count;
    context.fbo = fbo;
    effect.setup(context);
}
