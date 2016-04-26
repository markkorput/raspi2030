//
//  client_info.h
//  emptyExample
//
//  Created by Mark van de Korput on 16-04-25.
//
//

#ifndef client_info_h
#define client_info_h

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
#endif /* client_info_h */
