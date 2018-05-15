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

    char floorOfQ;
    if (dict.floor('Q', floorOfQ)) {
        cout << "floor of 'Q':\t" << floorOfQ << endl;
    }

    char selectIdx7;
    if (dict.select(7, selectIdx7)) {
        cout << "idx 7:\t" << selectIdx7 << endl;
    }

    int rankOfR = dict.rank('R');
    cout << "rank R:\t" << rankOfR << endl;

    dict.removeMin();

    dict.remove('P');
    dict.remove('Q');
    dict.remove('R');
    dict.print();


    return 0;
}
