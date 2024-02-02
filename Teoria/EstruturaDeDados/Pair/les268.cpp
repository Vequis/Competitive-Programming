#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string m[1005][10005];

int func(pair <int,string> a, pair<int,string> b){
    return a.first>b.first;
}

int main(){
    int n,t;
    vector< pair<int, string> > V;

    cin >> n >> t;

    pair<int,string> temp;

    for(int i=0; i<n; i++){
        cin >> temp.second >> temp.first;
        V.push_back(temp);
    }

    sort(V.begin(), V.end(), func);


    for (int i=0; i<n; i++){
        int x,y;
        x = i%t;
        y = i/t;
        m[x][y] = V[i].second;
    }

    for (int i=0; i<t; i++){
        int frac=n/t;
        if (i < n%t){
            frac++;
        }

        sort(m[i], m[i]+frac);
        cout << "Time " << (i+1) << endl;
        for (int j=0; j<frac; j++){
            cout << m[i][j] << endl;
        }

        cout << endl;
    }

    return 0;

}
