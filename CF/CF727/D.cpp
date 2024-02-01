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
#define int long long

using namespace std;

int n;
int a, b;
vii v;
int atual, custo, ultimo;

signed main(){_

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.eb(b,a);
    }

    sort(all(v));
    ultimo = n-1;

    for(int i=0; i<n; i++){
        while(v[i].fs > atual and i<=ultimo){
            if(v[i].fs - atual <= v[ultimo].sc){
                custo+=2*(v[i].fs - atual);
                v[ultimo].sc = v[ultimo].sc - (v[i].fs - atual);
                atual+=(v[i].fs - atual);
            } else {
                custo+=2*(v[ultimo].sc);
                atual+=v[ultimo].sc;
                v[ultimo].sc = 0;
                ultimo--;
            }
        }

        custo+=v[i].sc;
        atual+=v[i].sc;
    }

    cout << custo << endl;

    return 0;
}
