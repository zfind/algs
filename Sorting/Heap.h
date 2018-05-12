#ifndef HEAPSORT_H
#define HEAPSORT_H


#include <iostream>
#include <cassert>
#include "SortCommon.h"


class Heap : public SortingAlgorithm {
public:

    template<typename Item>
    static void sort(Item a[], int N) {
        resetCount();

        int n = N;

        for (int k=n/2; k>= 1; k--) {
            sink(a, k, n);
        }
        
        while (n > 1) {
            exch(a, 1, n--);
            sink(a, 1, n);
        }

        assert(isSorted(a, N));
    }

private:

    template<typename Item>
    static void sink(Item a[], int k, int N) {
        while (2*k <= N) {
            int j = 2*k;
            if (j < N && less(a, j, j+1)) j++;
            if (!less(a, k, j)) break;
            exch(a, k, j);
            k = j;
        }
    }

    template<typename Item>
    static int less(Item a[], int i, int j) {
        #ifdef COUNT_STATS
        compareCount++;
        #endif
        return a[i-1] < a[j-1];
    }

    template<typename Item>
    static void exch(Item a[], int i, int j) {
        #ifdef COUNT_STATS
        exchangeCount++;
        #endif
        std::swap(a[i-1], a[j-1]);
    }

};


#endif
