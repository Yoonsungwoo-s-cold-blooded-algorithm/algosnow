#include <iostream>
#include <algorithm>

int main() {
    // initial inputs
    int num_characters;
    std::cin >> num_characters;

    int level_count;
    std::cin >> level_count;

    int *characters_level = new int[num_characters];
    for (int i = 0; i < num_characters; i++) {
        std::cin >> characters_level[i];
    }
    // calculation
    std::sort(characters_level, characters_level + num_characters);

    int *level_gaps = new int[num_characters - 1];
    for (int i = 0; i < num_characters - 1; i++) {
        level_gaps[i] = characters_level[i + 1] - characters_level[i];
    }
    int indicator = 0;
    while (level_count >= level_gaps[indicator] * (indicator + 1) && indicator < num_characters) {
        level_count -= level_gaps[indicator] * (indicator + 1);
        indicator++;
    }
    int ans = characters_level[0];
    for (int i = 0; i < indicator; i++) {
        ans += level_gaps[i];
    }
    if (indicator == num_characters) {
        ans += level_count / indicator;
    }
    else {
        ans += level_count / (indicator + 1);
    }
    std::cout << ans;
    return 0;
}