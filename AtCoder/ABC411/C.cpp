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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

set<int> starts;
int n;
map<int, int> endings;
int resp = 0;
int color[512345];

bool there_is_segment_before(int idx, int* a) {
    if (sz(starts) == 0) return 0;
    
    auto it = starts.lower_bound(idx);
    // if (it == starts.end()) return 0;
    if (it == starts.begin() and (*it) != idx) return 0;

    if (it != starts.end() and *(it) == idx) {
        *a = idx;
        return 1;
    }
    *a = *(--it);
    return 1;
}

bool there_is_segment_after(int idx, int* b) {
    if (sz(starts) == 0) return 0;
    auto it = starts.upper_bound(idx);
    if (it == starts.end()) return 0;
    *b = *it;
    return 1;
}



void add_black(int idx) {
    // auto it = starts.lower_bound(idx);

    int a, b;
    if (there_is_segment_after(idx, &b) and there_is_segment_before(idx, &a)) {
        if (endings[a] == idx-1 and b == idx+1) {
            endings[a] = endings[b];
            starts.erase(starts.find(b));
        } else if (endings[a] == idx-1) {
            endings[a] = idx;
        } else if (b == idx+1) {
            endings[idx] = endings[b];
            starts.erase(starts.find(b));
            starts.insert(idx);
        } else {
            starts.insert(idx);
            endings[idx] = idx;
        }
    } else if (there_is_segment_after(idx, &b)) {
        if (b == idx+1) {
            endings[idx] = endings[b];
            starts.erase(starts.find(b));
            starts.insert(idx);
        } else {
            starts.insert(idx);
            endings[idx] = idx;
        }
    } else if (there_is_segment_before(idx, &a)){
        if (endings[a] == idx-1) {
            endings[a] = idx;
        } else {
            starts.insert(idx);
            endings[idx] = idx;
        }
    } else {
        starts.insert(idx);
        endings[idx] = idx;
    }

}

void add_white(int idx) {
    int a;
    if (there_is_segment_before(idx, &a) and endings[a] >= idx) { // always true
        if (a == idx) {
            starts.erase(starts.find(a));
            if (endings[a] != a) {
                starts.insert(a+1);
                endings[a+1] = endings[a];
            }
        } else {
            if (endings[a] != idx) {
                starts.insert(idx+1);
                endings[idx+1] = endings[a];
            }
            endings[a] = idx-1;
        }
    }
}

void solve() {
    int q;
    cin >> n >> q;

    for (int i = 1; i <=n; i++) color[i] = 0;

    while(q--) {
        int x;
        cin >> x;
        if (color[x]) add_white(x);
        else add_black(x);
        color[x] ^= 1;

        cout << sz(starts) << endl;
    }
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}