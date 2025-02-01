#include "user.h"

namespace user {

void User::ChangeLogin(const std::string& new_login) {
    login_ = new_login;
}

void User::ChangePassword(const std::string& new_password) {
    password_ = new_password;
}

bool User::CheckLogin(const std::string& login_to_singin) {
    return login_ == login_to_singin;
}

bool User::CheckPassword(const std::string& password_to_singin) {
    return password_ == password_to_singin;
}

} // namespace user
