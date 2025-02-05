#include "user_impl.h"

namespace user {

void UserImpl::ChangeLogin(const std::string& new_login) {
    login_ = new_login;
}

void UserImpl::ChangePassword(const std::string& new_password) {
    password_ = new_password;
}

bool UserImpl::CheckLogin(const std::string& login_to_singin) const {
    return login_ == login_to_singin;
}

bool UserImpl::CheckPassword(const std::string& password_to_singin) const {
    return password_ == password_to_singin;
}

} // namespace user
