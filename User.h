#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& username);
    bool registerUser(const std::string& password);
    bool loginUser(const std::string& password);

private:
    std::string username;
    std::string getUserFilePath() const;
    std::string hashPassword(const std::string& password);
};

#endif
