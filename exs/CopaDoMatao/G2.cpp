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

int n, k;
map<int, int> mp;
int a[1123456];
int resp[1123456];

int dvrs = 0;

void add(int ind) {
    if (mp[a[ind]]++ == 0) dvrs++;
}

void remover(int ind) {
    if (--mp[a[ind]] == 0) dvrs--;
}

signed main(){_

    cin >> n >> k;
    int cont = 0;

    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i!= 1 && a[i] == a[i-1]) {
            if (k==1) resp[i]++;
            resp[i] += resp[i-1];
            cont += resp[i];
            continue;
        }

        add(i);
        if (dvrs == k) resp[i]++;
        int ptr = i-1;

        while(ptr > 0 && dvrs <= k){
            add(ptr);
            ptr--;
            if(dvrs == k) resp[i]++;
        }

        dvrs = 0;
        mp.clear();
        cont+=resp[i];
    }

    cout << cont << endl;

    return 0;
}
