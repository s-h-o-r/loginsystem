#pragma once

#include <string>

namespace login_system {

class LoginSystem {
public:
    virtual ~LoginSystem() = default;
    virtual bool Login(const std::string& login, const std::string& password) = 0;
};

} // namspace login_system