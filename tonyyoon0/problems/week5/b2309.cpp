#include <iostream>
#include <algorithm>

int main() {
    int heights[9];
    for (int i = 0; i < 9; i++) {
        std::cin >> heights[i];
    }
    int a, b, c, d, e, f, g;

    for (a = 0; a < 9; a++) {
        for (b = 1; b < 9; b++) {
            for (c = 2; c < 9; c++) {
                for (d = 3; d < 9; d++) {
                    for (e = 4; e < 9; e++) {
                        for (f = 5; f < 9; f++) {
                            for (g = 6; g < 9; g++) {
                                if (heights[a] + heights[b] + heights[c] + heights[d] + heights[e] + heights[f] + heights[g] == 100) {
                                    goto end;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
end:
    int dwarf_heights[7] = {heights[a], heights[b], heights[c], heights[d], heights[e], heights[f], heights[g]};
    std::sort(dwarf_heights, dwarf_heights + 7);
    for (int i = 0; i < 7; i++) {
        std::cout << dwarf_heights[i] << std::endl;
    }
    return 0;
}