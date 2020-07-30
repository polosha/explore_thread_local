#include <thread>
#include <iostream>

#include "pub.h"

extern thread_local Pub g_pub;

using namespace std;

void stuff1()
{
    thread t([](){
        cout << "doing stuff()" << endl;
        g_pub.do_(135);
        });

    t.join();
}