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

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int pos;
        cin >> pos;

        priority_queue<int, vi, greater<int>> pq;

        for(int i = 0; i < sz(s) - 1; i++) {
            if (s[i] > s[i+1]) pq.push(i);
        }

        int sz_atual = sz(s);

        while(pos > sz(s)) {
            
        }
    }

    return 0;
}
