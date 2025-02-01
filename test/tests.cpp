#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <string>

#include "../src/user.h"

using namespace std::literals;

TEST_CASE("user collect login and password and can check them", "[user]") {
    user::User user{"login"s, "password"s};

    REQUIRE(user.CheckLogin("login"s));
    REQUIRE(user.CheckPassword("password"s));

    SECTION("changing login change current login but not a password") {
        user.ChangeLogin("new_login"s);
        CHECK(user.CheckLogin("new_login"s));
        CHECK(user.CheckPassword("password"s));
    }
    
    SECTION("changing password change current password but not a login") {
        user.ChangePassword("new_password"s);
        CHECK(user.CheckPassword("new_password"s));
        CHECK(user.CheckLogin("login"s));
    }
}