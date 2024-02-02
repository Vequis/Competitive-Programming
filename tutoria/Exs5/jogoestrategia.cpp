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

using namespace std;

int j,r, aux, venc;
vi v;

int main(){_
    cin >> j >> r;
    v = vi(j);

    for (int i=0; i<j*r; i++){
        cin >> aux;
        v[i%j] += aux;

        if (v[i%j] >= v[venc]) venc = i%j;
    }

    cout << venc+1 << endl;

    return 0;
}