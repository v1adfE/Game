#include <iostream>
#include <string>
#include <conio.h>
#include<vector>
#include "Graphic.h"
#include "WALKING.h"





int main() { 

    std::vector<std::vector<char>> map = createMap();
    Position playerPos = { 1, 1 };

    std::string a = "";
    PressEnter();
    std::getline(std::cin, a); 


    if (a.empty()) { 
        system("cls");
        std::cout << "GAME START\n";
        bool WalkMode = true;
        while (WalkMode) {
            char input;
            input = _getch();

            while (true) {
                // Отображаем карту
                drawMap(map, playerPos);

                // Получаем ввод пользователя
                
                input = getInput();

                // Обрабатываем ввод пользователя
                int newX = playerPos.x;
                int newY = playerPos.y;

                if (input == 'w') {
                    newY--; // Вверх
                }
                else if (input == 's') {
                    newY++; // Вниз
                }
                else if (input == 'a') {
                    newX--; // Влево
                }
                else if (input == 'd') {
                    newX++; // Вправо
                }
                else if (input == 'q') {
                    break; // Выход из игры
                }

                // Проверяем, является ли новая позиция допустимой
                if (isCellValid(map, newX, newY)) {
                    playerPos.x = newX;
                    playerPos.y = newY;
                }
            }

        }
    }


   
   
    

}