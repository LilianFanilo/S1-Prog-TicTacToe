#include <iostream>
#include <array>
#include <conio.h>
#include <cstdlib>

struct Player
{
    std::string name{};
    char symbol{"X" || "O"};

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

void draw_game_board(std::array<char, 9> &game_board)
{
    for (int i = 0; i < game_board.size(); i++)
    {
        std::cout << "| " << game_board[i] << " ";

        if (i == 2 || i == 5 || i == 8)
        {
            std::cout << "|" << std::endl;
        }
    }

    std::cout << std::endl;
}

void show_ref_board(std::array<char, 9> &game_board)
{
    std::cout << "Aide :" << std::endl;

    for (int i = 0; i < game_board.size(); i++)
    {
        std::cout << "| " << i + 1 << " ";

        if (i == 2 || i == 5 || i == 8)
        {
            std::cout << "|" << std::endl;
        }
    }

    std::cout << std::endl;
}

void player_move(struct Player &player, std::array<char, 9> &game_board)
{
    int number{};
    while (!number > 0 && !number < 8)
    {
        std::cout << "Entrez un nombre entre 1 et 9" << std::endl;
        std::cin >> number;
        number--;
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

void AI_move_easy(std::array<char, 9> &game_board)
{
    int random_number{};
    int occupied_case{true};
    while (occupied_case == true)
    {
        int random_number = rand() % 9;
        if (game_board[random_number] == ' ')
        {
            occupied_case = false;
            game_board[random_number] = 'O';
        }
    }
}

bool is_player_winning(struct Player &player, std::array<char, 9> &game_board)
{
    if (game_board[0] == player.symbol && game_board[1] == player.symbol && game_board[2] == player.symbol)
    {
        std::cout << "Victoire de " << player.name << std::endl;
        return true;
    }
    else if (game_board[3] == player.symbol && game_board[4] == player.symbol && game_board[5] == player.symbol)
    {
        std::cout << "Victoire de " << player.name << std::endl;
        return true;
    }
    else if (game_board[6] == player.symbol && game_board[7] == player.symbol && game_board[8] == player.symbol)
    {
        std::cout << "Victoire de " << player.name << std::endl;
        return true;
    }
    else if (game_board[0] == player.symbol && game_board[3] == player.symbol && game_board[6] == player.symbol)
    {
        std::cout << "Victoire de " << player.name << std::endl;
        return true;
    }
    else if (game_board[1] == player.symbol && game_board[4] == player.symbol && game_board[7] == player.symbol)
    {
        std::cout << "Victoire de " << player.name << std::endl;
        return true;
    }
    else if (game_board[2] == player.symbol && game_board[5] == player.symbol && game_board[8] == player.symbol)
    {
        std::cout << "Victoire de " << player.name << std::endl;
        return true;
    }
    else if (game_board[0] == player.symbol && game_board[4] == player.symbol && game_board[8] == player.symbol)
    {
        std::cout << "Victoire de " << player.name << std::endl;
        return true;
    }
    else if (game_board[2] == player.symbol && game_board[4] == player.symbol && game_board[6] == player.symbol)
    {
        std::cout << "Victoire de " << player.name << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(time(NULL));

    int game_mode{};
    std::array<char, 9> game_board{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;
    std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Joueur contre Joueur" << std::endl;
    std::cout << "2. Joueur contre IA" << std::endl;
    std::cin >> game_mode;

    if (game_mode == 1)
    {
        Player player;
        player.create_player();

        Player player2;
        player2.create_player();

        draw_game_board(game_board);

        while (is_player_winning(player, game_board) == false && is_player_winning(player2, game_board) == false)
        {
            show_ref_board(game_board);
            player_move(player, game_board);
            draw_game_board(game_board);
            player_move(player2, game_board);
            draw_game_board(game_board);
        }
    }
    else if (game_mode == 2)
    {
        Player player;
        player.create_player();

        Player AI;
        AI.name = "IA";
        AI.symbol = 'O';

        draw_game_board(game_board);

        while (is_player_winning(player, game_board) == false && is_player_winning(AI, game_board) == false)
        {
            show_ref_board(game_board);
            player_move(player, game_board);
            AI_move_easy(game_board);
            draw_game_board(game_board);
        }
    }

    return 0;
}