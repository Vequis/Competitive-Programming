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

using namespace std;

map<int, int> f;
int n,m,k,v;
vi V;

int main(){_

    while (cin >> n >> m){
        V = vi(n);

        for (int i=0; i<n; i++){
            cin >> V[i];
            f[V[i]]++;
        }

        for (int i=0; i<m; i++){
            cin >> k >> v;
                if (k > f[v]){
                    cout << 0 << endl;
                    continue;
                }

            for (int j=0; j<n; j++){
                if (V[j] == v){
                    k--;
                    if (!k){
                        cout << j+1 << endl;
                        break;
                    }
                }
            }
        }

        f.clear();

    }

    return 0;
}