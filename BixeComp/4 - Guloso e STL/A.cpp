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

vi places, pos;
int n, m, q, cont;

int main(){_

    cin >> n >> m >> q;

    places = vi(m+1);
    pos = vi(n+1);
    cont = m;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        if (places[num]==0) cont--;
        places[num]++;
        pos[i+1] = num;
    }

    for (int i=0; i<q; i++){
        int a,b;
        cin >> a >> b;

        places[pos[a]]--;
        if(!places[pos[a]]) cont++;

        if(!places[b]) cont--;
        places[b]++;

        pos[a] = b;
    
        cout << cont << endl;
    }

    return 0;
}