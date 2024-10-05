#include<bits/stdc++.h>
using namespace std;

string encrypt(string plain_text,string key){
    string cipher_text="";
    string temp;
    for(int i=0;i<plain_text.size();i++){
         if(islower(plain_text[i])){
            cipher_text+=((plain_text[i]-'a')+(key[i]-'a')+1)%26+'a';
        }
        if(isupper(plain_text[i])){
            cipher_text+=((plain_text[i]-'A')+(key[i]-'A')+1)%26+'A';
        }
    }
    return cipher_text;
}

string decrypt(string cipher_text,string key){
    string decipher_text="";
    for(int i=0;i<cipher_text.size();i++){
        int temp;
        if(islower(cipher_text[i])){
            temp=cipher_text[i]-key[i]-1;
            if(temp<0){
                decipher_text+=temp+26+'a';
            }
            else
                decipher_text+=temp+'a';
        }
        
        else if(isupper(cipher_text[i])){
          temp=cipher_text[i]-key[i]-1;
            if(temp<0){
                decipher_text+=temp+26+'A';
            }
            else
                decipher_text+=temp+'A';
        
        }
        
    }
    return decipher_text;
}


int main()
{
   freopen("message.txt","r",stdin);
   string plain_text;
   getline(cin,plain_text);
   //cout<<plain_text<<endl;
   cin.clear();

   freopen("key_sequence.txt","r",stdin);
   string key;
   getline(cin,key);
   //cout<<key<<endl;

    if (plain_text.size() != key.size()) {
        cout << "Error: Plaintext and key must be the same length!" << endl;
        return 1;
    }

    string encrypt_msg=encrypt(plain_text,key);
    cout<<"encrypt_msg :"<<encrypt_msg<<endl;

    string decrypt_msg=decrypt(encrypt_msg,key);
    cout<<"decrypt_msg :"<<decrypt_msg<<endl;

}
