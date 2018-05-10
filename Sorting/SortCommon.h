#include <iostream>


class SortingAlgorithm {
private:
    SortingAlgorithm();

public:
    template<typename Item>
    static void sort(Item a[], int N);

    template<typename Item>
    static int less(Item& a, Item& b) {
        return a < b;
    }

    template<typename Item>
    static void exch(Item a[], int i, int j) {
        std::swap(a[i], a[j]);
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


template<typename Item>
static void printArray(Item a[], int N) {
    for (int i=0; i<N; i++) {
        std::cout << a[i] << std::endl;
    }
}