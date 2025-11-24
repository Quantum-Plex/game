// Copyright (c) 2025 Quantum Plex Authors
// SPDX-License-Identifier: MIT

#include <string.h>

#include <iostream>

#include "linenoise/linenoise.h"
#include "data.h"
#include "game.h"

void cmd_exit() {
    exit(0);
}

std::map<const char *, void (*)()> commandMap = {
    { "exit", &cmd_exit },
    { "w", &game_w },
    { "a", &game_a },
    { "s", &game_s },
    { "d", &game_d },
};

int main(int argc, char* argv[])
{
    char singleUserAnswer;
    char *line;
    std::map<const char *, void (*)()>::iterator it;

    // Pre-loop texts
    std::cout << GameText.at(SPLASH) << std::endl;
    do
    {
        std::cout << GameText.at(WELCOME_PROMPT);
        std::cin >> singleUserAnswer;
    }
    while( !std::cin.fail() && singleUserAnswer != 'y' && singleUserAnswer != 'n' );
    plex.instructions_asked = true;
    if (singleUserAnswer == 'y')
        std::cout << std::endl << GameText.at(WELCOME_INSTRUCTIONS) << std::endl;

    // Game loop
    while (true) {
        game_state_loop();

        while ((line = linenoise("> ")) != NULL) {
            // Process lines
            if (*line) {
                for (it = commandMap.begin(); it != commandMap.end(); ++it)
                    if (!strcmp(it->first, line))
                        it->second();
            }
            free(line);
            break;
        }
    }

    return 0;
}
