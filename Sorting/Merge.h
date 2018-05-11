#ifndef MERGE_H
#define MERGE_H


#include <iostream>
#include <cassert>
#include <algorithm>
#include "SortCommon.h"

class Merge : public SortingAlgorithm {
public:
    template <typename Item>
    static void sort(Item a[], int N) {
        resetCount();

        Item aux[N];
        sort(a, aux, 0, N - 1);

        assert(isSorted(a, N));
    }

private:
    template <typename Item>
    static void sort(Item a[], Item aux[], int lo, int hi) {
        if (hi <= lo) return;

        int mid = lo + (hi - lo) / 2;

        sort(a, aux, lo, mid);
        sort(a, aux, mid + 1, hi);

        merge(a, aux, lo, mid, hi);
    }

    template <typename Item>
    static void merge(Item a[], Item aux[], int lo, int mid, int hi) {
        assert(isSorted(a, lo, mid));
        assert(isSorted(a, mid + 1, hi));

        std::copy_n(a + lo, hi + 1 - lo, aux + lo);

        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)               exch(a[k], aux[j++]);
            else if (j > hi)                exch(a[k], aux[i++]);
            else if (less(aux[j], aux[i]))  exch(a[k], aux[j++]);
            else                            exch(a[k], aux[i++]);
        }

        assert(isSorted(a, lo, hi));
    }

};


#endif
