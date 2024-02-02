#include <iostream>

using namespace std;

int main() {
    pair<int,string> A;
    pair<int,string> B;

    A.first = 10;
    A.second = "Vítor";

    B.first = 7;
    B.second = "Jerônimo";

    if (A > B) { //A ordem é dado pelo primeiro valor do pair, primeiro tipo, .first, etc.
        cout << A.second << " tirou a maior nota\n";
    } else {
        cout << B.second << " tirou a maior nota\n";
    }

    return 0;
}
