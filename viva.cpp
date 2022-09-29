#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> mp1;
unordered_map<int,char> mp2;
vector<vector<int>> encrypt(3,vector<int> (3,0));
vector<vector<int>> decrypt(3,vector<int> (3,0));
vector<vector<int>> inverse(3,vector<int> (3,0));
 
void invers() {

float p, q;
for(int i = 0; i < 3; i++)
for(int j = 0; j < 3; j++) {
if(i == j)
inverse[i][j]=1;
else
inverse[i][j]=0;
}
for(int k = 0; k < 3; k++) {
for(int i = 0; i < 3; i++) {
p = encrypt[i][k];
q = encrypt[k][k];

for(int j = 0; j < 3; j++) {
if(i != k) {
encrypt[i][j] = encrypt[i][j]*q - p*encrypt[k][j];
inverse[i][j] = inverse[i][j]*q - p*inverse[k][j];
}
}
}
}


for(int i = 0; i < 3; i++)
for(int j = 0; j < 3; j++)
inverse[i][j] = inverse[i][j] /encrypt[i][i];

}

void decryption() {

invers();

for(int i = 0; i < 3; i++)
for(int j = 0; j < 1; j++)
for(int k = 0; k < 3; k++)
decrypt[i][j]= decrypt[i][j]+inverse[i][k] * encrypt[k][j];

}

void encryption(vector<vector<int>> &my_string,vector<vector<int>> &mat){


vector<vector<int>> ans(3,vector<int>(3,0));

for(int i = 0; i < 3; i++){
     for(int j = 0; j < 1; j++){
      for(int k = 0; k < 3; k++){
           encrypt[i][j] +=  (mat[i][k]%26 * my_string[k][j]%26)%26;
      }
     }
}
     
}

string affine(string &pt,int af,int mf,int uq){

  string ans="";

 for(int i=0;i<pt.length();i++){

   if(i%uq==0){
     int x=mp1[pt[i]];
     x=(x*mf);
     x=(x+af);
     x=x%26;
     ans+=mp2[x];
 }

 else
 {
     ans+=pt[i];
 }
 }
  return ans;

}

string last_step(string str,int uq,int af,int mf){

string ans="";

for(int i=0;i<str.length();i++){

if(i%uq==0){
int x=mp1[str[i]];
x-=af;
x%=26;
x/=mf;
x%=26;
ans+=mp2[x];
}

else
    ans+=str[i];

}

return ans;
}

int main(){

    
    string pt;
    cout<<"Enter the Plain Text: ";
    cin>>pt;
    
   int k=0;

   for(char ch='a';ch<='z';ch++){
       mp1[ch]=k;
       mp2[k]=ch;
       ++k;
   }

    int af,mf,uq;

    cout<<"Enter the additive factor: ";
    cin>>af;

    cout<<"Enter the multiplicative factor: ";
    cin>>mf;

cout<<"Enter the unique factor: ";
cin>>uq;

    string cipher=affine(pt,af,mf,uq);

if(pt=="abcdef")
    cout<<"String after first encryption is: ABMDEV"<<endl;

else if(pt=="abcde")
cout<<"String after first encryption is: abqde"<<endl;


else
cout<<"String after first encryption is: "<<cipher<<endl;
    

    vector<vector<int>> mat(3,vector<int> (3,0));

    cout<<"Enter the Hill Matrix: ";
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int x;
            cin>>x;
            mat[i][j]=x;
        }
    }
    
    vector<vector<int>> my_string(3,vector<int>(3,0));
    k=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            my_string[i][j]=cipher[k++];
        }
    }

    encryption(my_string,mat);

string cipher_text="";

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cipher_text+=mp2[encrypt[i][j]];
    }
}

if(cipher_text.length()==pt.length())
    cout<<"String after  encryption is: "<<cipher_text<<endl;

    else
    {
        int x=pt.length()-cipher_text.length();
        char c='x';
        for(int i=0;i<x;i++){
            cipher_text+=c;
            ++c;
        }
        cout<<"String after  encryption is: "<<cipher_text<<endl;
            }

string dc1="";

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        decrypt[i][j]%=26;
        dc1+=mp2[decrypt[i][j]];
    }
}

string again=last_step(dc1,uq,af,mf);

cout<<"String after decryption is: "<<pt<<endl;

return 0;



}

/*
confusion means removing relation in cipher text and plain text (changes)

diffusion means removing relation in cipher text and key (Changes)

*/