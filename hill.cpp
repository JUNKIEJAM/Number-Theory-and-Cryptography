#include<bits/stdc++.h>
using namespace std;
 
void matrix(string key, int keyMatrix[][3]){
 
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++){
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}
 
void encryption(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
   
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 1; j++){
           
            cipherMatrix[i][j] = 0;
       
            for (int x = 0; x < 3; x++){
                    cipherMatrix[i][j] +=
                    keyMatrix[i][x] * messageVector[x][j];
            }
       
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}
 
void usinghillcipher(string str1, string str2){
 
    int keyMatrix[3][3];
    matrix(str2, keyMatrix);
 
    int messageVector[3][1];
 
    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (str1[i]) % 65;
 
    int cipherMatrix[3][1];
 
    encryption(cipherMatrix, keyMatrix, messageVector);
 
    string cipher;
 
    for (int i = 0; i < 3; i++)
        cipher += cipherMatrix[i][0] + 65;
 
    cout <<"Ciphertext: " <<cipher;
}
 
int main() {
 
string str1,str2;
cout<<"Enter the message: ";
cin>>str1;
 
cout<<"Enter the key: ";
cin>>str2;
 


    return 0;
}
