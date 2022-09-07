#pragma once

#include "defines.h"

typedef struct event_context {
    union {
        i64 i64[2];
        u64 u64[2];
        f64 f64[2];

        i32 i32[4];
        u32 u32[4];
        f32 f32[4];

        i16 i16[8];
        u16 u16[8];

        i8 i8[16];
        u8 u8[16];

        char c[16];
    } data;
} event_context;

typedef b8 (*PFN_on_event)(u16 code, void* sender, void* listener_inst, event_context data);

void event_system_initialize();
void event_system_shutdown();

/**
 * Register to listen for when events are sent with the provided code. Events with duplicate
 * listener/callback combos will not be registered again and will cause this to return false.
 * @param code The event to listen for.
 * @param listener a pointer to a listener instance. Can be 0/NULL.
 * @param on_event The callback function point to be invoked when the event is fired.
 * @returns true if the event is successfully registered; otherwise false.
 */
SAPI b8 event_register(u16 code, void* listener, PFN_on_event event);

/**
 * Unregister from listening for when events are sent with the provided code. If no matching
 * registration is found, this function returns false.
 * @param code The event to stop listening for.
 * @param listener a pointer to a listener instance. Can be 0/NULL.
 * @param on_event The callback function to be unregistered.
 * @returns true if the event is successfully unregistered; otherwise false.
 */
SAPI b8 event_unregister(u16 code, void* listener, PFN_on_event event);

/**
 * Fires an event to listeners of the given code. If the event handler returns
 * true, the event is considered handled and is not passed on to any more listeners.
 * @param code The event code to fire.
 * @param sender a pointer to the sender. Can be 0/NULL.
 * @param data the event data.
 * @returns true if handled; otherwise false.
 */
SAPI b8 event_fire(u16 code, void* sender, event_context context);

// System internal event codes, applications should use codes beyond 255.
typedef enum system_event_code {
    EVENT_CODE_APPLICATION_QUIT = 0x01,
    EVENT_CODE_KEY_PRESSED = 0x02,
    EVENT_CODE_KEY_RELEASED = 0x03,
    EVENT_CODE_BUTTON_PRESSED = 0x04,
    EVENT_CODE_BUTTON_RELEASED = 0x05,
    EVENT_CODE_MOUSE_MOVED = 0x06,
    EVENT_CODE_MOUSE_WHEEL = 0x07,
    EVENT_CODE_RESIZED = 0x08,
    MAX_EVENT_CODE = 0xFF
} system_event_code;