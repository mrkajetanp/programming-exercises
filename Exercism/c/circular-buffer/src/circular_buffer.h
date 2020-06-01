#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

typedef int buffer_value_t;

typedef struct {
    size_t capacity;
    size_t length;

    size_t read_cursor;
    size_t write_cursor;

    buffer_value_t* items;
} circular_buffer_t;

circular_buffer_t* new_circular_buffer(size_t);

void delete_buffer(circular_buffer_t*);
void clear_buffer(circular_buffer_t*);

int16_t read(circular_buffer_t*, buffer_value_t*);
int16_t write(circular_buffer_t*, buffer_value_t);
int16_t overwrite(circular_buffer_t*, buffer_value_t);

#endif
