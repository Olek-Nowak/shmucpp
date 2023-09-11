#ifndef DAMAGE
#define DAMAGE

/// @brief Interfejs zawierający metody i pola zarządzające zdrowiem obiektów
class IDamageable {
protected:
    /// @brief Maksymalne / początkowe zdrowie obiektu
    int maxHealth;
    /// @brief Aktualne zdrowie obiektu
    int health;
public:
    /// @brief Wirtualna metoda zmniejszająca zdrowie obiektu o daną wartość
    virtual void onHit(int damage) = 0;
    /// @brief Wirtualna metoda zarządzająca niszczeniem obiektu (WIP)
    virtual void destroy() = 0;

};

#endif