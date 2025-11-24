// Copyright (c) 2025 Quantum Plex Authors
// SPDX-License-Identifier: MIT

#ifndef PLEX_H
#define PLEX_H

#include <string>
#include <map>

enum GameTextState {
    SPLASH,
    WELCOME_PROMPT,
    WELCOME_INSTRUCTIONS,

    /* Start room */
    SURROUNDING_START_ROOM_STARTER,
    SURROUNDING_START_ROOM_CONDWI,
    SURROUNDING_START_ROOM_CONDWO,
    SURROUNDING_START_ROOM_CONDA,
    SURROUNDING_START_ROOM_CONDS,
    SURROUNDING_START_ROOM_CONDD,

    /* Start room puzzle */
    SURROUNDING_START_ROOM_PUZZLE_STARTER,
    SURROUNDING_START_ROOM_PUZZLE1,
    SURROUNDING_START_ROOM_PUZZLE2,
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
                           "Treat me like your eyes and hands, and direct me with commands, such as \"take\"\n"
                           "or look. Move around by entering directions in w/a/s/d.\n"},
    {SURROUNDING_START_ROOM_STARTER, "You awoke in the aftermath of the explosion.\n"},
    {SURROUNDING_START_ROOM_CONDWI, "There is a door in front of you, but it appears you are missing something.\n"},
    {SURROUNDING_START_ROOM_CONDWO, "The door is locked, you have to attempt a challenge to unlock.\n"},
    {SURROUNDING_START_ROOM_CONDA, "A portrait of the president of Quantum Plex hung beside the logo.\n"},
    {SURROUNDING_START_ROOM_CONDS, "You shouldn't come here, monstors are escaping the white hole. Fortunately,\n"
                                   "you are still shielded by a tempered glass door.\n"},
    {SURROUNDING_START_ROOM_CONDD, "You obtained the puzzle map, use it to unlock the door.\n"},
    {SURROUNDING_START_ROOM_PUZZLE_STARTER, "\n"},
    {SURROUNDING_START_ROOM_PUZZLE1, "\n"},
    {SURROUNDING_START_ROOM_PUZZLE2, "\n"},
};

#endif // PLEX_H
