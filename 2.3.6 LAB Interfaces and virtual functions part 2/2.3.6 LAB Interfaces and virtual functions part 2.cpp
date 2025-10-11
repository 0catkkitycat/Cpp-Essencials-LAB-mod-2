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
    if (text.find(pattern) != string::npos) {
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

    cout << "MinLengthValidator" << endl;
	MinLengthValidator minLengthValidator(6);
    bool result4 = validator1.IsValid("Hello"); //invalid
    cout << "The string 'hello' is " << +(result4 ? "valid" : "invalid") << endl;
    bool result5 = validator1.IsValid("Welcome"); //valid
    cout << "The string 'welcome' is " << (result5 ? "invalid" : "valid");
    cout << endl;

	cout << "MaxLengthValidator" << endl;
    MaxLengthValidator maxLengthValidator(6);
    bool result6 = validator1.IsValid("Hello"); //valid
    cout << "The string 'hello' is " << +(result6 ? "invalid" : "valid") << endl;
	bool result7 = validator1.IsValid("Welcome"); //invalid
    cout << "The string 'welcome' is " << (result7 ? "valid" : "invalid");
	cout << endl;

    cout << "PatternValidator" << endl;
	PatternValidator patternValidator("D");
    bool result8 = validator1.IsValid("The string 'there are 2 types of sentences in the world'"); //valid
    cout << "The string 'there are 2 types of sentences in the world' is " << (result8 ? "invalid" : "valid") << endl;
	bool result9 = validator1.IsValid("The string 'valid and invalid ones'"); //invalid
    cout << "The string 'valid and invalid ones' is " << (result9 ? "valid" : "invalid");
    cout << endl;
	return 0;


}