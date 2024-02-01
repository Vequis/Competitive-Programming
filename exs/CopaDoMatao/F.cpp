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

#define maxn 112345

int a[maxn];
map<int, int> f;

int modexp(int b, int e) {
	int res = 1;
	while (e > 0) {
		if (e & 1) res = (res * b);
		b = (b * b);
		e /= 2;

        if (res >= INT_MAX) return -1;
	}
	return res;
}

int rootBinarySearch(int l, int r, int x, int e){ 
    if (r > l) {
        int mid = l + (r - l) / 2;
 
        int atual = modexp(mid, e);
        if (atual == -1)  return rootBinarySearch(l, mid-1, x, e);

        if (atual >= x)
            return rootBinarySearch(l, mid, x, e);
        return rootBinarySearch(mid + 1, r, x, e);
    }

    return l;
}

signed main(){_

    int n, q;
    cin >> n;
    cin >> q;

    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    sort(a+1, a+n+1);

    int r;
    while(q--) {
        int cont = 0;

        cin >> r;

        int ant = 1;
        int numAnt = 0;

        for(int i = 1; i <= n; i++) {
            int atual = rootBinarySearch(ant, a[n], a[i], r);

            // cout << '*' << atual << endl;

            int numAtual = modexp(atual, r);

            if (numAtual == a[i]) {
                cont++;
            }

            ant = atual;
            numAnt = numAtual;
        }

        cout << cont << endl;
    }

    return 0;
}
