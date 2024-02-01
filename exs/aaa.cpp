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

vi primos;
int visitados[112345];

void crivo(int n){
    primos.pb(2);
    for(int i=3; i<=n; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitados[i] = 1;
        }
    }
}

int mdc(int a, int b) {
    if (a < b) swap(a,b);
    if (b==0) return a;
    return (mdc(b, a%b));
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[123];
        int psa[123];

        for(int i = 0; i < 110; i++) a[i] = 0;
        for(int i = 0; i < 110; i++) psa[i] = 0;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            a[num]++;
        }


        psa[n]= 0;

        int resp = -1;
        for(int i = n-1; i>=0; i--) {
            psa[i] = psa[i+1] + a[i+1];

            if (psa[i] == i) resp = i;
        }

        cout << resp << endl;

    }
    return 0;
}
