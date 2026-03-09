#pragma once

// Unique Vial UID for K15 Max ANSI RGB
#define VIAL_KEYBOARD_UID {0xF1, 0x57, 0xA1, 0x90, 0x23, 0x6C, 0x4E, 0x11}

// Unlock combo: matrix extremes
#define VIAL_UNLOCK_COMBO_ROWS { 0, 5 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 15 }

// Keep 8 dynamic layers within the K15 Max 2KB EEPROM budget.
#define VIAL_TAP_DANCE_ENTRIES 8
#define VIAL_COMBO_ENTRIES 8
#define VIAL_KEY_OVERRIDE_ENTRIES 8
#define VIAL_ALT_REPEAT_KEY_ENTRIES 8
