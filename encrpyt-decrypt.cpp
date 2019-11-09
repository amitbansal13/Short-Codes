#include<iostream>
#include<cstdlib>
using namespace std;
string encrypt(string text){
	string ans="";
	for(int i=0;i<text.size();i++){
		ans+='A'+(text[i]-'A'+rand())%26;
	}
	return ans;
}
string decrypt(string text){
	string ans="";
	for(int i=0;i<text.size();i++){
		int shift=(text[i]-'A'-rand()+26)%26;
		if(shift<0)
			shift+=26;
		ans+='A'+shift;//take care of negative values
	}
	return ans;
}
int main(){
	cout<<"What operation do you want to perform E-Encryption D-Decryption: ";
	char c;
	cin>>c;
	int key;
	cout<<"Enter a key: ";
	cin>>key;
	srand(key);
	string text;
	cout<<"Enter a text: ";
	cin>>text;
	if(c=='e' || c=='E'){
		cout<<"Encrypted String: "<<encrypt(text)<<"\n";
	}
	else{
		cout<<"Decrypted String: "<<decrypt(text)<<"\n";
	}
}