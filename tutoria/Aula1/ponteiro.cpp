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

set<int> s;
map<int, int> f;

map<int,int> :: iterator it;

int main(){_

    //Esses são ponteiros;
    int a = 5;
    int * ptr = &a;
    int b = *ptr;

    //Agora mexendo com sets;
    for (int i=0; i<10; i++){
        s.insert(i);
    }

    // for (set<int>::iterator it = s.begin(); it!=s.end(); it++){
    //     cout << *it << endl;
    // }

    //Agora iremos tentar mexer com sets;
    for (int i=0; i<5; i++){
        int num;
        cin >> num;
        f[num]++;
    }

    // for (int i=0; i<3; i++){ cout << f[i] << endl;}

    for (it = f.begin(); it != f.end(); it++){
        cout << it->fs << " " << it->sc << endl;
    }

    return 0;
}