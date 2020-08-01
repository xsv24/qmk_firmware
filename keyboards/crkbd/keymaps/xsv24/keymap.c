#include QMK_KEYBOARD_H

bool is_tap (qk_tap_dance_state_t *state);
void tap_or_hold (qk_tap_dance_state_t *state, uint16_t key, uint16_t layer);
void release_on_fin (qk_tap_dance_state_t *state, uint16_t layer);

void lower_tab_tap_or_hold (qk_tap_dance_state_t *state, void *user_data);
void raise_caps_tap_or_hold (qk_tap_dance_state_t *state, void *user_data);

void lower_tab_release_on_fin (qk_tap_dance_state_t *state, void *user_data);
void raise_caps_release_on_fin (qk_tap_dance_state_t *state, void *user_data);

void lower_mac_tab_tap_or_hold (qk_tap_dance_state_t *state, void *user_data);
void raise_mac_caps_tap_or_hold (qk_tap_dance_state_t *state, void *user_data);

void lower_mac_tab_release_on_fin (qk_tap_dance_state_t *state, void *user_data);
void raise_mac_caps_release_on_fin (qk_tap_dance_state_t *state, void *user_data);

#ifdef SSD1306OLED
// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _MAC_QWERTY 4
#define _MAC_LOWER 5
#define _MAC_RAISE 6
#define _MAC_ADJUST 7

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    MAC_QWERTY,
    MAC_LOWER,
    MAC_RAISE,
    MAC_ADJUST,
    TOGG_ALT
};

enum macro_keycodes {
    KC_SAMPLEMACRO,
};

//  Tap Dance Definitions // TD()
enum tab_dance_actions {
    TD_WIN_LOWER,
    TD_WIN_RAISE,
    TD_MAC_LOWER,
    TD_MAC_RAISE
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_WIN_LOWER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lower_tab_tap_or_hold, lower_tab_release_on_fin, 275),
    [TD_WIN_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, raise_caps_tap_or_hold, raise_caps_release_on_fin, 275),
    [TD_MAC_LOWER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lower_mac_tab_tap_or_hold, lower_mac_tab_release_on_fin, 275),
    [TD_MAC_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, raise_mac_caps_tap_or_hold, raise_mac_caps_release_on_fin, 275)
};

// Togglable values
bool mac = false;
bool alt_on = false;
bool shift_on = false;

// TAP Keys on HOLD changes layer
uint16_t RASIE_TAP_KEY = KC_CAPS;
uint16_t LOWER_TAP_KEY = KC_TAB;

// Windows Marcos

#define WIN_LOWER TD(TD_WIN_LOWER)
#define WIN_RAISE TD(TD_WIN_RAISE)

#define CURS_LEFT RCTL(KC_LEFT)
#define CURS_RIGHT RCTL(KC_RIGHT)

#define ALL LCTL(KC_A)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Y)

#define SLT_UP RCTL(RSFT(KC_UP))
#define SLT_DOWN RCTL(RSFT(KC_DOWN))
#define SLT_LEFT RCTL(RSFT(KC_LEFT))
#define SLT_RIGHT RCTL(RSFT(KC_RIGHT))

#define SLT_L_LN RSFT(KC_HOME)
#define SLT_R_LN RSFT(KC_END)

#define ADD_CURS_DN RCTL(RALT(KC_DOWN))
#define ADD_CURS_UP RCTL(RALT(KC_UP))

#define MV_UP RALT(KC_UP)
#define MV_DN RALT(KC_DOWN)

#define DUP_LN RCTL(KC_D)
#define DEL_LN RCTL(KC_X)
#define DEL_WORD RCTL(KC_BSPC)

#define GO_BRAK RSFT(RCTL(KC_BSLS))
#define GO_METH RCTL(RSFT(KC_O))
#define PEEK RALT(KC_F12)
#define OPEN_FS RCTL(RSFT(KC_TAB))

#define COLPSE RCTL(RSFT(KC_LBRC))
#define UN_COLPSE RCTL(RSFT(KC_RBRC))

#define WIN_LEFT RGUI(RCTL(KC_LEFT))
#define WIN_RIGHT RGUI(RCTL(KC_RIGHT))
#define EXPLORE RCTL(RSFT(KC_E))
#define REPO RCTL(RSFT(KC_G))


// Mutal Macros

#define CTL_Q RCTL(KC_Q)
#define PLAY KC_MEDIA_PLAY_PAUSE
#define KC_AUDIO_MUTE
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define PREV KC_MEDIA_PREV_TRACK
#define NEXT KC_MEDIA_NEXT_TRACK
#define TAB_WIN RGUI(KC_TAB)
// Mac Marcos

#define MAC_LOWER TD(TD_MAC_LOWER)
#define MAC_RAISE TD(TD_MAC_RAISE)

#define M_CURS_LEFT RALT(KC_LEFT)
#define M_CURS_RIGHT RALT(KC_RIGHT)

#define M_ALL LGUI(KC_A)
#define M_CUT LGUI(KC_X)
#define M_COPY LGUI(KC_C)
#define M_PASTE LGUI(KC_V)
#define M_UNDO LGUI(KC_Y)

#define M_SLT_UP RCTL(RSFT(KC_RIGHT))
#define M_SLT_DN RCTL(RSFT(KC_LEFT))
#define M_SLT_LEFT RALT(RSFT(KC_LEFT))
#define M_SLT_RIGHT RALT(RSFT(KC_RIGHT))

#define M_SLT_L_LN RGUI(RSFT(KC_LEFT))
#define M_SLT_R_LN RGUI(RSFT(KC_RIGHT))

#define M_ADD_CURS_DN RGUI(RALT(KC_DOWN))
#define M_ADD_CURS_UP RGUI(RALT(KC_UP))

#define M_MV_UP RALT(KC_UP)
#define M_MV_DN RALT(KC_DOWN)

#define M_DUP_LN RSFT(RALT(KC_DOWN))
#define M_DEL_LN RGUI(KC_X)
#define M_DEL_WORD RALT(KC_BSPC)

#define M_GO_BRAK RSFT(RGUI(KC_BSLS))
#define M_GO_METH RSFT(RGUI(KC_O))
#define M_PEEK RALT(KC_F12)
#define M_OPEN_FS RCTL(RSFT(KC_TAB))

#define M_COLPSE RCTL(RSFT(KC_LBRC))
#define M_UN_COLPSE RCTL(RSFT(KC_RBRC))

#define MAC_LEFT RCTL(KC_LEFT)
#define MAC_RIGHT RCTL(KC_RIGHT)

#define M_FIND RGUI(RSFT(KC_F))
#define M_EXPLORE RCTL(RSFT(KC_E))
#define M_REPO RCTL(RSFT(KC_G))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \

            KC_ESC,   KC_Q, KC_W,   KC_E,    KC_R,   KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\

            KC_LCTRL, KC_A, KC_S,   KC_D,    KC_F,   KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\

            KC_LSFT,  KC_Z, KC_X,   KC_C,    KC_V,   KC_B,                      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\

            TOGG_ALT, WIN_LOWER,  KC_SPC,  KC_ENT,  WIN_RAISE,  KC_RGUI\
    ),
    [_RAISE] = LAYOUT( \

            KC_ESC,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,			            KC_6,    KC_7,      KC_8,    KC_9,      KC_0,    KC_BSPC,\

            KC_LCTRL, ALL, KC_MS_L, KC_MS_U, KC_MS_R, KC_BTN1,                  KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT,   KC_WH_U, KC_PSCR,\

            KC_LSFT,  UNDO, CUT,    KC_MS_D, PASTE,   KC_BTN2,                  CURS_LEFT, KC_PGDN,  KC_PGUP, CURS_RIGHT, KC_WH_D, KC_RSFT,\

            TOGG_ALT, WIN_LOWER,  KC_SPC,  KC_ENT,  WIN_RAISE, KC_RGUI\
    ),
    [_LOWER] = LAYOUT( \

            KC_ESC,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\

            KC_LCTRL, KC_F1,  KC_F2,  KC_F3,   KC_F5,  KC_F10,                  KC_EQL, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE,  KC_GRV,\

            KC_LSFT, UNDO,    KC_F12, COPY,    PASTE,  KC_F11,	                KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR,   KC_BSLS, KC_TILD,\

            TOGG_ALT, WIN_LOWER, KC_SPC,  KC_ENT,  WIN_RAISE, KC_RGUI\
    ),
    [_ADJUST] = LAYOUT( \

            MAC_QWERTY, CTL_Q,  GO_METH, EXPLORE,  REPO,  COLPSE,		        UN_COLPSE, KC_U,    GO_BRAK, OPEN_FS,    PEEK,   DEL_WORD,\

            KC_LCTRL,   ALL,    WIN_LEFT, MV_UP,  MV_DN,  WIN_RIGHT,            SLT_LEFT,  SLT_DOWN, SLT_UP, SLT_RIGHT,  KC_SCLN,  KC_PSCR,\

            KC_LSFT,    UNDO,    DEL_LN,  COPY,   PASTE,  KC_B,                 SLT_L_LN,  ADD_CURS_DN, ADD_CURS_UP, SLT_R_LN,   KC_ACL2,  KC_RSFT,\

            TOGG_ALT,  WIN_LOWER, KC_SPC,  KC_ENT,    WIN_RAISE,  KC_RGUI\
    ),
    [_MAC_QWERTY] = LAYOUT( \

            KC_ESC,    	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\

            KC_RGUI,	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\

            KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\

            TOGG_ALT, MAC_LOWER, KC_SPC,  KC_ENT,  MAC_RAISE, KC_LCTRL\
    ),
    [_MAC_RAISE] = LAYOUT( \

            KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,			    KC_6,    KC_7,        KC_8,    KC_9,      KC_0,    KC_BSPC,\

            KC_RGUI, 	KC_6,    KC_7,    KC_8,    KC_9,    KC_0,               KC_LEFT, KC_DOWN,     KC_UP,   KC_RIGHT,  KC_WH_U, KC_PSCR,\

            KC_LSFT,    PLAY,   VOL_UP,  VOL_DOWN, NEXT,    PREV,               M_CURS_LEFT, KC_PGDN, KC_PGUP, M_CURS_RIGHT, KC_WH_D, KC_RSFT,\

            TOGG_ALT,  MAC_LOWER, KC_SPC,  KC_ENT, MAC_RAISE,  KC_LCTRL\
    ),
    [_MAC_LOWER] = LAYOUT( \

            KC_ESC,  KC_EXLM,  KC_AT,     KC_HASH,  KC_DLR,  KC_PERC,           KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\

            KC_RGUI, KC_TAB,   KC_LCBR,   KC_RCBR,  KC_LPRN, KC_RPRN,           KC_EQL,  KC_PLUS,  KC_LBRC, KC_RBRC, KC_PIPE,  KC_GRV,\

            KC_LSFT, KC_UNDO,  KC_CUT,   KC_CAPS,   KC__MUTE, KC_DEL,            KC_UNDS, KC_MINS,  KC_LT,   KC_GT,   KC_BSLS, KC_TILD,\

            TOGG_ALT, MAC_LOWER, KC_SPC,  KC_ENT, MAC_RAISE, KC_LCTRL\
    ),
    [_MAC_ADJUST] = LAYOUT( \

            QWERTY,   CTL_Q,    M_GO_METH,  M_EXPLORE,  M_REPO, M_COLPSE,		M_UN_COLPSE, KC_U,    M_GO_BRAK, M_OPEN_FS,   M_PEEK,   KC_BSPC,\

            KC_LCTRL, KC_F1,    MAC_LEFT,   KC_F3,    TAB_WIN, MAC_RIGHT,	    M_SLT_LEFT, M_SLT_DN, M_SLT_UP,  M_SLT_RIGHT, KC_SCLN,  KC_PSCR,\

            KC_LSFT,  KC_F2,    KC_F5,      KC_F10,   KC_F11,   KC_F12,           M_SLT_L_LN, M_ADD_CURS_DN, M_ADD_CURS_UP, M_SLT_R_LN,  KC_ACL2,  KC_RSFT,\

            TOGG_ALT,  MAC_LOWER, KC_SPC,  KC_ENT,   MAC_RAISE, KC_LCTRL\
    )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// Tap dance helpers
void on_double_hold(uint16_t layer1, uint16_t layer2, uint16_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef SSD1306OLED
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    // reset keyboard if layers stuck!
    //persistent_default_layer_set(1UL<<_MAC_QWERTY);
    //reset_keyboard();

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                mac = false;
                persistent_default_layer_set(1UL<<_QWERTY);
            }
            return false;

        case MAC_QWERTY:
            if(record->event.pressed) {
                mac = true;
                persistent_default_layer_set(1UL<<_MAC_QWERTY);
            }
            return false;

        case TOGG_ALT:
            if(record->event.pressed) {
                if(alt_on) {
                    alt_on = false;
                    unregister_code(KC_RALT);
                } else {
                    alt_on = true;
                    register_code(KC_RALT);
                }
            }
            return false;

        default:
            return true;
    }
}

bool is_tap (qk_tap_dance_state_t *state) {
    if (state->count == 1 && !state->pressed) {
        return true;
    }

  return false;
}

// MAC transitions

void tap_or_hold_mac(qk_tap_dance_state_t *state, uint16_t key, uint16_t layer) {
  if (is_tap(state)) {
      tap_code(key);

  } else {
      layer_on(layer);
      on_double_hold(_MAC_LOWER, _MAC_RAISE, _MAC_ADJUST);
  }
}

void release_on_fin_mac (qk_tap_dance_state_t *state, uint16_t layer) {
  if (IS_LAYER_ON(layer)) {
    layer_off(layer);
    on_double_hold(_MAC_LOWER, _MAC_RAISE, _MAC_ADJUST);
  }
}

void raise_mac_caps_tap_or_hold(qk_tap_dance_state_t *state, void *user_data) {
    tap_or_hold_mac(state, RASIE_TAP_KEY, _MAC_RAISE);
}

void raise_mac_caps_release_on_fin(qk_tap_dance_state_t *state, void *user_data) {
    release_on_fin_mac(state, _MAC_RAISE);
}

void lower_mac_tab_tap_or_hold(qk_tap_dance_state_t *state, void *user_data) {
    tap_or_hold_mac(state, LOWER_TAP_KEY, _MAC_LOWER);
}

void lower_mac_tab_release_on_fin(qk_tap_dance_state_t *state, void *user_data) {
    release_on_fin_mac(state, _MAC_LOWER);
}


// WINDOWS transitions

void tap_or_hold (qk_tap_dance_state_t *state, uint16_t key, uint16_t layer) {
  if (is_tap(state)) {
    tap_code(key);

  } else {
      layer_on(layer);
      on_double_hold(_LOWER, _RAISE, _ADJUST);
  }
}

void release_on_fin (qk_tap_dance_state_t *state, uint16_t layer) {
  if (IS_LAYER_ON(layer)) {
    layer_off(layer);
    on_double_hold(_LOWER, _RAISE, _ADJUST);
  }
}

void raise_caps_tap_or_hold (qk_tap_dance_state_t *state, void *user_data) {
  tap_or_hold(state, RASIE_TAP_KEY, _RAISE);
}

void raise_caps_release_on_fin (qk_tap_dance_state_t *state, void *user_data) {
  release_on_fin(state, _RAISE);
}

void lower_tab_tap_or_hold (qk_tap_dance_state_t *state, void *user_data) {
  tap_or_hold(state, LOWER_TAP_KEY, _LOWER);
}

void lower_tab_release_on_fin (qk_tap_dance_state_t *state, void *user_data) {
  release_on_fin(state, _LOWER);
}


// OLED STUFF

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  char os_state_str[9];

  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    if(mac){
        snprintf(os_state_str, sizeof(os_state_str), "OS: MAC");
    } else {
        snprintf(os_state_str, sizeof(os_state_str), "OS: WIN");
    }
    matrix_write_ln(matrix, os_state_str);
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //fmatrix_write_ln(matrix, read_mode_icon(rig.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED
