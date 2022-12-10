#ifndef __GAME_H__
#define __GAME_H__

class Game {
public:
    Game();
    virtual ~Game();

    // member functions
    void run();
    void update();
    void render();
    void updateSFMLEvents();
private:

};

#endif // __GAME_H__