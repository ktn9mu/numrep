#include<iostream>
#include <cmath>
using namespace std;

int main() {
    
    double under_f = 1.0;
    double over_f = 1.0;
    
    cout << "=== doubbel (double precison) ===" << endl;
    
    //underflow
    for (int i = 0; i < 20000; i++) {
        under_f /= 2.0;
        if (under_f == 0.0) {
            cout << "Underflow at loop " << i << ", under = " << under_f <<endl;
            break;
        }
    }
    
    //overflow
    for (int i = 0; i<20000; i++) {
        over_f *= 2.0;
        if (isinf(over_f)) {
            cout << "Overflow at loop " << i << ", over = " << over_f << endl;
            break;
        }
    }
    
    return 0;
}
