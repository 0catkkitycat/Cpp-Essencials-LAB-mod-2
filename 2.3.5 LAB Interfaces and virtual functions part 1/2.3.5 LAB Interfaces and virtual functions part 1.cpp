#include <iostream>
#include <string>
using namespace std;

class Validator {
    virtual bool IsValid(string text) = 0;
};

class PasswordValidator : public Validator 
{
  private:
    string password;
  public:
    PasswordValidator(string password);
    bool IsValid(string text);
};

PasswordValidator::PasswordValidator(string password) 
{
    this->password = password;
}

bool PasswordValidator::IsValid(string text) 
{
    if (text == password) {
        return true;
    }
    else {
        return false;
    }
}

int main() 
{
    PasswordValidator validator1("hello");
    bool result1 = validator1.IsValid("hello");
    cout << "The string 'hello' is " << (result1 ? "valid" : "invalid") << endl;

    bool result2 = validator1.IsValid("world");
    cout << "The string 'hello' is " << (result2 ? "valid" : "invalid") << endl;

    PasswordValidator validator2("secret");
    bool result3 = validator2.IsValid("secret");
    cout << "The string 'secret' is " << (result3 ? "valid" : "invalid") << endl;
}