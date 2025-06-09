#include "User.h"
#include <fstream>
#include <sstream>
#include <functional>  // std::hashu
using namespace std;


User::User(const std::string& username) : username(username){}
string User::getUserFilePath()const {
    return "data/" + username + ".lkb";

}
string User::hashPassword(const string& password){
    hash<string> hasher;
    return to_string(hasher(password));
}

bool User :: registerUser(const string& password){
    std:: ofstream file(getUserFilePath());
    if(!file) return false;

    file << hashPassword(password);
    file.close();
    return true;
}

bool User :: loginUser(const string& password){
    std:: ifstream file(getUserFilePath());
    if(!file) return false;
    string storeHash;
    file>>storeHash;
    return storeHash == hashPassword(password);
}
