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

using namespace std;

string s;
int dist[110], t, prim, ultimo, cont, n, k, resp;

int main(){_

    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;

        dist[0] = 0;
        prim = -1;
        for (int i=0; i<sz(s); i++){
            if (s[i] == '*'){
                if (prim==-1) prim = i+1;
                ultimo = i+1;
                dist[i+1] = 0;
            } else{
                dist[i+1] = dist[i-1 + 1]+1;
            }
        }

        cont = prim;
        resp = 1;
        while(cont+k <= ultimo){
            resp++;
            cont = cont+k-dist[cont+k];
        }

        if(cont+k>ultimo && cont!= ultimo) resp++;

        cout << resp << endl;
    }

    return 0;
}