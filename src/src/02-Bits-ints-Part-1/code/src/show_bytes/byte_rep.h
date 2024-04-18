// #include <Kernel/sys/_types/_size_t.h>
#ifndef BYTE_REP_H
#define BYTE_REP_H

typedef char *byte_pointer;
void show_bytes (byte_pointer start, size_t len);
void show_int (int x);
void show_float (float x);
void show_pointer (void* x);

#endif
