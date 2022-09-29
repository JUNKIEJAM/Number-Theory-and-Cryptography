#include<bits/stdc++.h>
using namespace std;
 
float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];


 
void inverse() {

float p, q;
for(int i = 0; i < 3; i++)
for(int j = 0; j < 3; j++) {
if(i == j)
b[i][j]=1;
else
b[i][j]=0;
}
for(int k = 0; k < 3; k++) {
for(int i = 0; i < 3; i++) {
p = c[i][k];
q = c[k][k];
for(int j = 0; j < 3; j++) {
if(i != k) {
c[i][j] = c[i][j]*q - p*c[k][j];
b[i][j] = b[i][j]*q - p*b[k][j];
}
}
}
}
for(int i = 0; i < 3; i++)
for(int j = 0; j < 3; j++)
b[i][j] = b[i][j] / c[i][i];
cout<<"\n\nInverse Matrix is:\n";
for(int i = 0; i < 3; i++) {
for(int j = 0; j < 3; j++)
cout<<b[i][j]<<" ";
cout<<"\n";
}
}

void encryption() {
 
   for(int i = 0; i < 3; i++)
     for(int j = 0; j < 1; j++)
      for(int k = 0; k < 3; k++)
           encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

cout<<"The encrypted string is: "<<endl;

for(int i = 0; i < 3; i++)
     cout<<(char)(fmod(encrypt[i][0], 26) + 97);

}
 
void decryption() {

inverse();

for(int i = 0; i < 3; i++)
for(int j = 0; j < 1; j++)
for(int k = 0; k < 3; k++)
decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
cout<<"The Decrypted string is: "<<endl;

for(int i = 0; i < 3; i++)
cout<<(char)(fmod(decrypt[i][0], 26) + 97);

cout<<"\n";

}
 
void getKeyMessage() {

char msg[3];
 
cout<<"Enter 3x3 matrix for key (It should be inversible):\n";
for(int i = 0; i < 3; i++)
for(int j = 0; j < 3; j++) {

cin>>a[i][j];
c[i][j] = a[i][j];
}

cout<<" Enter a 3 letter string: ";

cin>>msg;
for(int i = 0; i < 3; i++)
mes[i][0] = msg[i] - 97;
}


int main() {
getKeyMessage();
encryption();
decryption();
}
 