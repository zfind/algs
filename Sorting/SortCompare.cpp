#define COUNT_STATS

#include <iostream>
#include <cstring>
#include "Selection.h"
#include "Insertion.h"
#include "Shell.h"
#include "Merge.h"
#include "Quick.h"
#include "Heap.h"
using namespace std;


int main() {
    int N;
    std::cin >> N;

    int a_bak[N];
    for (int i = 0; i < N; i++) {
        std::cin >> a_bak[i];
    }

    int a[N];


    memcpy(a, a_bak, N*sizeof(int));
    Selection::sort(a, N);
    cout << "Selection compares:\t" << Merge::getCompareCount() << endl;
    cout << "Selection exchanges:\t" << Merge::getExchangeCount() << endl;


    memcpy(a, a_bak, N*sizeof(int));
    Insertion::sort(a, N);
    cout << "Insertion compares:\t" << Merge::getCompareCount() << endl;
    cout << "Insertion exchanges:\t" << Merge::getExchangeCount() << endl;


    memcpy(a, a_bak, N*sizeof(int));
    Shell::sort(a, N);
    cout << "Shellsort compares:\t" << Merge::getCompareCount() << endl;
    cout << "Shellsort exchanges:\t" << Merge::getExchangeCount() << endl;

    
    memcpy(a, a_bak, N*sizeof(int));
    Merge::sort(a, N);
    // printArray(a, N);
    cout << "Mergesort compares:\t" << Merge::getCompareCount() << endl;
    cout << "Mergesort exchanges:\t" << Merge::getExchangeCount() << endl;


    memcpy(a, a_bak, N*sizeof(int));
    Quick::sort(a, N);
    cout << "Quicksort compares:\t" << Merge::getCompareCount() << endl;
    cout << "Quicksort exchanges:\t" << Merge::getExchangeCount() << endl;


    memcpy(a, a_bak, N*sizeof(int));
    Heap::sort(a, N);
    cout << "Heapsort compares:\t" << Heap::getCompareCount() << endl;
    cout << "Heapsort exchanges:\t" << Heap::getExchangeCount() << endl;


    return 0;
}