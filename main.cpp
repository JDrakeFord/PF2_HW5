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
    return 0;
}
