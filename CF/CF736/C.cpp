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

int n, m;

vi vul;
int resp;

signed main(){_

    cin >> n >> m;

    v = vul(n+1);

    inbt a

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(a>b) swap(a,b); //Sempre a<b;

        if(vul[a] == 0) resp++;
        vul[a]++;
    }

    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int op;
        cin >> op;

        if(op == 1){
            int a, b;
            cin >> a >> b;

            if(a>b) swap(a,b);

            if(vul[a] == 0) resp++;
            vul[a]++;
        } else if(op==2){
            int a, b;
            cin >> a >> b;

            if(a>b) swap(a,b);

            vul[a]--;
            if(vul[a]==0) resp
            
        }
    }

    return 0;
}
