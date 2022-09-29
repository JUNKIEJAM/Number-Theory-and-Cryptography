#include<bits/stdc++.h>
#include<math.h>
using namespace std;

float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];

int findinverse(int key)
{
for (int x = 1; x < 26; x++)
        if (((key%26) * (x%26)) % 26 == 1)
            return x;
}
/*string multiplicativedecrypt(string text,int a,int b)
{
	int key;
	cout<<"Enter key for multiplicative cipher:- "<<endl;
	cin>>key;
		key = findinverse(key);
    string result = text;
    for(int i = 0; i < a; ++i)
    {
        if(isupper(text[i]))
        {
            result[i] = (char)(((int)text[i]*key-65)%26+65);
        }
        else
        {
            result[i] = (char)(((int)text[i]*key-97)%26+97);
        }
    }
    int counter=a+b;
    while(counter<text.size())
    {
      if(isupper(text[counter])) {
          result[counter] = char(int((text[counter] - 65) * key) % 26 + 65);
      } else {
          result[counter] = char(int((text[counter] - 97) * key) % 26 + 97);
      }
      counter+=(b+1);
    }
    return result;
}

string multiplicativeencrypt(string text,int a,int b)
{
	int key;
	cout<<"Enter key for multiplicative cipher:- "<<endl;
	cin>>key;

    string result = text;
    for(int i = 0; i < a; ++i)
    {
        if(isupper(text[i])) {
            result[i] = char(int((text[i] - 65) * key) % 26 + 65);
        } else {
            result[i] = char(int((text[i] - 97) * key) % 26 + 97);
        }
    }
    int counter=a+b;
    while(counter<text.size())
    {
      if(isupper(text[counter])) {
          result[counter] = char(int((text[counter] - 65) * key) % 26 + 65);
      } else {
          result[counter] = char(int((text[counter] - 97) * key) % 26 + 97);
      }
      counter+=(b+1);
    }
    return result;
}
*/
string encryption()
{
int i, j, k;
for(i = 0; i < 3; i++)
for(j = 0; j < 1; j++)
for(k = 0; k < 3; k++)
encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
string temp="";
for(i = 0; i < 3; i++)
temp = temp+(char)(fmod(encrypt[i][0], 26) + 97);
return temp;
}

string hillencrypt(string temp) {
int i, j;
string msg;
string result="";

cout<<"Enter 3x3 matrix key for hill cipher (It should be inversible):\n";
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++) {
cin>>a[i][j];
c[i][j] = a[i][j];
}

int x=0;
while(x<temp.length()){
	msg = temp.substr(x,x+3);
	x+=3;
	for(i = 0; i < 3; i++)
mes[i][0] = msg[i] - 97;

string str = encryption();
result+=str;
}
return result;
}

void inverse() {
int i, j, k;
float p, q;
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++) {
if(i == j)
b[i][j]=1;
else
b[i][j]=0;
}
for(k = 0; k < 3; k++) {
for(i = 0; i < 3; i++) {
p = c[i][k];
q = c[k][k];
for(j = 0; j < 3; j++) {
if(i != k) {
c[i][j] = c[i][j]*q - p*c[k][j];
b[i][j] = b[i][j]*q - p*b[k][j];
}
}
}
}
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++)
b[i][j] = b[i][j] / c[i][i];
}

string hilldecrypt() {
int i, j, k;
inverse();
for(i = 0; i < 3; i++)
for(j = 0; j < 1; j++)
for(k = 0; k < 3; k++)
decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
string result = "";
for(i = 0; i < 3; i++)
result+=(char)(fmod(decrypt[i][0], 26) + 97);
return result;
}


string affine(string &pt,int af,int mf,int uq){

  string ans="";

 for(int i=uq;i<pt.length();i+=uq){

     int x=mp1[pt[i]];
     x=(x*mf)%26;
     x=(x+af)%26;
     x=x%26;
     ans+=mp2[x];
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


int main() {
    string plaintext;
    cout<<"Enter Plaintext:- "<<endl;
    cin>>pt;
    int a1,b1;
    cout<<"Enter the additive factor: ";
    cin>>a1;
    cout<<"Enter the multiplicative factor: ";
    cin>>b1;

    cout<<"Enter the unique factor: ";
    cin>>uq;

    string pt2=affine(pt,a1,b1,uq);


 
	cout<<"----ENCRYPTION-----"<<endl;
	//string temp = multiplicativeencrypt(pt2,a1,b1);
	//cout<<"After multiplicative encryption cipher:- "<<endl;
	//cout<<temp<<endl;
	string result = hillencrypt(pt2);
	cout<<"After hill encryption cipher:- "<<endl;
	cout<<result<<endl;
	string ciphertext = "";
	int j=0;
	for(int i=1;i<=plaintext.length() && j<result.length();i++){
    	if(i%2==0)
		 ciphertext+=plaintext[i-1];
		else{
		  ciphertext+=result[j];
		  j++;
		}
	}
	cout<<"Ciphertext:- "<<ciphertext<<endl;

	cout<<"----DECRYPTION-----"<<endl;
	string cipheroddtext = "";
	string ciphereventext = "";
    for(int i=1;i<=ciphertext.length();i++){
    	if(i%2==0)
		 ciphereventext+=ciphertext[i-1];
		else
		 cipheroddtext+=ciphertext[i-1];
	}

	string result2 = hilldecrypt();
	cout<<"After hill decryption cipher:- "<<endl;
	cout<<temp<<endl;

string final=last_step(result2,a1,b1,uq);
//	string temp2 = multiplicativedecrypt(result2,a1,b1);
//	cout<<"After multiplicative decryption cipher:- "<<endl;
//	cout<<pt<<endl;

cout<<"The decrypted string is: "<<final;
    return 0;
}