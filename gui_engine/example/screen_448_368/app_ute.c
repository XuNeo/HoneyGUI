#include <gui_tabview.h>
#include "gui_cardview.h"
#include "gui_card.h"
#include <gui_obj.h>
#include <gui_win.h>
#include <gui_text.h>
#include <gui_curtain.h>
#include "ute.h"
#include <gui_app.h>
#include "gui_tab.h"
#include "gui_perspective.h"
#include "draw_font.h"
#include <gui_magic_img.h>
#include "gui_switch.h"

static void app_ute_ui_design(gui_app_t *app);
static gui_tabview_t *tv;
static gui_tabview_t *tv_up;
static gui_win_t *win;


static gui_app_t app_ute =
{
    .screen =
    {
        .name = "app_ute",
        .x    = 0,
        .y    = 0,
    },
    .ui_design = app_ute_ui_design,
    .thread_entry = NULL,
    .active_ms = 1000000,
};

void *get_app_ute(void)
{
    return &app_ute;
}

static void callback(void *obj, gui_event_t e)
{
    gui_log("win widget long touch enter cb\n");

    gui_tree_free(tv);

    gui_cardview_t *tv = gui_cardview_create(win, "cardview", 0, 0, 0, 0);
    gui_cardview_set_style(tv, STACKING);
    gui_card_t *tb_watch = gui_card_create(tv, "tb_watch",             0, 0, 0, 0, 0, 0);
    gui_card_t *tb_sport = gui_card_create(tv, "tb_sport",             0, 0, 0, 0, 0, 1);
    gui_card_t *tb_colorwheel = gui_card_create(tv, "tb_colorwheel",   0, 0, 0, 0, 0, 2);
    gui_card_t *tb_cube = gui_card_create(tv, "tb_cube",               0, 0, 0, 0, 0, 3);
    gui_card_t *tb_svg = gui_card_create(tv, "tb_svg",                 0, 0, 0, 0, 0, 4);
    gui_card_t *tb_wave = gui_card_create(tv, "tb_wave",               0, 0, 0, 0, 0, 5);
    gui_card_t *tb_60 = gui_card_create(tv, "tb_60",                     0, 0, 0, 0, 0, 6);
    gui_card_t *tb_70 = gui_card_create(tv, "tb_70",                     0, 0, 0, 0, 0, 7);

    gui_cardview_set_style(tv, STACKING);

    gui_magic_img_create_from_mem(tb_watch, "page0", CLOCKN_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_sport, "page1", ACTIVITY_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_colorwheel, "page2", HEARTRATE_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_cube, "page3", BLOODOXYGEN_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_svg, "page4", STRESS_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_wave, "page5", SLEEPN_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_60, "page6", WEATHER_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_70, "page7", MUSIC_BIN, 0, 0, 0, 0);

}

static void app_ute_ui_design(gui_app_t *app)
{
    gui_log("app_ute_ui_design\n");

    win = gui_win_create(&(app->screen), "win", 0, 0, 320, 320);
    gui_obj_add_event_cb(win, (gui_event_cb_t)callback, GUI_EVENT_TOUCH_LONG, NULL);

    tv = gui_tabview_create(win, "tabview", 0, 0, 0, 0);
    gui_tabview_set_style(tv, REDUCTION);
    gui_tab_t *tb_watch = gui_tab_create(tv, "tb_watch",             0, 0, 0, 0, 0, 0);
    gui_tab_t *tb_sport = gui_tab_create(tv, "tb_sport",             0, 0, 0, 0, 1, 0);
    gui_tab_t *tb_colorwheel = gui_tab_create(tv, "tb_colorwheel",   0, 0, 0, 0, 2, 0);
    gui_tab_t *tb_cube = gui_tab_create(tv, "tb_cube",               0, 0, 0, 0, 3, 0);
    gui_tab_t *tb_svg = gui_tab_create(tv, "tb_svg",                 0, 0, 0, 0, 4, 0);
    gui_tab_t *tb_wave = gui_tab_create(tv, "tb_wave",               0, 0, 0, 0, 5, 0);
    gui_tab_t *tb_60 = gui_tab_create(tv, "tb_60",                     0, 0, 0, 0, 6, 0);
    gui_tab_t *tb_70 = gui_tab_create(tv, "tb_70",                     0, 0, 0, 0, 7, 0);


    // gui_magic_img_create_from_mem(tb_watch, "page0", CLOCKN_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_sport, "page1", ACTIVITY_BIN, 0, 0, 0, 0);       //ACTIVITY_BIN
    gui_magic_img_create_from_mem(tb_colorwheel, "page2", HEARTRATE_BIN, 0, 0, 0, 0); //HEARTRATE_BIN
    gui_magic_img_create_from_mem(tb_cube, "page3", BLOODOXYGEN_BIN, 0, 0, 0, 0);     //BLOODOXYGEN_BIN
    gui_magic_img_create_from_mem(tb_svg, "page4", STRESS_BIN, 0, 0, 0, 0);           //STRESS_BIN
    gui_magic_img_create_from_mem(tb_wave, "page5", SLEEPN_BIN, 0, 0, 0, 0);          //SLEEPN_BIN
    gui_magic_img_create_from_mem(tb_60, "page6", WEATHER_BIN, 0, 0, 0, 0);           //WEATHER_BIN
    gui_magic_img_create_from_mem(tb_70, "page7", MUSIC_BIN, 0, 0, 0, 0);             //MUSIC_BIN


    gui_curtainview_t *ct = gui_curtainview_create(tb_watch, "ct", 0, 0, 368, 448);
    gui_curtain_t *c1 = gui_curtain_create(ct, "1", 0, 0, 368, 448, CURTAIN_MIDDLE, 1);
    gui_curtain_t *c2 = gui_curtain_create(ct, "2", 0, 0, 368, 448, CURTAIN_UP, 1);
    gui_curtain_t *c3 = gui_curtain_create(ct, "3", 0, 0, 368, 448, CURTAIN_DOWN, 1);
    gui_magic_img_create_from_mem(c1, "page0", CLOCKN_BIN, 0, 0, 0, 0);                     //CLOCKN_BIN
    // gui_magic_img_create_from_mem(c2, "page_up", CONTROLMENU_0_BIN, 0, 0, 0, 0);            //CONTROLMENU_0_BIN
    gui_magic_img_create_from_mem(c3, "page_down", MESSAGE_BIN, 0, 0, 0,
                                  0);                //MESSAGE_BIN


    tv_up = gui_tabview_create(c2, "tabview_up", 0, 0, 0, 0);
    gui_tabview_set_style(tv_up, CLASSIC);
    gui_tab_t *tb_up = gui_tab_create(tv_up, "tb_control0",          0, 0, 0, 0, 0, 0);
    gui_tab_t *tb_up_right = gui_tab_create(tv_up, "tb_control1",    0, 0, 0, 0, 1, 0);
    gui_magic_img_create_from_mem(tb_up, "page_up", CONTROLMENU_0_BIN, 0, 0, 0, 0);
    gui_magic_img_create_from_mem(tb_up_right, "page_up_right", CONTROLMENU_1_BIN, 0, 0, 0, 0);

}
