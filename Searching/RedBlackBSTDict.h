#ifndef REDBLACKBSTDICT_H
#define REDBLACKBSTDICT_H


#include <iostream>
#include <cassert>


template<typename Key, typename Value>
class RedBlackBSTDict {
private:

    static const bool RED    = true;
    static const bool BLACK  = false;

    struct Node {
        Key key;
        Value val;

        int N;
        bool color;

        Node* left;
        Node* right;

        Node(const Key& key, const Value& val, int N, bool color) :
            key(key), val(val), N(N), color(color),
            left(nullptr), right(nullptr) { }
    };

    Node* root;

public:

    RedBlackBSTDict() : root(nullptr) { }

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
        root->color = BLACK;
    }

    void print() {
        print(root);
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

    Node* put(Node* h, const Key& key, const Value& val) {
        if (h == nullptr) {
            return new Node(key, val, 1, RED);
        }

        if (key < h->key)
            h->left = put(h->left, key, val);
        else if (key > h->key)
            h->right = put(h->right, key, val);
        else
            h->val = val;

        if (isRed(h->right) && !isRed(h->left))
            h = rotateLeft(h);

        if (isRed(h->left) && isRed(h->left->left))
            h = rotateRight(h);

        if (isRed(h->left) && isRed(h->right))
            flipColors(h);

        h->N = size(h->left) + 1 + size(h->right);

        return h;
    }

    bool isRed(Node* x) {
        if (x == nullptr) return false;
        return x->color == RED;
    }

    Node* rotateLeft(Node* h) {
        Node* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = size(h->left) + 1 + size(h->right);
        return x;
    }

    Node* rotateRight(Node*h) {
        Node* x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = size(h->left) + 1 + size(h->right);
        return x;
    }

    void flipColors(Node* h) {
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

    void print(Node* x) {
        if (x == nullptr) return;

        print(x->left);
        std::cout << "< " << x->key << " : " << x->val << " >" << std::endl;
        print(x->right);
    }

};


#endif