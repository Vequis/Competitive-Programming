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

ll soma;
int cont;
vi v;

int main(){_

    int t, n;

    cin >> t;

    while(t--){
        cin >> n;

        v = vi(n);

        soma=0;

        for (int i=0; i<n; i++){
            int num;
            cin >> num;

            soma+=num;

            v[i] = num;
        }

        if (soma%n){
            cout << -1 << endl;
            continue;
        } 

        cont=0;

        for (int i=0; i<n; i++){
            if (v[i] > soma/n) cont++;
        }

        cout << cont << endl;
    }

    return 0;
}