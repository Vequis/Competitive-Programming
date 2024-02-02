#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int p,s;

    cin >> p >> s;

    vector< pair<int,int> > V;
    pair <int, int> temp;

    for (int i=0; i<s; i++){
        cin >> temp.first >> temp.second;
        V.push_back(temp);
    }

    sort (V.begin(), V.end());

    for (int i=0; i<(int)V.size()-1; i++) {

        if (V[i].second >= V[i+1].first){
            if (V[i+1].second>=V[i].second) V[i].second = V[i+1].second;

            for (int j=i+1; j<(int)V.size() - 1; j++){
                V[j] = V[j+1];
            }

            V.pop_back();
            i--;
        }
    }

    for (int i=0; i<(int)V.size(); i++){
        cout << V[i].first << " " << V[i].second << endl;
    }

    return 0;
}
