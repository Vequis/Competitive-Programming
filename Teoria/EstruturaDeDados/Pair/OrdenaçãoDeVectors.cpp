#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector < pair<int, string> > V;
    pair <int, string> temp;


    for (int i=1; i<10; i++) {
        cin >> temp.first >> temp.second;
        V.push_back(temp);
    }

    sort(V.begin(), V.end()) ;

    return 0;
}
