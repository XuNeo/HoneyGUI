# Wheel list

<br/>

## Overview

The wheellist widget is an application list interface, mainly composed of application icons arranged in multiple circular layers. Each layer can rotate independently, and each icon can have an associated callback.

## Usage

### Create a wheel list

[gui_wheel_list_t *gui_wheel_list_create(void *parent, uint8_t layer, uint8_t radius, uint8_t distence)](#api) creates a wheel list widget.

`layer` is the number of layers of the round wheel, 1 means there is one circle of outer icons in addition to the center icon.

`radius` is the radius of the icon. If the icon is square, it is half of the side length of the icon image. This value needs to be accurate, otherwise errors will occur in the icon arrangement calculation and position calculation.

`distance` is the distance between the centers of the icons of two adjacent layers, which needs to be greater than the diameter or side length of the icon.

In Layer 0, there is a central icon, whose center is at the center of the screen. This point serves as the reference for calculating the positions of other icons.
The number of icons in each layer is 6*n, where n represents the number of icon layers. Therefore, the closer to the outer layer, the more icons there are, and the smaller the angle between the centers of adjacent icons and the center of the screen on the same layer.

### Add icon

#### Default

After creating the wheel list widget, you can use the default interface for adding icons. In the wheel, corresponding icons can be added from the inside out in a layer-by-layer fashion.
[void gui_wheel_list_add_icon_default(gui_wheel_list_t *this, void *icon_addr,gui_event_cb_t event_cb)](#api)

`this` is the pointer to the widget.

`icon_addr` is the pointer to the address of the image.

`event_cb` is the callback function of this image, triggered by clicking.

##### Default example

<details> <summary>Example code</summary>

```c
#include "gui_wheel_list.h"
#include "gui_img.h"
#include "gui_app.h"
#include "root_image_8762g/ui_resource.h"

static void app_launcher_ui_design(gui_app_t *app);
static gui_app_t app_launcher =
{
    .screen =
    {
        .name = "app_launcher",
        .x    = 0,
        .y    = 0,
    },
    .ui_design = app_launcher_ui_design,
    .active_ms = 1000 * 5,
};
gui_app_t *get_launcher_app(void)
{
    return &app_launcher;
}

static void app_wheel_ui_design(gui_app_t *app);
static gui_app_t app_wheel =
{
    .screen =
    {
        .name = "app_wheel",
        .x    = 0,
        .y    = 0,
    },
    .ui_design = app_wheel_ui_design,
    .active_ms = 1000 * 5,
};
gui_app_t *get_wheel_app(void)
{
    return &app_wheel;
}

static void wheel_cb(void *obj, gui_event_t event)
{

}
static void switch_to_launcher(void *obj, gui_event_t event)
{
    gui_switch_app(get_wheel_app(), get_launcher_app());
}
static void app_wheel_ui_design(gui_app_t *app)
{
    gui_wheel_list_t *hc = gui_wheel_list_create(&app->screen, 2, 32, 80);
    gui_wheel_list_add_icon_default(hc, ICMENUALARM_BIN, switch_to_launcher);

    gui_wheel_list_add_icon_default(hc, ICMENUBIRD_BIN, wheel_cb);
    gui_wheel_list_add_icon_default(hc, ICMENUALBUM_BIN, wheel_cb);
    gui_wheel_list_add_icon_default(hc, ICMENUHEARTRATE_BIN, wheel_cb);
    gui_wheel_list_add_icon_default(hc, ICMENUMUSIC_BIN, wheel_cb);
    gui_wheel_list_add_icon_default(hc, ICMENUALARM_BIN, wheel_cb);
    gui_wheel_list_add_icon_default(hc, ICMENUBIRD_BIN, wheel_cb);

    gui_wheel_list_add_icon_default(hc, ICMENUALBUM_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUHEARTRATE_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUMUSIC_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUALARM_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUBIRD_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUALBUM_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUHEARTRATE_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUMUSIC_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUALARM_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUBIRD_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUALBUM_BIN, NULL);
    gui_wheel_list_add_icon_default(hc, ICMENUHEARTRATE_BIN, NULL);
}

static void app_launcher_ui_design(gui_app_t *app)
{

}

```

</details></br>

<center><img width="456" src= "https://foruda.gitee.com/images/1712042390527485103/b8f53fb0_9325830.gif"/></center>

<br/>

#### Customized

After creating the wheel list widget, you can use the default interface for adding icons. In the wheel, corresponding icons can be added from the inside out in a layer-by-layer fashion.
[gui_wheel_list_set_icon(gui_wheel_list_t *this, void *icon_addr, gui_event_cb_t event_cb, uint8_t layer, uint8_t index)](#api)

`this` is the pointer to the widget.

`icon_addr` is the pointer to the address of the image.

`event_cb` is the callback function of this image, triggered by clicking.

`layer` is the level or layer where the icon is located.

##### Customized example

<details> <summary>Example code</summary>

```c
#include "gui_wheel_list.h"
#include "gui_img.h"
#include "gui_app.h"
#include "root_image_8762g/ui_resource.h"

static void app_launcher_ui_design(gui_app_t *app);
static gui_app_t app_launcher =
{
    .screen =
    {
        .name = "app_launcher",
        .x    = 0,
        .y    = 0,
    },
    .ui_design = app_launcher_ui_design,
    .active_ms = 1000 * 5,
};
gui_app_t *get_launcher_app(void)
{
    return &app_launcher;
}

static void app_wheel_ui_design(gui_app_t *app);
static gui_app_t app_wheel =
{
    .screen =
    {
        .name = "app_wheel",
        .x    = 0,
        .y    = 0,
    },
    .ui_design = app_wheel_ui_design,
    .active_ms = 1000 * 5,
};
gui_app_t *get_wheel_app(void)
{
    return &app_wheel;
}

static void wheel_cb(void *obj, gui_event_t event)
{

}
static void switch_to_launcher(void *obj, gui_event_t event)
{
    gui_switch_app(get_wheel_app(), get_launcher_app());
}
static void app_wheel_ui_design(gui_app_t *app)
{
    gui_wheel_list_t *hc = gui_wheel_list_create(&app->screen, 2, 32, 80);
    gui_wheel_list_set_icon(hc, ICMENUALARM_BIN, switch_to_launcher, 0, 0);

    gui_wheel_list_set_icon(hc, ICMENUBIRD_BIN, wheel_cb, 1, 0);
    gui_wheel_list_set_icon(hc, ICMENUHEARTRATE_BIN, wheel_cb, 1, 2);
    gui_wheel_list_set_icon(hc, ICMENUALARM_BIN, wheel_cb, 1, 4);

    gui_wheel_list_set_icon(hc, ICMENUHEARTRATE_BIN, NULL, 2, 1);
    gui_wheel_list_set_icon(hc, ICMENUMUSIC_BIN, NULL, 2, 2);
    gui_wheel_list_set_icon(hc, ICMENUALARM_BIN, NULL, 2, 3);
    gui_wheel_list_set_icon(hc, ICMENUALBUM_BIN, NULL, 2, 5);
    gui_wheel_list_set_icon(hc, ICMENUHEARTRATE_BIN, NULL, 2, 6);
    gui_wheel_list_set_icon(hc, ICMENUMUSIC_BIN, NULL, 2, 7);
    gui_wheel_list_set_icon(hc, ICMENUBIRD_BIN, NULL, 2, 9);
    gui_wheel_list_set_icon(hc, ICMENUALBUM_BIN, NULL, 2, 10);
    gui_wheel_list_set_icon(hc, ICMENUHEARTRATE_BIN, NULL, 2, 11);
}

static void app_launcher_ui_design(gui_app_t *app)
{

}

```

</details></br>

<center><img width="456" src= "https://foruda.gitee.com/images/1712044916842211542/c5085ac7_9325830.gif"/></center>

<br/>

## API

```eval_rst

.. doxygenfile:: gui_wheel_list.h

```