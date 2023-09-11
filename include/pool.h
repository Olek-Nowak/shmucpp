#ifndef POOL
#define POOL
#include <string>
#include "projectile.h"
#include <vector>

/// @brief Klasa pozwalająca na aktywowanie, deaktywowanie i ponowne używanie pocisków
class pool {
protected:
    /// @brief Wektor wskaźników do przechowywanych pocisków
    std::vector<projectile*> bullets;
    /// @brief Liczba przechowywanych pocisków
    int num;
public:
    /// @brief Funkcja odnajdująca i zwracająca nieużywane pociski
    /// @return Wskaźnik do pocisku
    projectile* getNew();
    pool(int buffer, sf::Texture &res);
    ~pool();

};

#endif