#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

pair<int, int> par;

int main(){_

    cin >> n >> m;

    par = {n,m}; //Isso é muito melhor que make_pair

    cout << par.first << " " << par.second << endl;

    return 0;
}