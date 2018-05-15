#ifndef BINARYSEARCHTREEDICT_H
#define BINARYSEARCHTREEDICT_H


#include <iostream>
#include <cassert>


template<typename Key, typename Value>
class BinarySearchTreeDict {
private:

    struct Node {
        Key key;
        Value val;
        int N;
        Node* left;
        Node* right;

        Node(const Key& key, const Value& val, int N) :
            key(key), val(val), N(N),
            left(nullptr), right(nullptr) { }
    };

    Node* root;

public:

    BinarySearchTreeDict() : root(nullptr) { }

    int size() {
        return size(root);
    }

    bool isEmpty() {
        return size() == 0;
    }

    Value get(const Key& key) {
        return get(root, key);
    }

    void put(const Key& key, const Value& val) {
        root = put(root, key, val);
    }

    void print() {
        print(root);
    }

    Key min() {
        if (root == nullptr) return nullptr;
        return min(root)->key;
    }

    bool floor(const Key& key, Key& result) {
        Node* x = floor(root, key);
        if (x == nullptr) return false;
        result = x->key;
        return true;
    }

    bool select(int k, Key& result) {
        Node* selected = select(root, k);
        if (selected == nullptr)
            return false;
        result = selected->key;
        return true;
    }

    int rank(const Key& key) {
        return rank(root, key);
    }

private:

    int size(Node* x) {
        if (x == nullptr)
            return 0;
        else
            return x->N;
    }

    Value get(Node* x, const Key& key) {
        if (x == nullptr) return nullptr;

        if (key < x->key)
            return get(x->left, key);
        else if (key > x->key)
            return get(x->right, key);
        else
            return x->val;
    }

    Node* put(Node* x, const Key& key, const Value& val) {
        if (x == nullptr)
            return new Node{key, val, 1};

        if (key < x->key)
            x->left = put(x->left, key, val);
        else if (key > x->key)
            x->right = put(x->right, key, val);
        else
            x->val = val;

        x->N = size(x->left) + size(x->right) + 1;

        return x;
    }

    void print(Node* x) {
        if (x == nullptr) return;

        print(x->left);
        std::cout << "< " << x->key << " : " << x->val << " >" << std::endl;
        print(x->right);
    }

    Node* min(Node* x) {
        if (x->left == nullptr) return nullptr;
        return min(x->left);
    }

    Node* floor(Node* x, const Key& key) {
        if (x == nullptr) return nullptr;
        if (key == x->key)
            return x;
        else if (key < x->key)
            return floor(x->left, key);
        Node* t = floor(x->right, key);
        if (t != nullptr)
            return t;
        else
            return x;
    }

    Node* select(Node* x, int k) {
        if (x == nullptr) return nullptr;
        int t = size(x->left);
        if (t > k) 
            return select(x->left, k);
        else if (t < k) 
            return select(x->right, k-t-1);
        else 
            return x;
    }

    int rank(Node* x, const Key& key) {
        if (x == nullptr) return 0;
        if (key < x->key)
            return rank(x->left, key);
        else if (key > x->key)
            return size(x->left) + 1 + rank(x->right, key);
        else
            return size(x->left);
    }

};


#endif