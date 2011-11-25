#ifndef MSERVER_HPP
#define MSERVER_HPP

#endif // MSERVER_HPP

#include <string>

class MServer {
public:
    int id;
    std::string name;
    std::string desc;
    std::string path;
    int port;
    bool running;
    bool locked;
private:

};
