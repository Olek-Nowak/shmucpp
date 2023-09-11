#ifndef WINDOW
#define WINDOW
#include <SFML/Graphics.hpp>
#include "singleton.h"

/// @brief Singleton zarządzający wyświetlaniem gui oraz sprawdzaniem stanu wejść
/// @remark Sadly, input detection in SFML is tied to window listeners, so inputManager is merged into windowManager.
class windowManager : singleton {
private:
    /// @brief Główne okno gry (część biblioteki SFML)
    sf::RenderWindow* mainWindow;
    /// @brief Czcionka HUD (część biblioteki SFML)
    sf::Font font;
    windowManager();
    /// @brief Zdrowie gracza
    int trackerHP;
public:
    ~windowManager();
    /// @brief Metoda zwracająca jedyną instancję singletonu
    static windowManager& getInstance();
    /// @brief Metoda pobierająca wydarzenia inputu użytkownika z kolejki (część biblioteki SFML)
    /// @return Najnowsze wydarzenie
    sf::Event pollEvents();
    /// @brief Czyści okno
    void clear();
    /// @brief Dodaje sprite do głównego okna (część biblioteki SFML)
    /// @param s Sprite do wyświetlenia
    void add(sf::Sprite s);
    /// @brief Wyświetla wszystkie elementy przypisane do głównego okna
    void show();
    /// @brief Wyświetla ekran / tekst porażki
    void loseScreen();
    /// @brief Zamyka główne okno
    void exit();
    /// @brief Uaktualnia HUD / wyświetlacz zdrowia gracza
    /// @param delta Zmiana zdrowia gracza
    void updateUI(int delta);
    
};

#endif