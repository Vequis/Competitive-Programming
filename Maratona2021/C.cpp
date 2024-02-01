#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int b, l;
int soma;

int num[213245];
int pot[212345];

int gcdExtended(int a, int b, int* x, int* y);

int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        // m is added to handle negative x
        int res = (x % m + m) % m;
        return res;
    }
}
 
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{
     
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
     
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

signed main(){_

    cin >> b >> l;

    for (int i = 1; i <= l; i++) {
        cin >> num[i];
    }

    // cout << (2 - 7) % 5 << endl;

    int potatual = 1;
    for (int i = l; i >= 1; i--) {
        soma = (soma + num[i] * potatual)%(b+1);
        pot[i] = potatual;
        potatual = (potatual * b) % (b+1);
    }

    if (soma == 0) {
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }

    for (int i = 1; i<=l; i++) {
        int aux = soma;

        int inv = modInverse(pot[i], b+1); 
        if (inv != -1 && (inv*aux)%(b+1) <= num[i]) {
            cout << i << ' ' << num[i] - (inv*aux) % (b+1) << endl;
            return 0;
        }
    }

    cout << -1 << ' ' << -1 << endl;

    return 0;
}
