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

signed main(){_

    int n;
    cin >> n;

    int k;
    cin >> k;

    vi a(n+1);

    for(int i = 1; i <=n; i++) cin >> a[i];

    int menor = INF;
    int seqmenor = 1;
    int naomexer = 0;
    for(int i = n; i> 0; i--) {
        if (a[i] <= menor) {
            seqmenor++;
            if (seqmenor == k) naomexer=1;
        }
        else {
            seqmenor = 1;
            menor = a[i];
        }
        menor = min(a[i], menor);
    }

    if (naomexer) {
        for(int i = 1; i <=n; i++) cout << a[i] << ' ';
        cout << endl;
        return 0;
    }

    menor = INF;
    for(int i = n; i> n-k; i--) {
        menor = min(a[i], menor);
    }

    int first = n-k + 1;

    while(first > 1 and a[first - 1] <= menor) {
        first--;
        menor = min(menor, a[first]);
    }
    
    vi last;

    for(int i = first; i<=n - (n-k+1 - first); i++) {
        last.pb(a[i]);
    }

    sort(all(last));

    for(int i = first; i<=n - (n-k+1 - first); i++) {
        a[i] = last[i-first];
    }

    for(int i = 1; i <=n; i++) cout << a[i] << ' ';
    cout << endl;

    return 0;
}
