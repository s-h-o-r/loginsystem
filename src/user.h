#pragma once

#include <string>

namespace user {

class User {
public:
    User() = delete;
    User(const std::string& login, const std::string& password)
        : login_(login)
        , password_(password) {
    }

    User(const User& other) = delete;
    User& operator=(const User& other) = delete;

    void ChangeLogin(const std::string& new_login);
    void ChangePassword(const std::string& new_password);

    bool CheckLogin(const std::string& login_to_singin);
    bool CheckPassword(const std::string& password_to_singin);

private:
    std::string login_;
    std::string password_;
};

} // namespase user