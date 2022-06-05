#include <iostream>
#include "List.h"


using namespace std;

//example

void printInfo(list::List<int> &list)
{
    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i] << " | ";
    }
    cout << endl;
}

int main() {

    list::List<int> test;

    test.pushBack(39);
    cout << test.getSize() << endl;

    test.insert(29,0);

    printInfo(test);

    test.pushFront(100);

    printInfo(test);

    test.delFirst();

    printInfo(test);

    test.delLast();

    printInfo(test);

    test.pushBack(2);
    test.pushBack(3);
    test.pushBack(4);

    printInfo(test);

    test.removeAt(test.getSize() - 1);

    printInfo(test);
    cout << endl;
    test.clearList();
    cout << test.getSize() << endl;

    return 0;
}

//output

/*  |   1                   |
    |   29 | 39 |           |
    |   100 | 29 | 39 |     |
    |   29 | 39 |           |
    |   29 |                |
    |   29 | 2 | 3 | 4 |    |
    |   29 | 2 | 3 |        |
    |   0                   |        */

