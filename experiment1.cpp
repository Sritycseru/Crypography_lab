#include<bits/stdc++.h>
using namespace std;

string endc(string text,int shift){
    for(int i=0;i<text.size();i++){
        if(islower(text[i])){
            text[i]=(text[i]-'a'+shift)%26+'a';
        }
        if(isupper(text[i])){
            text[i]=(text[i]-'A'+shift)%26+'A';
        }    
    }   
    return text;
}

int main(){
    int shift;
    cout<<"Enter how many shift to the right: ";
    cin>>shift;

    freopen("caser.txt","r",stdin);
    string text;
    getline(cin,text);
    cin>>text;

    cout<<"Plain Text: "<<text<<endl;

    string encrypt=endc(text,shift);
    cout<<"Encryption Text :"<<encrypt<<endl;

    string decrypt=endc(encrypt,26-shift);
    cout<<"Decryption Text :"<<decrypt<<endl;


}