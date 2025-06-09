#ifndef VAULT_H
#define VAULT_H
using namespace std;

#include <string>
#include <vector>

struct Credential {
    string password;
    string username;
    string service;

};

class Vault {
    public:
        Vault(const string& owner , const string& key);
        void load();
        void save() const;

        void addCreds(const Credential& cred);
        void listCreds() const;
        void deleteCreds(int index);
    private:
     string owner;
     string key;
     string filePath;
     vector<Credential> Credentials;

    string encrypt(const string& text) const;
     string decrypt(const string& text) const;
};
#endif

