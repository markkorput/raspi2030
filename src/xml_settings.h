//
//  xml_settings.hpp
//  emptyExample
//
//  Created by Mark van de Korput on 16-04-25.
//
//

#ifndef xml_settings_hpp
#define xml_settings_hpp

#include "ofMain.h"

namespace of2030{

    class XmlSettings{
  
    public:
        static XmlSettings* instance();
    private:
        static XmlSettings* singleton;

    public:
        XmlSettings();

        void load();
        void save();

        std::string path;
        int osc_port,
            client_id,
            screen_width,
            screen_height;
    };
}

#endif /* xml_settings_hpp */
