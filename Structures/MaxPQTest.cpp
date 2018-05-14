#include <iostream>
#include "MaxPQ.h"
using namespace std;


int main(int argc, char const *argv[]) {
    MaxPQ<char> pq{};
    
    char out;

    pq.insert('P');
    pq.insert('Q');
    pq.insert('E');
    cout << pq.remove() << endl;
    pq.insert('X');
    pq.insert('A');
    pq.insert('M');
    cout << pq.remove() << endl;
    pq.insert('P');
    pq.insert('L');
    pq.insert('E');
    cout << pq.remove() << endl;

    cout << "rest:\t";
    while (!pq.isEmpty()) {
        cout << pq.remove() << " ";
    }
    cout << endl;

    return 0;
}
