#include <iostream>

char stars[3072][6144];

void draw_stars(int height, int pos_x, int pos_y) { // pos_x: col, pos_y: row
    if (height == 3) {
        for (int i = pos_x; i < pos_x + 5; i++) stars[pos_y][i] = '*';
        pos_x++;
        pos_y--;
        stars[pos_y][pos_x] = '*';
        pos_x += 2;
        stars[pos_y][pos_x] = '*';
        pos_x--;
        pos_y--;
        stars[pos_y][pos_x] = '*';
    }
    else {
        draw_stars(height / 2, pos_x, pos_y);
        draw_stars(height / 2, pos_x + height, pos_y);
        draw_stars(height / 2, pos_x + height / 2, pos_y - height / 2);
    }
}

int main() {
    int height, base;
    std::cin >> height;
    base = 2 * height;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < base; j++) {
            stars[i][j] = ' ';
        }
    }

    draw_stars(height, 0, height - 1);

    // print stars
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < base; j++) {
            std::cout << stars[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}