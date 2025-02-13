#pragma once
#include <iostream>




const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 10;
const char WALL = '#';
const char EMPTY = ' ';
const char PLAYER = '*';

struct Position {
    int x;
    int y;
};


std::vector<std::vector<char>> createMap() {
    std::vector<std::vector<char>> map(MAP_HEIGHT, std::vector<char>(MAP_WIDTH, EMPTY));

    // Создаем границы карты
    for (int i = 0; i < MAP_WIDTH; ++i) {
        map[0][i] = WALL;
        map[MAP_HEIGHT - 1][i] = WALL;
    }
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        map[i][0] = WALL;
        map[i][MAP_WIDTH - 1] = WALL;
    }

    // Добавляем несколько препятствий
    map[3][5] = WALL;
    map[3][6] = WALL;
    map[3][7] = WALL;

    map[6][2] = WALL;
    map[7][2] = WALL;
    map[8][2] = WALL;

    return map;
}

// Функция для отображения карты
void drawMap(const std::vector<std::vector<char>>& map, const Position& playerPos) {
    system("cls");


    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if (i == playerPos.y && j == playerPos.x) {
                std::cout << PLAYER;
            }
            else {
                std::cout << map[i][j];
            }
        }
        std::cout << std::endl;
    }
}


bool isCellValid(const std::vector<std::vector<char>>& map, int x, int y) {
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
        return false;
    }
    return map[y][x] == EMPTY;
}






char getInput() {
    char input;
    input = _getch();
    return input;
}




