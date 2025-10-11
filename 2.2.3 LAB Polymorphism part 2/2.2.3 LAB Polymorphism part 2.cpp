#include <iostream>
using namespace std;

// ---------- Base Class (Abstract)
class Piece {
public:
    virtual bool checkMove(const string& from, const string& to) = 0;
    virtual ~Piece() {}
};

// ---------- Class Man ----------
class Man : public Piece {
public:
    bool checkMove(const string& from, const string& to) override {
        int fromCol = from[0] - 'a' + 1;
        int fromRow = from[1] - '0';
        int toCol = to[0] - 'a' + 1;
        int toRow = to[1] - '0';

        int colDiff = abs(toCol - fromCol);
        int rowDiff = abs(toRow - fromRow);

        // A man can only move one square diagonally
        if (colDiff == 1 && rowDiff == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};

// ---------- Class King ----------
class King : public Piece {
public:
    bool checkMove(const string& from, const string& to) override {
        int fromCol = from[0] - 'a' + 1;
        int fromRow = from[1] - '0';
        int toCol = to[0] - 'a' + 1;
        int toRow = to[1] - '0';

        int colDiff = abs(toCol - fromCol);
        int rowDiff = abs(toRow - fromRow);

        // A king can move any number of squares diagonally
        if (colDiff == rowDiff && colDiff > 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

// ---------- Main Function ----------
int main() {
    Man man;
    King king;

    // Check 1: Man from b1 to c2
    if (man.checkMove("b1", "c2")) {
        cout << "Man: b1 -> c2  Movimiento valido" << endl;
    }
    else {
        cout << "Man: b1 -> c2  Movimiento no valido" << endl;
    }

    // Check 2: King from b1 to d3
    if (king.checkMove("b1", "d3")) {
        cout << "King: b1 -> d3  Movimiento valido" << endl;
    }
    else {
        cout << "King: b1 -> d3  Movimiento no valido" << endl;
    }

    // Check 3: Man from b1 to d3
    if (man.checkMove("b1", "d3")) {
        cout << "Man: b1 -> d3  Movimiento valido" << endl;
    }
    else {
        cout << "Man: b1 -> d3  Movimiento no valido" << endl;
    }

    return 0;
}
