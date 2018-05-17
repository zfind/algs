#include <iostream>
#include "RedBlackBSTDict.h"
using namespace std;


int main() {

    int N;
    cin >> N;

    RedBlackBSTDict<char, int> dict;

    char k;
    for (int i=0; i<N; i++) {
        cin >> k;
        dict.put(k, i);
    }

    dict.print();

    cout << "size:\t" << dict.size() << endl;


    return 0;
}
