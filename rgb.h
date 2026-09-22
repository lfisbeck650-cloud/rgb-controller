#ifndef RGB_H
#define RGB_H

#include <stdint.h>

#define RGB_PATTERN_SOLID     0x01
#define RGB_PATTERN_BREATHING 0x02
#define RGB_PATTERN_WAVE      0x03
#define RGB_PATTERN_BLINKING  0x12
#define RGB_PATTERN_FLOW      0x13

int rgb_open(void);
void rgb_close(void);
int rgb_set_region(uint8_t region, uint8_t r, uint8_t g, uint8_t b);
int rgb_set_all(uint8_t r, uint8_t g, uint8_t b);
int rgb_set_pattern(uint8_t pattern, uint8_t speed, uint8_t intensity);

#endif