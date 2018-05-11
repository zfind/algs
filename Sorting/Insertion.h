#ifndef INSERTION_H
#define INSERTION_H


#include <iostream>
#include <cassert>
#include "SortCommon.h"


class Insertion : public SortingAlgorithm {
public:
    template<typename Item>
    static void sort(Item a[], int N) {
        resetCount();
        
        for (int i=1; i<N; i++) {
            for (int j=i; j>0 && less(a[j], a[j-1]); j--) {
                exch(a, j, j-1);
            }
        }

        assert(isSorted(a, N));
    }
};


#endif
