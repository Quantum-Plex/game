// Copyright (c) 2025 Quantum Plex Authors
// SPDX-License-Identifier: MIT

#include <string.h>

#include <iostream>

#include "linenoise/linenoise.h"
#include "data.h"

class Game {
public:
    GameState state = STATE_START_ROOM;
    GameState prev_state;

    bool instructions_asked;
};
Game plex; /* global */

void cmd_exit() {
    exit(0);
}

std::map<const char *, void (*)()> commandMap = {
    { "exit", &cmd_exit },
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
        while ((line = linenoise("> ")) != NULL) {
            // Process lines
            if (*line) {
                for (it = commandMap.begin(); it != commandMap.end(); ++it) {
                    if (!strcmp(it->first, line)) {
                        it->second();
                        break;
                    }
                }

                // Game states & events (FIXME)
                if (plex.prev_state != plex.state) {
                    GameTextState starter;
                    switch (plex.state) {
                        case STATE_START_ROOM:
                            starter = SURROUNDING_START_ROOM_STARTER;
                            break;
                    }
                    std::cout << GameText.at(starter) << std::endl;
                }
            }
            free(line);
        }
    }

    return 0;
}
