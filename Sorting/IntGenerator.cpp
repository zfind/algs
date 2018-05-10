#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    srand((unsigned) time(0));

    if (argc != 3) {
        cout << "Usage: a.out N SCALE" << endl;
        exit(1);
    }

    int N = atoi(argv[1]);
    int SCALE = atoi(argv[2]);

    cout << N << endl;

    for (int i=0; i<N; i++) {
        cout << (rand() % SCALE) + 1 << endl;
    }

    return 0;
}