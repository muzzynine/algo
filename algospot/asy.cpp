#include <iostream>
 
using namespace std;
 
int main(void)
{
    int mod = 1000000007;
 
    int count;
    int input;
 
    int fibo2;
    int fibo1;
    int fibo;
 
    cin >> count;
 
    while (count--) {
        fibo2 = 0;
        fibo1 = 1;
        fibo = 0;
 
        cin >> input;
        if (input <= 2) {
            cout << 0 << endl;
            continue;
        }
 
        int p1=0, p2=0;
 
        for (int i = 1; i <= input; i++) {
            fibo = (fibo1 + fibo2) % mod;
            if (i == input / 2) {
                p1 = fibo1;
                p2 = fibo;
            }
 
            fibo2 = fibo1 % mod;
            fibo1 = fibo % mod;
 
        }
        
        if (input & 1) {  //input is odd
            p1 = 0;
        }
        cout << (fibo - (p1 + p2)%mod + mod)%mod <<endl;
    }
    //end while
    
    return 0;
}
