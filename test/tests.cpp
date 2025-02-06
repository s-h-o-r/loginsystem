#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include <string>

#include "../src/user_impl.h"
#include "../src/singup_system_impl.h"

using namespace std::literals;

TEST_CASE("user collect login and password", "[user]") {
    user::UserImpl user{"login"s, "password"s};

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

TEST_CASE("SingupSystem creates new users", "[singup]") {
    singup_system::SingupSystemImpl singup_system;
    
    auto new_user = singup_system.SingupUser("login"s, "password"s);
    
    SECTION("singup system prepares new user with set login and password") {
        CHECK(new_user->CheckLogin("login"s));
        CHECK(new_user->CheckPassword("password"s));
    }

    SECTION("if login or password is empty throw an exception") {
        CHECK_THROWS_AS(singup_system.SingupUser(""s, "password"s), std::logic_error);
        CHECK_THROWS_AS(singup_system.SingupUser("login"s, ""s), std::logic_error);

    }
}