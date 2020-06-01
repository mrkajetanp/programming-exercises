#include "circular_buffer.h"

circular_buffer_t* new_circular_buffer(size_t capacity) {
    circular_buffer_t* result = malloc(sizeof(circular_buffer_t));
    result->length = 0;
    result->read_cursor = 0;
    result->write_cursor = 0;
    result->capacity = capacity;
    result->items = malloc(capacity * sizeof(buffer_value_t));
    return result;
}

void delete_buffer(circular_buffer_t* buffer) {
    free(buffer->items);
    free(buffer);
}

void clear_buffer(circular_buffer_t* buffer) {
    buffer->length = 0;
    buffer->read_cursor = 0;
    buffer->write_cursor = 0;
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* result) {
    // Buffer empty
    if (buffer->length == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    if (buffer->read_cursor == buffer->capacity)
        buffer->read_cursor = 0;

    *result = buffer->items[buffer->read_cursor++];
    buffer->length--;
    return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t* buffer, buffer_value_t value) {
    // Buffer full
    if (buffer->length == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    if (buffer->write_cursor == buffer->capacity)
        buffer->write_cursor = 0;

    buffer->items[buffer->write_cursor++] = value;
    buffer->length++;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value) {
    // Buffer full
    if (buffer->length == buffer->capacity)
        buffer->read_cursor++;
    else
        buffer->length++;

    if (buffer->write_cursor == buffer->capacity)
        buffer->write_cursor = 0;

    buffer->items[buffer->write_cursor++] = value;
    return EXIT_SUCCESS;
}
