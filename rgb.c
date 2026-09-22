#include "rgb.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/hidraw.h>

#define HID_DEVICE "/dev/hidraw1"

static int fd = -1;

int rgb_open(void)
{
    fd = open(HID_DEVICE, O_RDWR);

    if (fd < 0) {
        perror("open");
        return -1;
    }

    return 0;
}

void rgb_close(void)
{
    if (fd >= 0) {
        close(fd);
        fd = -1;
    }
}

int rgb_set_region(uint8_t region, uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t report[8] = {
        0x14,
        0x00,
        region,
        r,
        g,
        b,
        0x00,
        0x00
    };

    if (ioctl(fd, HIDIOCSFEATURE(sizeof(report)), report) < 0) {
        perror("HIDIOCSFEATURE");
        return -1;
    }

    return 0;
}

int rgb_set_all(uint8_t r, uint8_t g, uint8_t b)
{
    for (uint8_t region = 1; region <= 7; region++) {
        if (rgb_set_region(region, r, g, b) < 0)
            return -1;
    }

    return 0;
}

int rgb_set_pattern(uint8_t pattern, uint8_t speed, uint8_t intensity)
{
    uint8_t report[8] = {
        0x08,
        0x02,
        pattern,
        speed,
        intensity,
        0x08,
        0x00,
        0x01
    };

    if (ioctl(fd, HIDIOCSFEATURE(sizeof(report)), report) < 0) {
        perror("HIDIOCSFEATURE");
        return -1;
    }

    return 0;
}