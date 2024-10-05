#include<bits/stdc++.h>
using namespace std;

string encrypt(string str,int width){
    string encrypt_msg="";
    int temp;
    for(int i=0;i<width;i++){
        temp=i;
        while(temp<str.size()){
            encrypt_msg+=str[temp];
            temp+=width;
        }

    }
    return encrypt_msg;
}

string decrypt(string str,int width){
    string decrypt_msg="";
    int partition=ceil((str.size()*1.0)/width);
    //cout<<partition<<endl;
    int extra=str.size()%width;
    //cout<<extra;

    for(int i=0;i<partition;i++){
        int regulate=0,temp=i;
        while(temp<str.size()){
            if(decrypt_msg.size()<str.size())
            decrypt_msg+=str[temp];
            regulate++;
            if(regulate>extra && regulate!=0){
                temp+=(partition-1);
            }
            else{
                temp+=partition;
            }
        }
    }
    return decrypt_msg;
}
int main(){
    int width=5;
    freopen("transposition.txt","r",stdin);
    string str;
    getline(cin,str);

    cout<<"Plain_Text :"<<str<<endl;

    string encrypted_message=encrypt(str,width);
    cout<<"Transposition Message :"<<encrypted_message<<endl;

    string double_transposition_encrypt_message=encrypt(encrypted_message,width);
    cout<<"Double Transposition encrypted Message :"<<double_transposition_encrypt_message<<endl;

    string decrypt_message1=decrypt(double_transposition_encrypt_message,width);
    //cout<<"decrypt_message2 :"<<decrypt_message2<<endl;

    string decrypt_Transposition_message=decrypt(decrypt_message1,width);
    cout<<"decrypt Transposition message :"<< decrypt_Transposition_message<<endl;

    

    





}