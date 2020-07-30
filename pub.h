#include <iostream>
#include <thread>


using namespace std;

#include <mutex>

class Pub 
{
  static mutex cout_mutex;
public:
    Pub() {
    lock_guard<mutex> guard(cout_mutex);
        cout << "Pub() : Tid = " << this_thread::get_id() << endl;
    }
    ~Pub() {
        lock_guard<mutex> guard(cout_mutex);
        cout << "~Pub() : Tid = " << this_thread::get_id() << endl;
    }
    void do_(int val) 
    {
        lock_guard<mutex> guard(cout_mutex);
        cout << "do(val) " << val << " : Tid = " << this_thread::get_id() << endl;
    }
};