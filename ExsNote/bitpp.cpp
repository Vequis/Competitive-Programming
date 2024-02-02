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
// #define int long long -> solução divina?

using namespace std;

int v[112345];

int main(){_

    int a, b, c, d, num;
    cin >> a >> b >> c >> d >> num;

    for (int i = a; i<=num; i+=a) v[i] = 1;
    for (int i = b; i<=num; i+=b) v[i] = 1;
    for (int i = c; i<=num; i+=c) v[i] = 1;
    for (int i = d; i<=num; i+=d) v[i] = 1;

    int cont = 0;
    for (int i = 1; i <=num; i++) {
        cont+=v[i];
    }

    cout << cont << endl;

    return 0;
}
