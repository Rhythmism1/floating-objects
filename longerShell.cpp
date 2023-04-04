#include <iostream>
#include <cmath>
#include <cstring>
#include <unistd.h>

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    std::cout << "\x1b[2J";
    for (;;) {
        std::memset(b, 32, 1760);
        std::memset(z, 0, 7040);

        for (j = -2; j <= 2; j += 0.05) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sin(i);
                float d = cos(i);
                float e = sin(A);
                float f = cos(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + j * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - j * e;
                int x = 40 + 20 * D * (l * h * m - t * n); // changed scaling factor for x
                int y = 12 + 10 * D * (l * h * n + t * m); // changed scaling factor for y
                int o = x + 80 * y;
                int N = 8 * ((j * e - c * d * g) * m - c * d * e - j * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        // Print the updated frame
        std::cout << "\x1b[H";
        for (k = 0; k < 1761; k++) {
            std::cout.put(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }
        usleep(30000);
    }
    return 0;
}
