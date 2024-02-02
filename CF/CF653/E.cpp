#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    cin >> n >> k;

    vector<int> times[4];
    vector<int> sums[4];

    for(int i= 0; i<n; i++){
        int t, a ,b;
        cin >> t >> a >>b;
        times[a*2 + b].push_back(t);
    }

    for(int i=0; i<4; i++){
        sort(times[i].begin, times[i].begin());
        sums[i].push_back();
        for(auto it:: times[i]) {
            sums[i].push_back(sums[i].back + it);
        }
    }

    int ans = INF;

    for(int cnt = 0; cnt < min(k+1, int(sums[3].size())); cnt++){
        if (k-cnt < int (sums[1].size()) && k - cnt < int(sums[2].size())){
            ans = min (ans, sums[3])
        }
    }


// depois ainda tem que escrever uma carta, e p
    return 0;
}