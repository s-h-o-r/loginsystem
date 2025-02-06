#pragma once

#include <memory> 
#include "../src/user.h"

namespace singup_system {

class SingupSystem { // it's UserFactory
public:
    virtual ~SingupSystem() = default;

    virtual std::unique_ptr<user::User> SingupUser(const std::string& login, const std::string& password) = 0;
};

} // namespace singup_system