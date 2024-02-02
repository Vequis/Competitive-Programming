#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<char> Q;

    for (int i=0; i<16; i++){
        Q.push('A'+i);
    }

    for (int i=0; i<15; i++){
        int a, b;
        cin >> a >> b;
        if (a>b) {
            Q.push(Q.front());
            Q.pop();
            Q.pop();
        } else {
            Q.pop();
            Q.push(Q.front());
            Q.pop();
        }
    }

    cout << Q.front() << endl;
    return 0;
}
