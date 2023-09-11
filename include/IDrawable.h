#ifndef DRAWABLE
#define DRAWABLE
#include <SFML/Graphics.hpp>

/// @brief Interfejs zawierający metody i pola zarządzające wyświetlaniem obiektów
class IDrawable {
protected:
    /// @brief Włączenie (false/0) oraz wyłączenie (true/1) wyświetlania obiektu
    bool disabled;
public:
    /// @brief Grafika obiektu (część biblioteki SFML). Zawiera teksturę, położenie i skalę
    sf::Sprite sprite;
    
};

#endif