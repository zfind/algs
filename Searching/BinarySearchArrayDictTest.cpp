#include <iostream>
#include "BinarySearchArrayDict.h"
using namespace std;


int main() {

    int N;
    cin >> N;

    BinarySearchArrayDict<char, int> dict{N};

    char k;
    for (int i=0; i<N; i++) {
        cin >> k;
        dict.put(k, i);
    }

    dict.print();


    return 0;
}
