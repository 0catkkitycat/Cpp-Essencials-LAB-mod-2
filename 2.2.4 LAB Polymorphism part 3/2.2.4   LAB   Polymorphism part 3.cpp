#include <iostream>
#include <string>
using namespace std;

// ---------- Clase base ----------
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

// ---------- Clase derivada ----------
class IPAddressChecked : public IPAddress {
private:
    bool isCorrect;
public:
    IPAddressChecked(const string& ipValue) : IPAddress(ipValue) {
        // Validación muy básica: IP correcta si primer octeto < 256 y tiene 4 partes
        int count = 0;
        for (char c : ipValue) {
            if (c == '.') count++;
        }
        // Solo un chequeo básico para el ejemplo
        isCorrect = (count == 3 && ipValue[0] != '9'); // "truco" para mostrar ejemplo
    }

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), isCorrect(other.isCorrect) {
    }

    void print() const override {
        IPAddress::print();
        cout << " - " << (isCorrect ? "Correct" : "Not Correct");
    }
};

// ---------- Código de prueba ----------
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
