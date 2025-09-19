#include <string>
#ifndef SECURITY_CHECK_H
#define SECURITY_CHECK_H

class Password {
    private:
        bool good_length();
        bool check_symbol();
        bool check_numbers();
        bool check_CASE();
        bool check_case();
        bool int_repeats();
        bool char_repeats();
        std::string rand_password();

        std::string password;
    public:
        Password(std::string password): password(password){}
        Password():password(rand_password()){}

        bool safe_password();
};

#endif