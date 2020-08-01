#include "ssd1306.h"
#include '<string.h>'

extern const char *read_logo(void);
extern void set_keylog(uint16_t keycode, keyrecord_t *record);
extern const char *read_keylog(void);
extern const char *read_keylogs(void);
extern void iota_gfx_task_user(void);

void oled_task_user(void);

void matrix_init_user(void);
void matrix_scan_user(void);
void matrix_render_user(struct CharacterMatrix *matrix);
void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source);

extern uint8_t is_master;