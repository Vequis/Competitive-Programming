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

int v[1111];

int bb (int x, int inicio, int fim) {
    if (inicio > fim) return -1;

    int mid = inicio + (fim - inicio) / 2;

    if (v[mid] == x) return mid;
    else if (v[mid] > x) return bb(x, inicio, mid - 1);
    else return bb(x, mid+1, fim);
}

signed main(){_

    for (int i = 0; i < 100; i++) {
        v[i] = i;
    }

    cout << bb(2, 1, 4) << endl;

    return 0;
}
