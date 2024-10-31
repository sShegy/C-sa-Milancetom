#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

int gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

void setup() {
    gameOver = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;
}

void draw() {
    system("cls"); // Brisanje ekrana
    for (int i = 0; i < WIDTH + 2; i++) 
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
                printf("O"); // Glava zmije
            else if (i == fruitY && j == fruitX)
                printf("F"); // Voće
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o"); // Rep zmije
                        print = 1;
                    }
                }
                if (!print)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) 
        printf("#");
    printf("\n");
    printf("Score: %d\n", score);
}

void logic() {
    // Pomera rep zmije
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Funkcija koja proverava da li je sledeća pozicija na repu
    int isTailPosition(int newX, int newY) {
        for (int i = 0; i < nTail; i++) {
            if (tailX[i] == newX && tailY[i] == newY) {
                return 1; // Nađena je pozicija repa
            }
        }
        return 0; // Pozicija nije deo repa
    }

    // Heuristika za kretanje ka voću, uz izbegavanje repa
    if (x < fruitX && !isTailPosition(x + 1, y)) {
        x++; // Kretanje desno
    } else if (x > fruitX && !isTailPosition(x - 1, y)) {
        x--; // Kretanje levo
    } else if (y < fruitY && !isTailPosition(x, y + 1)) {
        y++; // Kretanje dole
    } else if (y > fruitY && !isTailPosition(x, y - 1)) {
        y--; // Kretanje gore
    } else {
        // Ako je voće blokirano od strane repa, zmija se nasumično pomera
        if (!isTailPosition(x + 1, y)) {
            x++; // Kretanje desno
        } else if (!isTailPosition(x - 1, y)) {
            x--; // Kretanje levo
        } else if (!isTailPosition(x, y + 1)) {
            y++; // Kretanje dole
        } else if (!isTailPosition(x, y - 1)) {
            y--; // Kretanje gore
        }
    }

    // Kada zmija pojede voće
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }

    // Ako zmija udari zidove (teleportacija na suprotnu stranu)
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    // Provera udarca u rep
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = 1;
        }
    }
}


int main() {
    setup();
    while (!gameOver) {
        draw();
        logic();
        Sleep(100); // Pauza između poteza zmije
    }
    return 0;
}
