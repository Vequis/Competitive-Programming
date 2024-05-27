#include <bits/stdc++.h>

using namespace std;

void solve() {
    set<int> s;
    int n, c, m;
    cin >> n >> c >> m;

    while(c--) {
        int a;
        cin >> a;
        s.insert(a);
    }

    while(m--) {
        int a;
        cin >> a;
        if (s.count(a)) s.erase(s.find(a));
    }

    cout << s.size() << endl;
}

int main() {

    solve();

    return 0;
}