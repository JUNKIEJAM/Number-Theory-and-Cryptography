#include <iostream>
#include<vector>
using namespace std;

int main()
{
    string input,output;
    int opt,key;
    cout<<"For Encryption press 1, for decryption press 2: ";
    cin>>opt; 
    cout<<endl<<"Enter Text:";
    cin>>input;
    cout<<endl<<"Enter key:";
    cin>>key;
    if(opt==2)key=-key;
    for(int i=0;i<input.size();i++)
      {
          int diff=(input[i]-'a'+key)%26;
          if(diff<0)diff+=26;
          output+='a'+diff;
      }
    cout<<endl<<"Result:"<<output;
    return 0;
}