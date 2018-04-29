#include <iostream>
using namespace std;

class UF {
private:
    int *parent;
    int *size;
    int count;

public:
    UF(int N) {
        parent = new int[N];
        size = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        count = N;
    }

    ~UF() {
        delete[] parent;
        delete[] size;
    }

    int getCount() {
        return count;
    }

    int findRoot(int p) {
        while (p != parent[p])
            p = parent[p];
        return p;
    }

    bool isConnected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }

    void unionNodes(int p, int q) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
        if (rootP == rootQ)
            return;

        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }
};


int main() {
    int N, p, q;

    cin >> N;
    UF uf = UF(N);

    while (cin >> p) {
        cin >> q;
        if (uf.isConnected(p, q))
            continue;
        uf.unionNodes(p, q);
        cout << p << " " << q << endl;
    }

    cout << uf.getCount() << endl;

    return 0;
}
