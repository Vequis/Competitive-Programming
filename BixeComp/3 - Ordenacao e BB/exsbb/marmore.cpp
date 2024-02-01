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

int n, q, caso, num, atual;
vi v;

int bb(int x){
    int ini=0, fim=n, mid;
    while(ini < fim){
        mid = ini + (fim-ini)/2;
        if (v[mid]>=x)fim = mid;
        else ini = mid+1;
    }
    if(v[ini]==x) return ini;
    return -1;
}

int main(){_

    while((cin >> n >> q) && (n!=0&&q!=0)){
        caso++;
        v = vi(n);
        for (int i=0; i<n; i++){
            cin >> v[i];
        }

        cout << "CASE# " << caso << ":" << endl;

        sort(all(v));

        for (int i=0; i<q; i++){
            cin >> num;
            atual = bb(num);
            if (atual==-1){
                cout << num << " not found" << endl;
            } else {
                cout << num << " found at " << atual+1 << endl;
            }
        }

        v.clear();
    }

    return 0;
}