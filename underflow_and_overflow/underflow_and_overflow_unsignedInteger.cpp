#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "=== unsigned int ===" << endl;
    
    unsigned int u=0;
    
    //Overflow
    while (true) {
        unsigned int prev=u;
        u=u+1;
        if (u<prev) {
            cout << "Overflow: from " << prev << " to " << u << endl;
            break;
        }
    }
    
    cout << "According to <limits>: " << endl;
    cout << "MAx unsigned int = " << numeric_limits<unsigned int>::max() << endl;
    cout << "Min unsigned int = " << numeric_limits<unsigned int>::min() << endl;
    
    return 0;
}
