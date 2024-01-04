#pragma once
#include <SFML/Graphics.hpp>
#include "ui/UIManager.hpp"
#include "object/ObjectManager.hpp"

#define logl(x) std::cout << x << std::endl
#define log(x) std::cout << x

class GameManager
{
private:
    UIManager ui_manager;
    ObjectManager obj_manager;
public:
    GameManager();
    void UIControll();
    void ConnectObject();
};