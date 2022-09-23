// Assignment 2 20T1 COMP1511: CS bEats
// test_beats.c
//
// This program was written by Tianwei MO (z5305298)
// on 29th July 2020
//
// Version 1.0.0: Assignment released.
#include <stdio.h>
#include <stdlib.h>

#include "test_beats.h"
#include "beats.h"


// Test function for `add_note_to_beat`
int test_add_note_to_beat(void) {
    // Test 1: Rejecting negative inputs.
    Beat test_beat = create_beat();
    if (add_note_to_beat(test_beat, -1, -1) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, -1, 0) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 1, -1) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Rejecting wrong inputs.

    // TODO: Write Test 2
    if (add_note_to_beat(test_beat, 11, 1) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 1, 15) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: Rejecting non-increasing notes.

    // TODO: Write Test 3
    add_note_to_beat(test_beat, 2, 5);
    if (add_note_to_beat(test_beat, 1, 6) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 2, 5) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    return MEETS_SPEC;
}

// Test function for `count_notes_in_octave`
int test_count_notes_in_octave(void){
    // Test 1: Counting empty beats.
    Beat test_beat = create_beat();
    if (count_notes_in_octave(test_beat, 1) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    // Test 2: Counting empty octaves.
    add_note_to_beat(test_beat, 1, 1);
    if (count_notes_in_octave(test_beat, -1) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 11) != 0) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: Counting non-exist octaves.
    // TODO: Write Test 3
    if (count_notes_in_octave(test_beat, 2) != 0) {
        return DOES_NOT_MEET_SPEC;
    }

    return MEETS_SPEC;
}

// Test function for `add_beat_to_track`
int test_add_beat_to_track(void){
    // Test 1: First adding.
    // TODO: Write Test 1
    Track test_track = create_track();
    Beat test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    if (select_next_beat(test_track) != TRACK_PLAYING) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_beats_left_in_track(test_track) != 0) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Adding NULL.
    // TODO: Write Test 2
    Beat test_second_beat = create_beat();
    add_beat_to_track(test_track, test_second_beat);
    if (count_beats_left_in_track(test_track) != 1) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: Changing selectedBeat.
    // TODO: Write Test 3
    Beat test_third_beat = create_beat();
    add_beat_to_track(test_track, test_third_beat);
    if (select_next_beat(test_track) != TRACK_PLAYING) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_beats_left_in_track(test_track) != 1) {
        return DOES_NOT_MEET_SPEC;
    }

    return MEETS_SPEC;
}

// Test function for `remove_selected_beat`
int test_remove_selected_beat(void){
    // Test 1: Removing a beat.
    // TODO: Write Test 1
    Track test_track = create_track();
    Beat test_beat = create_beat();
    add_beat_to_track(test_track, test_beat);
    int i = select_next_beat(test_track);
    if (remove_selected_beat(test_track) != TRACK_STOPPED) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Removing last beat.
    // TODO: Write Test 2
    Beat test_second_beat = create_beat();
    Beat test_third_beat = create_beat();
    add_beat_to_track(test_track, test_third_beat);
    add_beat_to_track(test_track, test_second_beat);
    i = select_next_beat(test_track);
    i = select_next_beat(test_track);
    if (remove_selected_beat(test_track) != TRACK_STOPPED) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: Numbers of removed beats.
    // TODO: Write Test 3
    if (select_next_beat(test_track) != TRACK_PLAYING) {
        return DOES_NOT_MEET_SPEC;
    }

    return MEETS_SPEC;
}

// Test function for `add_musical_note_to_beat`
int test_add_musical_note_to_beat(void){
    // Test 1: Adding a musical note.
    // TODO: Write Test 1
    Beat test_beat = create_beat();
    if (add_musical_note_to_beat(test_beat, "0A") != VALID_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Adding a repeated note.
    // TODO: Write Test 2
    if (add_musical_note_to_beat(test_beat, "0A") != INVALID_MUSICAL_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: Checking whether addition successful.
    // TODO: Write Test 3
    if (count_notes_in_octave(test_beat, 0) != 1) {
        return DOES_NOT_MEET_SPEC;
    }

    return MEETS_SPEC;
}
