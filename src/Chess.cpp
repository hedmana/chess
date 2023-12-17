#include "Chess.hpp"

Chess::Chess(std::shared_ptr<GameContext> &context)
    : context_(context)
{
    mouseClicked_ = false;
    pieceSelected_ = false;
}

Chess::~Chess()
{
}

void Chess::init()
{
    // Set up the board
    for (int i = 0; i < 8; i++)
    {
        std::vector<Tile> row;

        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
                row.push_back(Tile(i * 100, j * 100, 100, 100, WHITE));
            else
                row.push_back(Tile(i * 100, j * 100, 100, 100, BLACK));
        }

        board_.push_back(row);
    }

    // Set up the pieces
    for (int i = 0; i < 8; i++)
    {
        if (i == 0 || i == 7)
        {
            pieces_.push_back(std::make_unique<Rook>(50 + i * 100, 50, 100, 100, BLACK));
            pieces_.push_back(std::make_unique<Rook>(50 + i * 100, 750, 100, 100, WHITE));
        }
        else if (i == 1 || i == 6)
        {
            pieces_.push_back(std::make_unique<Knight>(50 + i * 100, 50, 100, 100, BLACK));
            pieces_.push_back(std::make_unique<Knight>(50 + i * 100, 750, 100, 100, WHITE));
        }
        else if (i == 2 || i == 5)
        {
            pieces_.push_back(std::make_unique<Bishop>(50 + i * 100, 50, 100, 100, BLACK));
            pieces_.push_back(std::make_unique<Bishop>(50 + i * 100, 750, 100, 100, WHITE));
        }
        else if (i == 3)
        {
            pieces_.push_back(std::make_unique<Queen>(50 + i * 100, 50, 100, 100, BLACK));
            pieces_.push_back(std::make_unique<Queen>(50 + i * 100, 750, 100, 100, WHITE));
        }
        else if (i == 4)
        {
            pieces_.push_back(std::make_unique<King>(50 + i * 100, 50, 100, 100, BLACK));
            pieces_.push_back(std::make_unique<King>(50 + i * 100, 750, 100, 100, WHITE));
        }
        pieces_.push_back(std::make_unique<Pawn>(50 + i * 100, 150, 100, 100, BLACK));
        pieces_.push_back(std::make_unique<Pawn>(50 + i * 100, 650, 100, 100, WHITE));
    }

    // Set occupied tiles
    for (auto &piece : pieces_)
    {
        for (auto &row : board_)
        {
            for (auto &tile : row)
            {
                if (tile.getSprite().getGlobalBounds().contains(piece->getSprite().getPosition()))
                {
                    tile.setOccupied(true);
                }
            }
        }
    }
}

void Chess::checkPieces(sf::Vector2i mousePos)
{
    std::pair<int, int> tilePos;

    if(!pieceSelected_)
    {
        for (auto &piece : pieces_)
        {
            if (piece->getSprite().getGlobalBounds().contains(context_->window_->mapPixelToCoords(mousePos)))
            {
                piece->setSelected(true);
            }
        }
        pieceSelected_ = true;
    } else {
        for (auto &piece : pieces_)
        {
            if (piece->isSelected())
            {
                for (auto &tile : board_)
                {
                    for (auto &tile : tile)
                    {
                        if (tile.getSprite().getGlobalBounds().contains(context_->window_->mapPixelToCoords(mousePos)))
                        {
                            if (!tile.isOccupied())
                            {
                                piece->setSelected(false);
                                tilePos = tile.getPosition();
                                piece->setCoordinates(tilePos.first + 50, tilePos.second + 50);
                                pieceSelected_ = false;
                                tile.setOccupied(true);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Chess::processInput()
{
    sf::Event event;
    sf::Vector2i mousePos = sf::Mouse::getPosition(*(context_->window_));

    while (context_->window_->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            context_->window_->close();
            break;
        }
        case sf::Event::KeyPressed:
        {
            switch (event.key.code)
            {
            case ::sf::Keyboard::Enter:
            {
                quit_ = true;
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case ::sf::Event::MouseButtonPressed:
        {
            std::cout << mousePos.x << ", " << mousePos.y << std::endl;
            checkPieces(mousePos);
            
            break;
        }
        default:
        {
            break;
        }
        }
    }
}

void Chess::update()
{
    if (quit_)
    {
        context_->states_->popCurrent();
        quit_ = false;
    }
}

void Chess::draw()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*(context_->window_));
    context_->window_->clear(sf::Color(75, 0, 90));

    for (auto &row : board_)
    {
        for (auto &tile : row)
        {
            context_->window_->draw(tile.getSprite());
        }
    }

    for (auto &piece : pieces_)
    {
        if (!piece->isSelected())
            context_->window_->draw(piece->getSprite());
    }

    for (auto &piece : pieces_)
    {
        if (piece->isSelected())
        {
            piece->setCoordinates(mousePos.x, mousePos.y);
            context_->window_->draw(piece->getSprite());
        }
    }

    context_->window_->display();
}

void Chess::pause()
{
}

void Chess::start()
{
}
