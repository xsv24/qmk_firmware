#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_ADJUST_TRI 14

#define L_MAC 16
#define L_MAC_LOWER 32
#define L_MAC_RAISE 64
#define L_MAC_ADJUST 224

char layer_state_str[24];
char os_state_str[9];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ABC");
            break;
        case L_RAISE:
        case L_MAC_RAISE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: { } </>");
            break;
        case L_LOWER:
        case L_MAC_LOWER:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: (8) & =>");
            break;
        case L_ADJUST:
        case L_MAC_ADJUST:
        case L_ADJUST_TRI:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: FUNC");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld ?", layer_state);
    }

    return layer_state_str;
}
