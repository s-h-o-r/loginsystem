#pragma once

#include <string>

namespace user {

class User {
public:
    virtual void ChangeLogin(const std::string& new_login) = 0;
    virtual void ChangePassword(const std::string& new_password) = 0;

    virtual bool CheckLogin(const std::string& login_to_singin) const = 0;
    virtual bool CheckPassword(const std::string& password_to_singin) const = 0;

protected:
    ~User() = default;
};

} // namespase user