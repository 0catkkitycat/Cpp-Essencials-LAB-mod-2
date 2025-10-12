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

class MinLengthValidator : public Validator
{
  private:
    int MinLength;
  public:
    MinLengthValidator(int length);
    bool IsValid(string text);
};

MinLengthValidator::MinLengthValidator(int length)
{
    this->MinLength = length;
}

bool MinLengthValidator::IsValid(string text)
{
    if (text.length() >= MinLength) {
        return true;
    }
    else {
        return false;
    }
}

class MaxLengthValidator : public Validator
{
  private:
    int MaxLength;
  public:
    MaxLengthValidator(int length);
    bool IsValid(string text);
};

MaxLengthValidator::MaxLengthValidator(int length)
{
    this->MaxLength = length;
}

bool MaxLengthValidator::IsValid(string text)
{
    if (text.length() <= MaxLength) {
        return true;
    }
    else {
        return false;
    }
}

class PatternValidator : public Validator
{
  private:
    string pattern;
    bool matchPattern(string text, int startPos);
  public:
    PatternValidator(string pattern);
    bool IsValid(string text);
};

PatternValidator::PatternValidator(string pattern)
{
    this->pattern = pattern;
}

bool PatternValidator::IsValid(string text)
{
    int limit = text.length() - pattern.length();

    for (int i = 0; i <= limit; i++) {
        if (matchPattern(text, i)) {
            return true;
        }
    }

    return false;
}

bool PatternValidator::matchPattern(string text, int startPos)
{
    for (int i = 0; i < pattern.length(); i++) {
        char patternChar = pattern[i];
        char textChar = text[startPos + i];

        if (patternChar == 'D') {
            if (!isdigit(textChar)) {
                return false;
            }
        }
        else if (patternChar == 'A') {
            if (!isalpha(textChar)) {
                return false;
            }
        }
        else if (patternChar == 'U') {
            if (!isupper(textChar)) {
                return false;
            }
        }
        else if (patternChar == 'L') {
            if (!islower(textChar)) {
                return false;
            }
        }
        else if (patternChar == 'S') {
            if (isalnum(textChar) || textChar == ' ') {
                return false;
            }
        }
        else if (patternChar == '?') {

        }
        else if (islower(patternChar)) {
            if (tolower(textChar) != patternChar) {
                return false;
            }
        }
        else {
            if (textChar != patternChar) {
                return false;
            }
        }
    }
    return true;
}

class CompositeValidator : public Validator
{
private:
    MinLengthValidator* minLength;
    PatternValidator* hasUpper;
    PatternValidator* hasLower;
    PatternValidator* hasDigit;
    PatternValidator* hasSpecial;
public:
    CompositeValidator();
    bool IsValid(string text);
};

CompositeValidator::CompositeValidator()
{
    this->minLength = new MinLengthValidator(8);
    this->hasUpper = new PatternValidator("U");
    this->hasLower = new PatternValidator("L");
    this->hasDigit = new PatternValidator("D");
    this->hasSpecial = new PatternValidator("S");
}

bool CompositeValidator::IsValid(string text)
{
    if (!minLength->IsValid(text)) {
        return false;
    }

    if (!hasUpper->IsValid(text)) {
        return false;
    }

    if (!hasLower->IsValid(text)) {
        return false;
    }

    if (!hasDigit->IsValid(text)) {
        return false;
    }

    if (!hasSpecial->IsValid(text)) {
        return false;
    }

    return true;
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

    cout << "MinLengthValidator" << endl;
    MinLengthValidator minLengthValidator(6);
    bool result4 = minLengthValidator.IsValid("Hello");
    cout << "The string 'hello' is " << (result4 ? "invalid" : "valid") << endl;
    bool result5 = minLengthValidator.IsValid("Welcome");
    cout << "The string 'welcome' is " << (result5 ? "valid" : "invalid");
    cout << endl;

    cout << "MaxLengthValidator" << endl;
    MaxLengthValidator maxLengthValidator(6);
    bool result6 = maxLengthValidator.IsValid("Hello");
    cout << "The string 'hello' is " << (result6 ? "valid" : "invalid") << endl;
    bool result7 = maxLengthValidator.IsValid("Welcome");
    cout << "The string 'welcome' is " << (result7 ? "invalid" : "valid");
    cout << endl;

    cout << "PatternValidator" << endl;
    PatternValidator patternValidator("D");
    bool result8 = patternValidator.IsValid("there are 2 types of sentences in the world");
    cout << "The string 'there are 2 types of sentences in the world' is " << (result8 ? "valid" : "invalid") << endl;
    bool result9 = patternValidator.IsValid("valid and invalid ones");
    cout << "The string 'valid and invalid ones' is " << (result9 ? "invalid" : "valid");
    cout << endl;

    cout << endl << "CompositeValidator - Password Validation:" << endl;
    CompositeValidator passwordValidator;

    bool resultPass1 = passwordValidator.IsValid("Abc123!@");
    cout << "The string 'Abc123!@' is " << (resultPass1 ? "valid" : "invalid") << endl;

    bool resultPass2 = passwordValidator.IsValid("abc123!@");
    cout << "The string 'abc123!@' is " << (resultPass2 ? "invalid" : "valid") << endl;

    bool resultPass3 = passwordValidator.IsValid("Ab1!");
    cout << "The string 'Ab1!' is " << (resultPass3 ? "invalid" : "valid") << endl;

    bool resultPass4 = passwordValidator.IsValid("Abc12345");
    cout << "The string 'Abc12345' is " << (resultPass4 ? "invalid" : "valid") << endl;

    return 0;
}