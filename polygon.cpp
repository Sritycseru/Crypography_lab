#include<bits/stdc++.h>
using namespace std;

map<string,string>encoder;
map<string,string>decoder;

string encrypt(string str,int block_size){
    string temp="",cipher_text;
    for(int i =0;i<str.size();i++){
        temp+=str[i];
        if((i+1)%block_size==0){
            cipher_text+=encoder[temp];
            temp="";
        
        }


    }
    return cipher_text;
}
string decrypt(string str,int block_size){
    string temp="",decrypt_text;
    for(int i =0;i<str.size();i++){
        temp+=str[i];
        if((i+1)%block_size==0){
            decrypt_text+=decoder[temp];
            temp="";
        
        }


    }
    return decrypt_text;
}
int main(){
    int block_size=3;
    freopen("polygon.txt","r",stdin);
    string str;
    getline(cin,str);
    cin.clear();

    freopen("dictionary.txt","r",stdin);
    string s1,s2;
    while(cin>>s1>>s2){
        encoder[s1]=s2;
        decoder[s2]=s1;
    
    }

    // for(const auto &pair:encoder){
    //     cout<<pair.first<<" "<<pair.second<<endl;
    // }

    string encrypted_message=encrypt(str,block_size);
    cout<<"encrypted_message :"<<encrypted_message<<endl;

    string decrypted_message=decrypt(encrypted_message,block_size);
    cout<<"decrypted_message :"<<decrypted_message<<endl;


}