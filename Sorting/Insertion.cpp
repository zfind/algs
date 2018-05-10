#include <iostream>
#include <cassert>
#include "SortCommon.h"


class Insertion : public SortingAlgorithm {
public:
    template<typename Item>
    static void sort(Item a[], int N) {
        for (int i=1; i<N; i++) {
            for (int j=i; j>0 && less(a[j], a[j-1]); j--) {
                exch(a, j, j-1);
            }
        }

        assert(isSorted(a, N));
    }
};


int main() {
    int N;
    std::cin >> N;

    int a[N];
    for (int i=0; i<N; i++) {
        std::cin >> a[i];
    }

    Insertion::sort(a, N);

    //printArray(a, N);

    return 0;
}