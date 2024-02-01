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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

map<int,int> f;
set<int> cj;
vi v;
int t, n, aux;
ll atual, resp;

int main(){_

    cin >> t;

    while(t--){
        cin >> n;

        for (int i=0; i<n; i++){
            cin >> aux;
            cj.insert(aux);
            f[aux]++;
        }

        resp = 0;

        for (int i=2; i<=2*n; i++){
            atual = 0;
            for (auto x : cj){
                if (x > (i-1)/2) break;
                atual+= min(f[x], f[i-x]);
            }

            if (i%2 == 0) atual += f[i/2]/2;

            resp = max(resp, atual);
        }

        cout << resp << endl;

        f.clear();
        cj.clear();
    }

    return 0;
}