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

int n, m, v[110], v2[110];

int main(){_

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    cin >> m;

    for (int i=0; i<m; i++){
        cin >> v2[i];
    }

    int j= 0;

    for (int i=0; i<n; i++){
        while(v2[j] < v[i] && j<m) {
            j++;
        }   
        if (v2[j] > v[i] or j>=m) cout << v[i] << ' ';
    }

    return 0;
}