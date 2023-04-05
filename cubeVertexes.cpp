#include <iostream>
#include <cmath>
#include <cstring>
#include <unistd.h>

int main() {
    float A = 0, B = 0;
    float i, j, k;
    float z[1760];
    char b[1760];
    std::cout << "\x1b[2J";
    for (;;) {
        std::memset(b, 32, 1760);
        std::memset(z, 0, 7040);
        for (i = -1; i <= 1; i += 2) {
            for (j = -1; j <= 1; j += 2) {
                for (k = -1; k <= 1; k += 2) {
                    float x = i;
                    float y = j;
                    float z1 = k;
                    // Rotate around x-axis
                    float x2 = x;
                    float y2 = y * cos(A) - z1 * sin(A);
                    float z2 = y * sin(A) + z1 * cos(A);
                    // Rotate around y-axis
                    float x3 = x2 * cos(B) + z2 * sin(B);
                    float y3 = y2;
                    float z3 = -x2 * sin(B) + z2 * cos(B);
                    // Apply perspective projection
                    float c = 1 / (1.5 - z3);
                    int xp = 40 + 30 * x3 * c;
                    int yp = 12 + 15 * y3 * c;
                    if (xp >= 0 && xp < 80 && yp >= 0 && yp < 22 && c > z[xp + 80 * yp]) {
                        z[xp + 80 * yp] = c;
                        b[xp + 80 * yp] = ".,-~:;=!*#$@"[(int)(0.5 * (i + j + k + 1.5))];
                    }
                }
            }
        }
        std::cout << "\x1b[H";
        for (int p = 0; p < 1761; p++) {
            std::cout.put(p % 80 ? b[p] : 10);
        }
        usleep(30000);
        A += 0.05;
        B += 0.03;
    }
    return 0;
}
