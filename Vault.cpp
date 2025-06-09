#include "Vault.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


Vault::Vault(const  string& owner , const string& key):owner(owner),key(key),filePath("data/" + owner + ".vlt"){}
string Vault::encrypt(const string& text)const {
    string result = text;
    for(size_t i = 0;i<result.size();i++){
        result[i]^=key[i % key.length()];

    }
    return result;
}

string Vault::decrypt(const string& text) const{
    return encrypt(text);
}

void Vault::load(){
    Credentials.clear();
    ifstream file(filePath);
    if(!file) return;
    
    string line;
    while(getline(file,line)) {
        istringstream iss(decrypt(line));
        Credential cred;
        getline(iss,cred.service, '|');
        getline(iss,cred.username, '|');
        getline(iss,cred.password, '|');
        Credentials.push_back(cred);

    }
}
void Vault::save() const {
    std::ofstream file(filePath);
    for(const auto& cred: Credentials){
        ostringstream oss;
        oss<< cred.service <<'|'<<cred.username <<'|'<<cred.password <<'|';
        file << encrypt(oss.str()) << "\n";

    }
}

void Vault::addCreds(const Credential& cred) {
    Credentials.push_back(cred);
    save();
}

void Vault::listCreds() const {
    if(Credentials.empty()) {
        cout << "No credentials to show";
        return;
    }
    for(size_t i = 0 ;i<Credentials.size();++i){
        cout<<i + 1<< "." << Credentials[i].service
            <<" - " << Credentials[i].username << " \n" ; 
    }
}
void Vault :: deleteCreds(int index) {
    if( index < 1 || index> static_cast<int>(Credentials.size())) {
        cout << "Invalid index . \n ";
        return ;
    }
    Credentials.erase(Credentials.begin() + (index - 1));
    save();
}