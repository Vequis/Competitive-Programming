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
#define MAXN 1000000000+7

using namespace std;

// vector<bool> bset(MAXN);
// bitset<MAXN> nums;
set<int> cj;
set<int>::iterator it;
int d;
int main(){_

    int n;

    cin >> n;

    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        cj.insert(num);
        // nums[num] = 1;
        // vetor.eb(num);
    }

    cin >> d;

    for (it = cj.begin(); it!=cj.end(); it++){
        int x = (*it);
        if (cj.count(d-x)){
            cout << x << " " << d-x << endl;
            return 0;
        }
    }

    return 0;
}