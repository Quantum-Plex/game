// Copyright (c) 2025 Quantum Plex Authors
// SPDX-License-Identifier: MIT

#include <iostream>

#include "data.h"
#include "game.h"

Game plex; /* global */

void game_w() {
    GameTextState buf;

    switch (plex.state) {
        case STATE_START_ROOM:
            if (plex.starter_room.puzzle_obtained)
                buf = SURROUNDING_START_ROOM_CONDWO;
            else
                buf = SURROUNDING_START_ROOM_CONDWI;
            break;
    }
    std::cout << GameText.at(buf);
}

void game_a() {
    GameTextState buf;

    switch (plex.state) {
        case STATE_START_ROOM:
            buf = SURROUNDING_START_ROOM_CONDA;
            plex.starter_room.portrait_gazed = true;
            break;
    }
    std::cout << GameText.at(buf);
}

void game_s() {
    GameTextState buf;

    switch (plex.state) {
        case STATE_START_ROOM:
            buf = SURROUNDING_START_ROOM_CONDS;
            break;
    }
    std::cout << GameText.at(buf);
}

void game_d() {
    GameTextState buf;

    switch (plex.state) {
        case STATE_START_ROOM:
            buf = SURROUNDING_START_ROOM_CONDD;
            plex.starter_room.puzzle_obtained = true;
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
        }
        std::cout << "[*] " << GameText.at(buf);

        plex.prev_state = plex.state;
    }
}
