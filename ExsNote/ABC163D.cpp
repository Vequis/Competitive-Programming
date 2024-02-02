#include <iostream>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    long long int soma = 0;

    long long int mod = 1000000007;

    for (int i=k; i<=n+1; i++) {
        long long int R = i*(i-1)/2;
        long long int L = n*i - R;
        soma += L - R + 1;
    }

    cout << (soma%mod) << endl;
    return 0;

}
