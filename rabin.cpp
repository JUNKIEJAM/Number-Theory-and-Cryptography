#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int p = 151, q = 43; 

int n = p * q;        

int encrypter(int m, int n)
{
    int c = (m * m)%n;    
    return c;
}

int mod(int k, int b, int m) 
{
    int i=0;
    int a=1;
   
    vector<int> t;
   
    while(k>0){
        t.push_back(k%2);
        k=(k-t[i])/2;
        i++;
    }
   
    for(int j=0; j<i; j++){
   
        if(t[j]==1){
            a=(a*b)%m;
            b=(b*b)%m;
        } 
        
        else{
            b=(b*b)%m;
        }
    }
    
    return a;
}

int modulo (int a, int b)
{
    return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b;
}

vector<int> Extended_Euclid(int a, int b)
{
    if (b>a) {
        int temp=a; a=b; b=temp;
    }
    int x=0;
    int y=1;
    int lastx=1;
    int lasty=0;
    while (b!=0) {
        int q= a/b;
        int temp1= a%b;
        a=b;
        b=temp1;
        int temp2 = x;
        x=lastx-q*x;
        lastx = temp2;
        int temp3 = y;
        y = lasty-q*y;
        lasty=temp3;
    }
    vector<int>arr(3);
    arr[0] = lastx;
    arr[1] = lasty;
    arr[2] = 1;
    return arr;
}

int decrypter(int c, int p, int q)
{
    int mp = mod((p+1)/4, c, p);
    int mq = mod((q+1)/4, c, q);

    vector<int> arr = Extended_Euclid(p, q);
    
    int rootp = arr[0]*p*mq;
    
    int rootq = arr[1]*q*mp;
    
    double r = modulo((rootp+rootq), n);
    
    if( r < 128)
        return r;
    
    int negative_r = n - r;
   
   
    if (negative_r < 128)
        return negative_r;
   
    int s = modulo((rootp-rootq), n);
   
    if( s < 128)
        return s;
   
    int negative_s = n - s;
        return negative_s;

}

int main()
{
    vector<int> e; 
    vector<int> d; 
    
    cout << "Plain text: " << message << endl;
    int len = strlen(message.c_str());

    cout << "Encrypted text: ";
    for(int i = 0; i <= len; i++)
    {
        e.push_back(encrypter(message[i], n));
        cout << e[i];
    }

    cout << endl;

    for(int i = 0; i < len; i++)
    {
        d.push_back(decrypter(e[i], p, q));
    }
    cout << "Decrypted text: ";
    for(int i=0;i<d.size();i++)
      cout << char(d[i]);

    cout << endl;
    return 0;
}