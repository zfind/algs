#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include "SortCommon.h"

class Quick : public SortingAlgorithm {
public:
    template <typename Item>
    static void sort(Item a[], int N) {
        std::random_shuffle(a, a + N);
        sort(a, 0, N - 1);
        assert(isSorted(a, N));
    }

private:
    template <typename Item>
    static void sort(Item a[], int lo, int hi) {
        if (hi <= lo) return;
        int j = partition(a, lo, hi);
        sort(a, lo, j - 1);
        sort(a, j + 1, hi);
        assert(isSorted(a, lo, hi));
    }

    template <typename Item>
    static int partition(Item a[], int lo, int hi) {
        int i = lo;
        int j = hi + 1;
        Item v = a[lo];

        while (true) {
            while (less(a[++i], v)) {
                if (i == hi)
                    break;
            }
            while (less(v, a[--j])) {
                if (j == lo)
                    break;
            }

            if (i >= j)
                break;

            exch(a, i, j);
        }

        exch(a, lo, j);

        return j;
    }
};

int main() {
    int N;
    std::cin >> N;

    int a[N];
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    Quick::sort(a, N);

    // printArray(a, N);

    return 0;
}