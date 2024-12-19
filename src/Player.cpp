#include "Player.hpp"

void Player::create_player()
{
    std::cout << "ENTRER VOTRE NOM :" << std::endl;
    std::cin >> this->name;

    std::cout << "CHOISISSEZ VOTRE SYMBOLE ( X ou O ) :" << std::endl;
    std::cin >> this->symbol;

    std::cout << "Nom du joueur : " << this->name << std::endl;
    std::cout << "Symbole choisi : " << this->symbol << std::endl;
}