#ifndef MAXPQ_H
#define MAXPQ_H


#include <cassert>


template<typename Item>
class MaxPQ {
private:
    Item* pq;
    int N;

public:

    MaxPQ(int maxN) : N(0) {
        pq = new Item[maxN+1];
    }

    MaxPQ() : MaxPQ(1) { }

    MaxPQ(Item keys[], int N) {
        pq = new Item[N+1];
        for (int i=0; i<N; i++) {
            pq[i+1] = keys[i];
        }
        for (int k=N/2; k>=1; k--) {
            fixDown(k);
        }
        assert(isHeap());
    }

    ~MaxPQ() {
        delete[] pq;
    }

    bool isEmpty() {
        return N == 0;
    }

    int size() {
        return N;
    }

    void insert(Item v) {
        pq[++N] = v;
        fixUp(N);
        assert(isHeap());
    }

    Item remove() {
        Item max = pq[1];
        exch(1, N--);
        fixDown(1);
        assert(isHeap());
        return max;
    }

private:

    void fixUp(int k) {
        while (k > 1 && less(k/2, k)) {
            exch(k, k/2);
            k = k/2;
        }
    }

    void fixDown(int k) {
        while(2*k <= N) {
            int j = 2*k;
            if (j < N && less(j, j+1)) j++;
            if (!less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    bool less(int i, int j) {
        return pq[i] < pq[j];
    }

    void exch(int i, int j) {
        std::swap(pq[i], pq[j]);
    }

    bool isHeap() {
        return isHeap(1);
    }

    bool isHeap(int k) {
        if (k > N) return true;
        int left = 2*k;
        int right = 2*k+1;
        if (left <= N && less(k, left)) return false;
        if (right <= N && less(k, right)) return false;
        return isHeap(left) && isHeap(right);
    }

};


#endif