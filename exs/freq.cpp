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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

set<int> cj;

int main(){_

    int n;
    cin >> n;

    int num;

    for (int i=0; i<n; i++){
        cin >> num;
        cj.insert(num);
    }

    cout << cj.size() << endl;

    return 0;
}