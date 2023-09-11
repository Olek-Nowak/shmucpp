#ifndef GAME
#define GAME
#include "singleton.h"
#include "windowManager.h"
#include "ship.h"
#include "projectile.h"
#include "pool.h"
#include <list>

/// @brief Singleton zarządzający tworzeniem, uaktualnianiem oraz niszczeniem wszystkich aktorów
class gameManager : singleton {
private:
    gameManager();
    /// @brief Singleton zarządzający wyświetlaniem gui oraz sprawdzaniem stanu wejść
    windowManager wm = windowManager::getInstance();
    /// @brief Wskaźnik do obiektu pozwalającego na aktywowanie, deaktywowanie i ponowne używanie pocisków
    pool* p = nullptr;
    /// @brief Tekstura statku (część biblioteki SFML)
    sf::Texture shipTex;
    /// @brief Tekstura pocisku (część biblioteki SFML)
    sf::Texture projectileTex;
    /// @brief Lista zawierająca wskaźniki do wszystkich aktywnych aktorów drużyny gracza
    std::list<entity*> team_0;
    /// @brief Lista zawierająca wskaźniki do wszystkich aktywnych aktorów drużyny przeciwnika
    std::list<entity*> team_1;
    /// @brief Współrzędne poziome punktów tworzenia nowych statków
    float spawnPoints[6];
    /// @brief Flaga oznaczająca włączenie (true/1) oraz wyłączenie (false/0) gry
    bool gameOn_flag;
    /// @brief Aktualny czas w milisekundach od pojawienia się poprzedniej fali statków przeciwnika
    float nextWave;
    /// @brief Czas w milisekundach między falami statków przeciwnika
    float nextWaveCD;
public:
    ~gameManager();
    /// @brief Getter flagi włączenia gry
    /// @return Flaga oznaczająca włączenie (true/1) oraz wyłączenie (false/0) gry
    /// @see gameOn_flag
    bool gameOn();
    /// @brief Metoda zwracająca jedyną instancję singletonu
    static gameManager& getInstance();
    /// @brief Sets player speed to the left
    void left_down();
    /// @brief Sets player speed to the right
    void right_down();
    /// @brief Resets all player inputs and speed
    void reset_input();
    /// @brief Metoda zatrzymująca grę (WIP)
    void pause();
    /// @brief Metoda uaktualniająca pozycję obiektu, oraz odliczająca czas do następnego strzału
    /// @param msElapsed Ilość milisekund od ostatniego wywołania update
    /// @return True, gdy obiekt jest gotowy do oddania strzału
    void update(int msElapsed);
    
};



#endif