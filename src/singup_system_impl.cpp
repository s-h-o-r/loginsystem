#include <stdexcept>
#include <string>
#include "../src/singup_system_impl.h"
#include "../src/user_impl.h"

using namespace std::literals;

namespace singup_system {

std::unique_ptr<user::User> SingupSystemImpl::SingupUser(const std::string& login, const std::string& password) {
    CheckLoginIsNotEmpty(login);
    CheckPasswordIsNotEmpty(password);
    return std::make_unique<user::UserImpl>(login, password);
}

void SingupSystemImpl::CheckLoginIsNotEmpty(const std::string& login) {
    if (login.empty()) throw std::logic_error("login is empty");
}

void SingupSystemImpl::CheckPasswordIsNotEmpty(const std::string& password) {
    if (password.empty()) throw std::logic_error("password is empty");
}

}  // namespace singup_system