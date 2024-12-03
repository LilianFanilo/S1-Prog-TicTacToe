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

void play(struct Player& player , std::array<char, 9>& game_board)
{
    int number {};
    while (!number > 0 && !number < 8)
    {
        std::cout << "Entrez un nombre entre 1 et 9" << std::endl;
        std::cin >> number;
        number --;
        if (game_board[number] == ' ')
        {
            game_board[number] = player.symbol;
            break;
        }
        else
        {
            std::cout << "DEJA PRIS" << std::endl;
        }
    }
    
}

bool is_player_winning(std::array<char, 9>& game_board)
{

    if (game_board[0] == 'X')
    {
        return true;
    }
    else
    {
        return false;
    }
    

}

int main()
{   
    std::system("CLS");

    int game_mode {};
    std::array<char, 9> game_board{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

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

        Player player2;
        player2.create_player();

    }
    else if (game_mode == 2)
    {
        Player player;
        player.create_player();

        draw_game_board(game_board);

        while (is_player_winning(game_board) == false)
        {
            play(player, game_board);
            draw_game_board(game_board);
        }
        
    }
    
    return 0;
}