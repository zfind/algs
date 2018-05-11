#ifndef SHELL_H
#define SHELL_H


#include <iostream>
#include <cassert>
#include "SortCommon.h"


class Shell : public SortingAlgorithm {
public:
    template<typename Item>
    static void sort(Item a[], int N) {
        resetCount();

        int h = 1;
        while (h < N/3) h = 3*h + 1;

        while (h >= 1) {
            for (int i=h; i<N; i++) {
                for (int j=i; j>=h && less(a[j], a[j-h]); j-=h) {
                    exch(a, j, j-h);
                }
            }
            h /= 3;
        }

        assert(isSorted(a, N));
    }
};


#endif
