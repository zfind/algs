#ifndef SORTCOMMON_H
#define SORTCOMMON_H


#include <iostream>


class SortingAlgorithm {
public:

    template<typename Item>
    static void sort(Item a[], int N);

    static int getCompareCount() {
        return compareCount;
    }

    static int getExchangeCount() {
        return exchangeCount;
    }

protected:

    static int compareCount;
    static int exchangeCount;

    SortingAlgorithm() = delete;

    static void resetCount() {
        compareCount = 0;
        exchangeCount = 0;
    }

    template<typename Item>
    static int less(Item& a, Item& b) {
        #ifdef COUNT_STATS
        compareCount++;
        #endif
        return a < b;
    }

    template<typename Item>
    static void exch(Item a[], int i, int j) {
        #ifdef COUNT_STATS
        exchangeCount++;
        #endif
        std::swap(a[i], a[j]);
    }

    template<typename Item>
    static void exch(Item& a, Item& b) {
        #ifdef COUNT_STATS
        exchangeCount++;
        #endif
        Item& tmp = a;
        a = b;
        b = tmp;
    }

    template<typename Item>
    static bool isSorted(Item a[], int N) {
        return isSorted(a, 0, N-1);
    }

    template<typename Item>
    static bool isSorted(Item a[], int lo, int hi) {
        for (int i=lo+1; i<=hi; i++) {
            if (less(a[i], a[i-1])) {
                return false;
            }
        }
        return true;
    }

};

int SortingAlgorithm::compareCount = 0;
int SortingAlgorithm::exchangeCount = 0;


template<typename Item>
static void printArray(Item a[], int N) {
    for (int i=0; i<N; i++) {
        std::cout << a[i] << std::endl;
    }
}


#endif