#ifndef SHIP
#define SHIP
#include "entity.h"
#include "IDamageable.h"

/// @brief Klasa definiująca statek
class ship : public entity, IDamageable {
private:
    /// @brief 
    int maxHealth;
    /// @brief 
    int health;
    /// @brief 
    int maxCD;
    /// @brief 
    int cooldown;
public:
    ship(int hp, float startx, float starty, float hitbox, sf::Texture &res, int weaponCD);
    ~ship();
    /// @brief Metoda sprawdzająca kolizję (wzajemną odległość hitboxów) z hitboxem innego obiektu
    /// @param e Obiekt do sprawdzenia kolizji
    /// @return True, jeżeli doszło do kolizji
    bool checkCollision(entity* e) override;
    /// @brief Metoda zmniejszająca zdrowie obiektu o daną wartość
    /// @param damage Ilość straconego zdrowia
    void onHit(int damage);
    /// @brief Metoda zarządzająca niszczeniem obiektu (WIP)
    void destroy();
    /// @brief Metoda uaktualniająca pozycję obiektu, oraz odliczająca czas do następnego strzału
    /// @param ms Ilość milisekund od ostatniego wywołania update
    /// @return True, gdy obiekt jest gotowy do oddania strzału
    bool update(int msElapsed) override;

};

#endif