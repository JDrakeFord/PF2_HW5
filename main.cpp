#include <iostream>
#include "Linkedlist.h"

using namespace std;



int main() {
    Linkedlist a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    a.push_back(1);
    a.push_back(25);
    a.push_back(13);
    a.push_back(9);
    a.push_back(940);
    a.push_back(256);
    a.check();
    a.sort();
    a.check();
    cout << a.back() << endl;
    a.pop_back();
    cout << a.back() << endl;
    cout << a.front() << endl;
    a.pop_front();
    cout << a.front() << endl;
    a.push_back(3);
    cout << a.back() << endl;
    a.push_front(3);
    cout << a.front() << endl ;
    Linkedlist b(20);
    b.check();
    if(b.empty())
        cout << "B is empty!" << endl;
    else
        cout << "B isn't empty!" << endl;
    b.clear();
    if(b.empty())
        cout << "B is empty!" << endl;
    else
        cout << "B isn't empty!" << endl;
    a.check();
    b.check();
    b = a;
    b.check();
    return 0;

}
