#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n,m;

    cin >> n >> m;

    int minA = floor((n-1)/3) + 1;
    long maneiras = 0;

    for (int a = minA; a<=min(n,m); a++){
        int minB = floor((n-a-1)/2)+1;
        maneiras += a-minB+1;
    }

    maneiras *= 3;

    cout << maneiras << endl;
    return 0;
}
