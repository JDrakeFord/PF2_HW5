#include <iostream>
#include "Linkedlist.h"

using namespace std;
int main() {
    Linkedlist a(20);
    a.check();
    Linkedlist b;
    b = a;
    b.rcheck();
    return 0;
}
