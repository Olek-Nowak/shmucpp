#ifndef ENTITY
#define ENTITY
#include "IPhysics.h"
#include "IDrawable.h"

/// @brief Abstrakcyjna klasa bazowa dla wszystkich aktorów w grze
class entity : IPhysics, IDrawable {
protected:
    /// @brief Aktualna prędkość obiektu w dwóch płaszczyznach (x,y)
    float vel[2];

    /// @brief Promień cyrkularnego hitboxa obiektu
    float hitboxRadius;
    /// @brief Ograniczenia położenia obiektu. Maksymalna pozioma/pionowa odległość od środka ekranu
    float boundries[2];

    /// @brief Włączenie (false/0) oraz wyłączenie (true/1) wyświetlania obiektu
    bool disabled;
public:
    /// @brief Zewnętrzna grafika obiektu z biblioteki SFML. Zawiera teksturę, położenie i skalę
    sf::Sprite sprite;
    entity();
    virtual ~entity();
    /// @brief Setter poziomej prędkości obiektu
    /// @param vx Nowa pozioma prędkość
    void setVel_x(float vx);
    /// @brief Setter pionowej prędkości obiektu
    /// @param vy Nowa pionowa prędkość
    void setVel_y(float vy);
    /// @brief Wirtualna metoda sprawdzająca kolizję z hitboxem innego obiektu
    virtual bool checkCollision(entity* e)=0;
    /// @brief Getter promienia hitboxa
    /// @return Promień hitboxa obiektu
    float getHitbox();
    /// @brief Wirtualna metoda uaktualniająca pozycję obiektu, oraz odliczająca czas do następnego strzału
    /// @param ms Ilość milisekund od ostatniego wywołania update
    /// @return True, gdy obiekt jest gotowy do oddania strzału
    virtual bool update(int msElapsed)=0;
    /// @brief Getter włączenia wyświetlania obiektu
    /// @return Włączenie (false/0) oraz wyłączenie (true/1) wyświetlania obiektu
    bool getDisabled();
    /// @brief Setter włączenia wyświetlania obiektu
    /// @param d Włączenie (false/0) oraz wyłączenie (true/1) wyświetlania obiektu
    void setDisabled(bool d);

};

#endif