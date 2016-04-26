//
//  effect.h
//  emptyExample
//
//  Created by Mark van de Korput on 16-04-19.
//
//

#ifndef effect_h
#define effect_h

#include "ofMain.h"

namespace of2030{ namespace effects {

    typedef struct {
        float time;
        int client_id;
        int client_index;
        int client_count;
        ofFbo* fbo;
    } Context;

    enum EffectType{
        OFF = 0,
        COLOR = 1,
        CURSOR = 2
    };

    #define NO_TIME (-1.0f)



    class Effect{

    public: // methods

        Effect();
        // ~Effect(){}

        virtual void setup(Context &context);
        virtual void draw(Context &context);

        bool hasStartTime(){ return startTime >= 0.0f; }
        bool hasEndTime(){ return endTime >= 0.0f; }
        bool hasDuration(){ return duration >= 0.0f; }
        float getDuration();

    public: // properties

        int cid;
        float startTime, endTime, duration;
        EffectType type;

        static int cidCounter;
    };



    class Off : public Effect{

    public: // methods

        Off(){ type = EffectType::OFF; }
        virtual void setup(Context &context);
        virtual void draw(Context &context);
    };



    class Color : public Effect{

    public: // methods
        Color();
        virtual void setup(Context &context);
        virtual void draw(Context &context);

    public: // attributes
        ofColor color;
    };


    class Cursor : public Effect{

    public: // methods
        Cursor();
        virtual void setup(Context &context);
        virtual void draw(Context &context);

    };

}} // namespace of2030{ namespace effects {

#endif /* effect_h */
