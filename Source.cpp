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
                // ���������� �����
                drawMap(map, playerPos);

                // �������� ���� ������������
                
                input = getInput();

                // ������������ ���� ������������
                int newX = playerPos.x;
                int newY = playerPos.y;

                if (input == 'w') {
                    newY--; // �����
                }
                else if (input == 's') {
                    newY++; // ����
                }
                else if (input == 'a') {
                    newX--; // �����
                }
                else if (input == 'd') {
                    newX++; // ������
                }
                else if (input == 'q') {
                    break; // ����� �� ����
                }

                // ���������, �������� �� ����� ������� ����������
                if (isCellValid(map, newX, newY)) {
                    playerPos.x = newX;
                    playerPos.y = newY;
                }
            }

        }
    }


   
   
    

}