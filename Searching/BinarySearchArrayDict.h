#ifndef BINARYSEARCHARRAYDICT_H
#define BINARYSEARCHARRAYDICT_H


#include <iostream>
#include <cassert>


template<typename Key, typename Value>
class BinarySearchArrayDict {
private:

    Key* keys;
    Value* vals;
    int N;

public:

    BinarySearchArrayDict(int capacity) : N(0) {
        keys = new Key[capacity];
        vals = new Value[capacity];
    }

    ~BinarySearchArrayDict() {
        delete[] keys;
        delete[] vals;
    }

    int size() {
        return N;
    }

    bool isEmpty() {
        return N == 0;
    }

    Value get(Key& key) {
        if (isEmpty()) return nullptr;
        int idx = rank(key);
        if (idx < N && keys[idx] == key) {
            return vals[idx];
        } else {
            return nullptr;
        }
    }

    void put(Key& key, Value& val) {
        int idx = rank(key);
        if (idx < N && keys[idx] == key) {
            vals[idx] = val;
            return;
        }
        for (int i=N; i>idx; i--) {
            keys[i] = keys[i-1];
            vals[i] = vals[i-1];
        }
        keys[idx] = key;
        vals[idx] = val;
        N++;
    }

    int rank(Key& key) {
        return rank(key, 0, N-1);
    }

    int rank(Key& key, int lo, int hi) {
        if (hi < lo) return lo;
        int mid = lo + (hi - lo) / 2;
        int cmp = key < keys[mid];
        if (key < keys[mid]) {
            return rank(key, lo, mid-1);
        } else if (key > keys[mid]) {
            return rank(key, mid+1, hi);
        } else {
            return mid;
        }
    }

    void print() {
        for (int i=0; i<N; i++) {
            std::cout << "< " << keys[i] << " : " << vals[i] << " >" << std::endl;
        }
    }

};


#endif
