#include <iostream>
#include <string>
using namespace std;

class Board
{
private:
    char grid[9];

public:
    Board();
    void Display();
    bool PlaceMove(int position, char symbol);
    bool IsPositionValid(int position);
    char CheckWinner();
    bool IsFull();
};

Board::Board()
{
    for (int i = 0; i < 9; i++)
    {
        grid[i] = ' ';
    }
}

void Board::Display()
{
    cout << endl;
    cout << " " << grid[0] << " | " << grid[1] << " | " << grid[2] << endl;
    cout << "-----------" << endl;
    cout << " " << grid[3] << " | " << grid[4] << " | " << grid[5] << endl;
    cout << "-----------" << endl;
    cout << " " << grid[6] << " | " << grid[7] << " | " << grid[8] << endl;
    cout << endl;
}

bool Board::IsPositionValid(int position)
{
    int index = position - 1;
    return (index >= 0 && index <= 8 && grid[index] == ' ');
}

bool Board::PlaceMove(int position, char symbol)
{
    int index = position - 1;
    if (IsPositionValid(position))
    {
        grid[index] = symbol;
        return true;
    }
    else
    {
        return false;
    }
}

char Board::CheckWinner()
{
    // Filas
    for (int i = 0; i < 9; i += 3)
    {
        if (grid[i] != ' ' && grid[i] == grid[i + 1] && grid[i + 1] == grid[i + 2])
        {
            return grid[i];
        }
    }

    // Columnas
    for (int i = 0; i < 3; i++)
    {
        if (grid[i] != ' ' && grid[i] == grid[i + 3] && grid[i + 3] == grid[i + 6])
        {
            return grid[i];
        }
    }

    // Diagonales
    if (grid[0] != ' ' && grid[0] == grid[4] && grid[4] == grid[8])
        return grid[0];
    if (grid[2] != ' ' && grid[2] == grid[4] && grid[4] == grid[6])
        return grid[2];

    return ' ';
}

bool Board::IsFull()
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i] == ' ')
            return false;
    }
    return true;
}

// PLAYER CLASS 

class Player
{
private:
    char symbol;
    string name;

public:
    Player(char symbol, string name);
    char GetSymbol();
    string GetName();
    int MakeMove();
};

Player::Player(char symbol, string name)
{
    this->symbol = symbol;
    this->name = name;
}

char Player::GetSymbol()
{
    return symbol;
}

string Player::GetName()
{
    return name;
}

int Player::MakeMove()
{
    int position;
    cout << name << " (" << symbol << "), ingresa tu movimiento (1-9): ";
    cin >> position;
    return position;
}

//  GAME CLASS 

class Game
{
private:
    Board board;
    Player* player1;
    Player* player2;
    Player* currentPlayer;

public:
    Game();
    void ShowWelcome();
    void Play();
    void PlayTurn();
    void SwitchPlayer();
};

Game::Game()
{
    player1 = new Player('X', "Jugador 1");
    player2 = new Player('O', "Jugador 2");
    currentPlayer = player1;
}

void Game::ShowWelcome()
{
    cout << "¡Bienvenido a Tres en Raya!" << endl;
    cout << "Jugador 1 es 'X' y Jugador 2 es 'O'" << endl;
    board.Display();
    cout << endl;
}

void Game::SwitchPlayer()
{
    if (currentPlayer == player1)
    {
        currentPlayer = player2;
    }
    else
    {
        currentPlayer = player1;
    }
}

void Game::PlayTurn()
{
    board.Display();
    int position;
    bool validMove = false;
    while (!validMove)
    {
        position = currentPlayer->MakeMove();
        validMove = board.PlaceMove(position, currentPlayer->GetSymbol());
        if (!validMove)
        {
            cout << "Movimiento inválido :( Intenta de nuevo." << endl;
        }
    }
}

void Game::Play()
{
    bool gameOver = false;

    while (!gameOver)
    {
        PlayTurn();

        char winner = board.CheckWinner();
        if (winner != ' ')
        {
            board.Display();
            cout << currentPlayer->GetName() << " gana! ¡Felicidades!" << endl;
            gameOver = true;
        }
        else if (board.IsFull())
        {
            board.Display();
            cout << "Empate :)" << endl;
            gameOver = true;
        }
        else
        {
            SwitchPlayer();
        }
    }
}

//MAIN 

int main()
{
    Game game;
    game.ShowWelcome();

    cout << "¿Quieres jugar? (y/n): ";
    char response;
    cin >> response;

    if (response == 'y' || response == 'Y')
    {
        game.Play();
    }
    else
    {
        cout << "¡Tal vez la próxima vez!" << endl;
    }

    return 0;
}
