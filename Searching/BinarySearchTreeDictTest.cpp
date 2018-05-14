#include <iostream>
#include "BinarySearchTreeDict.h"
using namespace std;


int main() {

    int N;
    cin >> N;

    BinarySearchTreeDict<char, int> dict;

    char k;
    for (int i=0; i<N; i++) {
        cin >> k;
        dict.put(k, i);
    }

    dict.print();

    return 0;
}
