#include <iostream>
using namespace std;

class UF {
private:
  int *parent;
  int *size;
  int componentsCount;

public:
  UF(int n) {
    parent = new int[n];
    size = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  ~UF() {
    delete[] parent;
    delete[] size;
  }

  int getCount() { return componentsCount; }

  int findParent(int p) {
    while (p != parent[p])
      p = parent[p];
    return p;
  }

  bool isConnected(int p, int q) { return findParent(p) == findParent(q); }

  void unionNodes(int p, int q) {
    int rootP = findParent(p);
    int rootQ = findParent(q);
    if (rootP == rootQ)
      return;

    if (size[rootP] < size[rootQ]) {
      parent[rootP] = rootQ;
    } else {
      parent[rootQ] = rootP;
      size[rootP] += size[rootQ];
    }
    componentsCount--;
  }
};


int main() {
  int n, p, q;
  cin >> n;
  UF uf = UF(n);
  while (cin >> p) {
    cin >> q;
    if (uf.isConnected(p, q))
      continue;
    uf.unionNodes(p, q);
    cout << p << " " << q << endl;
  }

  return 0;
}
