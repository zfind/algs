#ifndef SELECTION_H
#define SELECTION_H


#include <iostream>
#include <cassert>
#include "SortCommon.h"


class Selection : public SortingAlgorithm {
public:
    template<typename Item>
    static void sort(Item a[], int N) {
        resetCount();

        for (int i=0; i<N; i++) {
            int min = i;
            for (int j=i+1; j<N; j++) {
                if (less(a[j], a[min])) min = j;
            }
            exch(a, i, min);
        }

        assert(isSorted(a, N));
    }
};


#endif
