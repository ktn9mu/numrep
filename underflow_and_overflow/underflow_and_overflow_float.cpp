#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float under_f = 1.0f;
    float over_f = 1.0f;

    cout << "=== float (single precision) ====" << endl;
    
    //Underflow
    for (int i = 0; i < 2000; i++) {
	    under_f /= 2.0f;
	    if (under_f == 0.0f) {
	        cout << "Underflow at loop " << i << ", under = " << under_f <<endl;
	        break; 
	    }
    }
    
    //Overflow
    for (int i = 0; i <2000; i++) {
        over_f *= 2.0f;
        if (isinf(over_f)) {
            cout << "Overflow at loop " << i << ", over = " <<over_f << endl;
            break;
        }
    }
    
    return 0;
}
