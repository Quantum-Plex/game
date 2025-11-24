// Copyright (c) 2025 Quantum Plex Authors
// SPDX-License-Identifier: MIT

#include <cstdlib>
#include <iostream>

#include "data.h"
#include "game.h"

Game plex; /* global */

void game_single_input_handler(char *key) {
    GameTextState buf;

    switch (plex.state) {
        case STATE_START_ROOM:
            switch (*key) {
                case 'w':
                    if (plex.starter_room.puzzle_obtained)
                        buf = SURROUNDING_START_ROOM_CONDWO;
                    else
                        buf = SURROUNDING_START_ROOM_CONDWI;
                    break;
                case 'a':
                    if (rand() % 101 >= 90) // 10% chance
                        buf = SURROUNDING_START_ROOM_CONDA2;
                    else
                        buf = SURROUNDING_START_ROOM_CONDA1;
                    plex.starter_room.portrait_gazed = true;
                    break;
                case 's':
                    buf = SURROUNDING_START_ROOM_CONDS;
                    break;
                case 'd':
                    buf = SURROUNDING_START_ROOM_CONDD;
                    plex.starter_room.puzzle_obtained = true;
                    break;
            }
            break;
        case STATE_START_ROOM_PUZZLE:
            break;
    }

    std::cout << GameText.at(buf);
}

void game_state_loop() {
    GameTextState buf;

    // Show starter text for new states
    if (plex.prev_state != plex.state) {
        switch (plex.state) {
            case STATE_START_ROOM:
                buf = SURROUNDING_START_ROOM_STARTER;
                break;
            case STATE_START_ROOM_PUZZLE:
                // TODO: Chance calculations
                break;
        }
        std::cout << "[*] " << GameText.at(buf);

        plex.prev_state = plex.state;
    }
}
