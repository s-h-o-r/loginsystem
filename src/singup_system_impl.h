#pragma once

#include <memory>

#include "singup_system.h"
#include "user.h"

namespace singup_system {

class SingupSystemImpl : public SingupSystem {
public:
    std::unique_ptr<user::User> SingupUser(const std::string& login, const std::string& password) override;

private:
    void CheckLoginIsNotEmpty(const std::string& login);
    void CheckPasswordIsNotEmpty(const std::string& password);
};

} // namespace singup_system