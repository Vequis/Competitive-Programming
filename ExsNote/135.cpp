#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ant = 0;
    int post;

    int maiorSeq = 1;
    int seq = 1;
    for (int i = 1; i<=n; i++){
        cin >> post;
        if (ant == post) {
            seq+=1;
            if (seq > maiorSeq) {
                maiorSeq = seq;
            }
        } else {
            seq = 1;
        }
        ant = post;
    }
    cout << maiorSeq << "\n";
}
