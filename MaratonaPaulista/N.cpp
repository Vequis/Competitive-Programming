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
int visitados[1123457];

void crivo(int n){
    primos.pb(2);
    for(int i=3; i<=n; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitados[j] = 1;
        }
    }
}

signed main(){_

    crivo(1123456);

    set<ii> s;
    map<int, int> f;

    set<int> acesos;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (acesos.find(a) != acesos.end()) {
            acesos.erase(a);

            for (int primo : primos) {
                if (a%primo == 0) {
                    if (f[primo] != 0) s.erase({f[primo], primo});
                    f[primo]--;
                    s.insert({f[primo], primo});
                }
                
                while(a%primo == 0) a/=primo;

                if (a== 1) break;
            }
        } else {
            acesos.insert(a);

            for (int primo : primos) {
                if (a%primo == 0) {
                    s.erase({f[primo], primo});
                    f[primo]++;
                    if (f[primo] != 0) s.insert({f[primo], primo});
                }
                
                while(a%primo == 0) a/=primo;

                if (a==1)break;
            }
        }
    
        cout << (*s.rbegin()).fs << endl;
        // for (ii p : s) {
        //     cout << p.fs << ' ' << p.sc << endl;
        // }
        // cout << endl;
    }

    return 0;
}
