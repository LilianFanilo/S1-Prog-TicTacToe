#include <iostream>
#include <array>
#include <conio.h>

struct Player
{
    std::string name {};
    char symbol {"X" || "O"};

    void create_player();
};

void Player::create_player()
{
    std::cout << "ENTRER VOTRE NOM :" << std::endl;
    std::cin >> this->name;

    std::cout << "CHOISISSEZ VOTRE SYMBOLE ( X ou O ) :" << std::endl;
    std::cin >> this->symbol;

    std::cout << "Nom du joueur : " << this->name << std::endl;
    std::cout << "Symbole choisi : " << this->symbol << std::endl;

};

void draw_game_board(std::array<char, 9>& game_board)
{
    for (int i = 0; i < game_board.size(); i++)
    {   
        std::cout << "| " << game_board[i] << " " ;

        if (i == 2 || i == 5 || i == 8)
        {
            std::cout << "|" << std::endl;
        }
    }

    std::cout << std::endl ;

}

void play()
{
    std::cout << "Au tour du joueur 1, ecrivez le numero de la case a remplir (1-9):" << std::endl;
    std::cout << std::endl ;

    std::cout << "Tableau de reference" << std::endl;

    for (int i = 0; i < 9; i++)
    {   
        std::cout << "| " << i + 1 << " " ;

        if (i == 2 || i == 5 || i == 8)
        {
            std::cout << "|" << std::endl;
        }
    }

    std::cout << std::endl ;
}

void is_winning()
{
    
}

int main()
{   
    int game_mode {};

    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;
    std::cout << "Veuillez choisir un mode de jeu :" << std::endl ;
    std::cout << "1. Joueur contre Joueur" << std::endl ;
    std::cout << "2. Joueur contre IA" << std::endl ;
    std::cin >> game_mode ;

    std::system("CLS");

    if (game_mode == 1)
    {
        Player player;
        player.create_player();
    }
    else if (game_mode == 2)
    {
        Player player;
        player.create_player();
    }

    std::array<char, 9> game_board{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    draw_game_board(game_board);
    play();

    

}