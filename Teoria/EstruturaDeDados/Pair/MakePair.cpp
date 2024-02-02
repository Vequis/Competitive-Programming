#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector <pair<int,string> > V;
    int a;
    string b;

    for (int i=1;i<5; i++){
        cin >> a >> b;
        V.push_back(make_pair(a,b)); //A função tranforma os valores em 1 pair
    }

    sort(V.begin(), V.end());

    for (int i=0;i<4; i++){
        cout << V[i].first << " " << V[i].second << endl;
    }

    return 0;
}
