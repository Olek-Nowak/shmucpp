#ifndef PROJECTILE
#define PROJECTILE
#include "entity.h"

/// @brief Klasa definująca pocisk
class projectile : public entity {
private:
public:
    projectile(sf::Texture &res);
    /// @brief Metoda sprawdzająca kolizję (wzajemną odległość hitboxów) z hitboxem innego obiektu
    /// @param e Obiekt do sprawdzenia kolizji
    /// @return True, jeżeli doszło do kolizji
    bool checkCollision(entity* e) override;
    /// @brief Metoda uaktualniająca pozycję obiektu, oraz odliczająca czas do następnego strzału
    /// @param ms Ilość milisekund od ostatniego wywołania update
    /// @return True, gdy obiekt jest gotowy do oddania strzału
    bool update(int msElapsed) override;

};

#endif