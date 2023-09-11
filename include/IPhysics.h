#ifndef IPHYSICS
#define IPHYSICS

/// @brief Interfejs zawierający metody i pola zarządzające pozycją, prędkością oraz kolizjami obiektu
class IPhysics {
protected:
    /// @brief Aktualna prędkość obiektu w dwóch płaszczyznach (x,y)
    float vel[2];

    /// @brief Promień cyrkularnego hitboxa obiektu
    float hitboxRadius;
    /// @brief Ograniczenia położenia obiektu. Maksymalna pozioma/pionowa odległość od środka ekranu
    float boundries[2];
public:
    /// @brief Wirtualny setter poziomej prędkości obiektu
    virtual void setVel_x(float vx) = 0;
    /// @brief Wirtualny setter pionowej prędkości obiektu
    virtual void setVel_y(float vy) = 0;
    /// @brief Wirtualny getter promienia hitboxa
    virtual float getHitbox() = 0;
    /// @brief Wirtualna metoda aktualniająca pozycję obiektu, oraz odliczająca czas do następnego strzału
    virtual bool update(int ms) = 0;

};

#endif