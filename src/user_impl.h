#pragma once

#include <string>

#include "../src/user.h"

namespace user {

class UserImpl : public User {
public:
    UserImpl() = delete;
    UserImpl(const std::string& login, const std::string& password)
        : login_(login)
        , password_(password) {
    }

    UserImpl(const User& other) = delete;
    UserImpl& operator=(const UserImpl& other) = delete;

    void ChangeLogin(const std::string& new_login) override;
    void ChangePassword(const std::string& new_password) override;

    bool CheckLogin(const std::string& login_to_singin) const override;
    bool CheckPassword(const std::string& password_to_singin) const override;

private:
    std::string login_;
    std::string password_;
};

} // namespase user