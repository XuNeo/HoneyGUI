
#include <gui_tabview.h>
#include "gui_card.h"
#include <gui_obj.h>
#include <gui_win.h>
#include <gui_text.h>
#include <gui_curtain.h>
#include "root_image/ui_resource.h"
#include <gui_app.h>
#include "gui_tab.h"
#include "draw_font.h"
#include <gui_img.h>
#include "gui_canvas.h"
#include "app_gui_main.h"
#include "app_gui_cube.h"
#include "gui_cube.h"
#include "gui_win.h"
#include "gui_server.h"
#include "gui_components_init.h"
#include <stdio.h>

static void design_app_cube_ui(gui_app_t *app);

static uint16_t longtouch_count = 0;
static void win_switch_main_to_app_touch_cb(void *obj, gui_event_t event)
{
    switch (event)
    {
    case GUI_EVENT_TOUCH_LONG:
        gui_log("win_switch_main_to_app_touch_cb, event = %d longtouch_count = %d\n", event,
                longtouch_count);
        longtouch_count++;
        if (longtouch_count > 30)
        {
            longtouch_count = 0;
            gui_switch_app(get_app_cube_ui(), get_app_watch_ui());
        }
        break;
    case GUI_EVENT_TOUCH_RELEASED:
        longtouch_count = 0;
        break;

    default:
        break;

    }
}

static gui_app_t app_cube_ui =
{
    .screen =
    {
        .name = "app_cube",
        .x    = 0,
        .y    = 0,
        .parent = NULL,
    },
    .ui_design = design_app_cube_ui,
    .thread_entry = NULL,
    .active_ms = 1000000,
};

void *get_app_cube_ui(void)
{
    return &app_cube_ui;
}

static void design_app_cube_ui(gui_app_t *app)
{
    gui_log("design_app_cube_ui\n");

    gui_font_mem_init(FONT_BIN);

    gui_cube_imgfile_t image_file;
    memset(&image_file, 0, sizeof(gui_cube_imgfile_t));
    for (int i = 0; i < 6; i++)
    {
        image_file.src_mode[i] = IMG_SRC_MEMADDR;
    }
    image_file.data_addr.data_addr_up = B1_RLE_BIN;
    image_file.data_addr.data_addr_down = B2_RLE_BIN;
    image_file.data_addr.data_addr_front = B3_RLE_BIN;
    image_file.data_addr.data_addr_left = B4_RLE_BIN;
    image_file.data_addr.data_addr_right = B5_RLE_BIN;
    image_file.data_addr.data_addr_back = B6_RLE_BIN;
    gui_cube_t *ccc = gui_cube_create(&(app->screen), "ccc", &image_file, 0, 0);
    gui_cube_set_center(ccc, 227, 227);
    gui_cube_set_size(ccc, 75);
    gui_cube_auto_rotation_by_y(ccc, 100, 5.5f);

    gui_win_t *win_switch_to_main_app = gui_win_create(&(app->screen), "win_switch_to_main_app", 0, 0,
                                                       454, 454);
    gui_win_onLong(win_switch_to_main_app, win_switch_main_to_app_touch_cb, NULL);
    gui_win_onRelease(win_switch_to_main_app, win_switch_main_to_app_touch_cb, NULL);
    gui_fb_change();
}

