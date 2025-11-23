// Copyright (c) 2025 Quantum Plex Authors
// SPDX-License-Identifier: MIT

#ifndef PLEX_H
#define PLEX_H

#include <string>
#include <map>

enum GameState {
    STATE_START_ROOM = 1,
};

enum GameTextState {
    SPLASH,
    WELCOME_PROMPT,
    WELCOME_INSTRUCTIONS,

    /* Start room */
    SURROUNDING_START_ROOM_STARTER,
    SURROUNDING_START_ROOM_COND1,
    SURROUNDING_START_ROOM_COND2,
    SURROUNDING_START_ROOM_COND3,
    SURROUNDING_START_ROOM_COND4,
};

const std::map<GameTextState, std::string> GameText = {
    {SPLASH, "Quantum Plex - A text-based adventure game\n"
             "Copyright (c) 2025 Quantum Plex Authors\n"},
    {WELCOME_PROMPT, "Welcome to the Plex! Would you like instructions? (y/n) "},
    {WELCOME_INSTRUCTIONS, "Your gaze focused on the glistering light emanating from the qubits, just a while\n"
                           "back you were a little known physicists starting your internship at the company\n"
                           "Quantum Plex, an ambitious start up aiming to commercialize quantum mechanics for\n"
                           "the masses; Yet, you now stood at the forefront of supposedly the most advanced,\n"
                           "government assigned projects your company had chosen to take on, but all that was\n"
                           "only hearsay.\n\n"
                           "KABOOM! A deafening explosion sound encompassed your room, and blinding lights\n"
                           "scattered in the room. Your creation had opened up a galactic white hole, spiling\n"
                           "out animate objects of alien origin. You were sure your time would be limited if\n"
                           "you do not escape from the plex.\n\n"
                           "Treat me like your eyes and hands, and direct me with commands, such as get/take\n"
                           "or look. Move around by entering directions in WASD.\n"},
    {SURROUNDING_START_ROOM_STARTER, "You awoke in the aftermath of the explosion.\n"},
    {SURROUNDING_START_ROOM_COND1, "\n"},
};

#endif // PLEX_H
