#include <iostream>
#include <cmath>
#include <cstring>
#include <unistd.h>

int main() {
    float A = 0, B = 0, C = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    std::cout << "\x1b[2J";
    for (;;) {
        std::memset(b, 32, 1760);
        std::memset(z, 0, sizeof(z));

        for (j = 0; j < 12.56637; j += 0.3) {
            for (i = 0; i < 12.56637; i += 0.1) {
                float a = sin(j);
                float d = cos(j);
                float e = sin(i);
                float f = cos(i);
                float g = sin(A);
                float h = sin(B);
                float l = sin(C);
                float m = cos(A);
                float n = cos(B);
                float o = cos(C);
                float w = a * e + h * f * g;
                float x = a * f * o - h * e * l;
                float y = d * e * m + f * (l * m * o - n * g);
                float z_val = d * f * n + e * (g * n * o + l * m); // Renamed variable to avoid confusion
                float D = 1 / (z_val + 5);
                int u = 40 + 40 * D * (w * n - x * m);
                int v = 12 + 20 * D * (w * m + x * n);
                int p = u + 80 * v;
                int q = 8 * ((f * g * o - a * l * g * n) * m - (a * n * g + h * l * g - a * m) * l - (d * m * o + l * n * o) * h);
                if (22 > v && v > 0 && u > 0 && 80 > u && D > z[p]) {
                    z[p] = D;
                    b[p] = ".,-~:;=!*#$@"[q > 0 ? q : 0];
                }
            }
        }

        // Print the updated frame
        std::cout << "\x1b[H";
        for (k = 0; k < 1761; k++) {
            std::cout.put(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00008;
            C += 0.00012;
        }
        usleep(30000);
    }
    return 0;
}
