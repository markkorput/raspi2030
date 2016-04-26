//
//  client_info.hpp
//  emptyExample
//
//  Created by Mark van de Korput on 16-04-25.
//
//

#ifndef client_info_hpp
#define client_info_hpp

namespace of2030{
    class ClientInfo {

    public:
        static ClientInfo* instance();
    private:
        static ClientInfo* singleton;

    public:
        ClientInfo();
        // ~ClientInfo();

    public:
        int id, index, count;
    };
}
#endif /* client_info_hpp */
