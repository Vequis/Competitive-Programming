#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()

using namespace std;

vi v;
int n, x;

int main(){_

    cin >> n;

    v = vi(n);

    for (int &x : v){
        cin >> x;
    }

    v.erase(v.begin() + 1); // Apagando o segundo elemento (v[1])
    //Poderia ser v.erase(v.begin()+1, v.begin()+3); Apagará v[1] á v[3-1]

    while(sz(v)){
        int x = v.back(); //O ultimo elemento
        v.pop_back();
        cout << x << " " ;
    }

    cout << endl;

    return 0;

}