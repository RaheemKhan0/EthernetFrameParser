#ifndef TAP_H
#define TAP_H

#include <cstdint>
int tap_open(const char* dev);
int tap_read(int fd, uint8_t *buf, int buflen);
int tap_write(int fd, uint8_t *buf, int buflen);



#endif // !DEBUG
