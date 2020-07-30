// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>

#include <vector>
#include <stdio.h>
#include <future>

#include "pub.h"
/// #include "..\libEarcut\libearcut.h"

using namespace std;


void stuff1();




void doStaticStuff(int id)
{
    static  Pub pb;    
    pb.do_(id);
}

thread_local Pub g_pub;

void dothread_localStuff(int id)
{
    g_pub.do_(id);
}

template <class T>
void joinAll(T& cont) {
for (auto& t : cont) {
t.join();
}
}

int main()
{
    stuff1();
    
    std::vector<thread> threads; 
    cout << "Starting doStaticStuff" << endl;
    for (int i =0 ;i < 4; ++i) {
    threads.emplace_back(&doStaticStuff, i);
    }
    joinAll(threads);
    cout << "Finished doStaticStuff" << endl;

    threads.clear();
    

    cout << "Push enter" << endl;
    getchar();

    cout << "Starting dothread_localStuff" << endl;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(&dothread_localStuff, i);
    }
    joinAll(threads);
    cout << "Finished dothread_localStuff" << endl;

//    std::vector<future<void>> asyncs;
//    for (int i =0; i < 4; ++i)
//    {
//    std::async(&doStaticStuff())
//    }

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
