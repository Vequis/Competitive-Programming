#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>


int max1 = 1e9;

using namespace std;

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        string s;
        cin >> s;

        string aux;
        aux+=s[0];
        for (int j=1; j<s.size(); j+=2){
            aux+=s[j];
        }
        cout << aux << endl;
    }
	return 0;
}
