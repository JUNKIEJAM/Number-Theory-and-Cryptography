#include<bits/stdc++.h>
using namespace std;
 
int extendedeu(int a, int b, int* x, int* y){

    if (a == 0)    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd =extendedeu(b % a, a, &x1, &y1);
 
   
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
 
void modularInverse(int a, int m){

    int x, y;
    int g = extendedeu(a, m, &x, &y);
    
    if (g != 1)
        cout << "Inverse doesn't exist";
    
    else{
         
        int res = (x % m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }

}
  
int main(){

    int a,b;
    cout<<"Enter the number: ";
    cin>>a;

    cout<<"Enter the modulo: ";
    cin>>b;
  
    modularInverse(a, b);
    return 0;

}