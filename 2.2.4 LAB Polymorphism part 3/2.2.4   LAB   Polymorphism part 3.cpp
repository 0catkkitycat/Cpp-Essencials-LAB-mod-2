#include <iostream>
#include <string>
using namespace std;


class IPAddress {
protected:
    string ip;
public:
    IPAddress(const string& ipValue) : ip(ipValue) {}
    IPAddress(const IPAddress& other) : ip(other.ip) {}

    virtual void print() const {
        cout << ip;
    }
};


class IPAddressChecked : public IPAddress {
private:
    bool isCorrect;
public:
    IPAddressChecked(const string& ipValue) : IPAddress(ipValue) {

        int count = 0;
        for (char c : ipValue) {
            if (c == '.') count++;
        }

        isCorrect = (count == 3 && ipValue[0] != '9'); 
    }

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), isCorrect(other.isCorrect) {
    }

    void print() const override {
        IPAddress::print();
        cout << " - " << (isCorrect ? "Correct" : "Not Correct");
    }
};


int main() {
    string ip1, ip2, ip3;
    cin >> ip1 >> ip2 >> ip3;

    IPAddress a(ip1);
    IPAddressChecked b(ip2);
    IPAddressChecked c(ip3);

    a.print(); cout << endl;
    b.print(); cout << endl;
    c.print(); cout << endl;

    return 0;
}
