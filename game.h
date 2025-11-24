// Copyright (c) 2025 Quantum Plex Authors
// SPDX-License-Identifier: MIT

#ifndef GAME_H
#define GAME_H

enum GameState {
    STATE_START_ROOM = 1,
};

class Game {
public:
    GameState state = STATE_START_ROOM;
    GameState prev_state;

    bool instructions_asked;

    /* Starter room */
    struct starter_room {
        bool puzzle_obtained;
        bool portrait_gazed;
    };
    struct starter_room starter_room;
};
extern Game plex; /* global */

void game_state_loop();
void game_w();
void game_a();
void game_s();
void game_d();

#endif // GAME_H
