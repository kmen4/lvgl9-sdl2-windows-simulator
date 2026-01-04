/*
 * MIT License
 *
 * Copyright (c) 2025-2026 Erriez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "SDL.h"
#include "lvgl.h"
#include "lv_demos.h"

/* SDL timer callback: Called every 'interval' milliseconde */
static Uint32 tick_thread(Uint32 interval, void *param)
{
    LV_UNUSED(param);
    lv_tick_inc(interval);
    return interval;
}

int main(void)
{
    /* SDL init for timer + event loop (video init is for lv_sdl_window internal) */
    if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
        return -1;
    }

    /* Initialize LVGL */
    lv_init();

    /* Start LVGL tick timer (1 ms) */
    SDL_AddTimer(1, tick_thread, NULL);

    /* Create SDL window + display driver (800x480) */
    lv_display_t *disp = lv_sdl_window_create(800, 480);
    if(disp == NULL) {
        return -1;
    }

    /* Input devices */
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();
    lv_sdl_mousewheel_create();

    /* Enable ONE of the demo functions below */
    lv_demo_widgets();
    // lv_demo_music();
    // lv_demo_benchmark();
    // lv_demo_keypad_encoder();

    /* Main loop */
    while(1) {
        lv_timer_handler();
        SDL_Delay(5);
    }

    return 0;
}