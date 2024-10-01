#ifndef __CHESS_H__
#define __CHESS_H__

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "GameContext.hpp"
#include "GameEngine.hpp"
#include "Tile.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include "Button.hpp"

// CHILD CLASS RESPONSIBLE FOR THE CHESS STATE. INHERITS FROM THE STATE CLASS.
class Chess : public Engine::State
{
private:
    bool mouseClicked_;
    bool pieceSelected_;
    std::shared_ptr<GameContext> context_;
    std::vector<std::vector<Tile>> board_;
    std::vector<std::unique_ptr<Piece>> pieces_;
    
    Button mainMenuButton_ = Button(1000, 475, 200, 100, "assets/sprites/button.png", "Main Menu");
    Button resetBoardButton_ = Button(1000, 325, 200, 100, "assets/sprites/button.png", "Reset Board");

    bool quit_ = false;

public:
    Chess(std::shared_ptr<GameContext> &context);
    ~Chess();

    void resetBoard();
    void checkPieces(sf::Vector2i mousePos);
    void checkButtons(sf::Vector2i mousePos);

    // Pure virtual methods:
    virtual void init() override;
    virtual void processInput() override;
    virtual void update() override;
    virtual void draw() override;

    virtual void pause() override;
    virtual void start() override;
};

#endif // __CHESS_H__   