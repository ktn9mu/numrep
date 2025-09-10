#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "=== signed int ===" << endl;
    
    int x = 0;
    
    //overflow
    while (true) {
        int prev = x;
        x = x + 1;
        if (x < prev) {
            cout << "Overflow: from " << prev << " to " << x << endl;
            break;
        }
    }
    
    //underflow
    x = 0;
    while (true) {
        int prev = x;
        x = x - 1;
        if (x > prev) {
            cout << "Underflow: from " << prev << " to " << x << endl;
            break;
        }
    }
    
    cout << "According to <limits>: " << endl;
    cout << "Max int = " << numeric_limits<int>::max() << endl;
    cout << "Min int = " << numeric_limits<int>::min() << endl;
    
    return 0;
}
