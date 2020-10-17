/*
From:ITC
14
Object orientedness defects
14.6
Unused private function
14.6.1
unused private function errors
*/
#include<iostream>
using namespace std;
class Server {
public:
    void start() { // Compliant, the member function "start()" is public
        log("start");
    }
private:
    void clear() { // Noncompliant, the member function ""clear()"" is unused  /*Tool should detect this line as error*/ /*ERROR:Object orientedness error*/
    }
    void log(const char* msg) { // Compliant, the member function ""log()"" is used in ""start() { ... }""
        printf(msg);
    }
};
