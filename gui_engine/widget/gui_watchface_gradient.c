/*nt
 * File      : gui_watchface_gradient.c
 * This file is part of GUI Engine
 */
#include "gui_watchface_gradient.h"

#define WATCHFACE_GRADIENT_RING1 296.52
#define WATCHFACE_GRADIENT_RING2 192.17
#define WATCHFACE_GRADIENT_RING3 87.83
#define WATCHFACE_GRADIENT_BASE 368.0F
#define WATCHFACE_GRADIENT_SCLAE     (GET_BASE(canvas)->w/WATCHFACE_GRADIENT_BASE)
static void canvas_design(gui_canvas_t *canvas)
{
    gui_dispdev_t *dc = gui_get_dc();
    NVGcontext *vg = canvas->vg;
    gui_canvas_t *this = canvas;
    nvgResetTransform(vg);
    nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
    nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
    nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
    nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                 dc->screen_height / 2 - GET_BASE(this)->y);
    nvgScale(vg, this->base.sx, this->base.sy);
    nvgTranslate(vg, -(dc->screen_width / 2 - GET_BASE(this)->x),
                 -(dc->screen_height / 2 - GET_BASE(this)->y));
    nvgBeginPath(canvas->vg);
    nvgRect(canvas->vg, 0, 0, GET_BASE(canvas)->w, GET_BASE(canvas)->h);
    nvgFillColor(canvas->vg, nvgRGB(0x7C, 0x7A, 0xEB));
    nvgFill(canvas->vg);
    nvgBeginPath(canvas->vg);
    nvgCircle(canvas->vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2,
              WATCHFACE_GRADIENT_RING1 * WATCHFACE_GRADIENT_SCLAE / 2);
    nvgFillColor(canvas->vg, nvgRGBA(94, 92, 230, 0.5 * 0xff));
    nvgFill(canvas->vg);
    nvgBeginPath(canvas->vg);
    nvgCircle(canvas->vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2,
              WATCHFACE_GRADIENT_RING2 * WATCHFACE_GRADIENT_SCLAE / 2);
    nvgFillColor(canvas->vg, nvgRGBA(168, 167, 241, 0.5 * 0xff));
    nvgFill(canvas->vg);
    nvgBeginPath(canvas->vg);
    nvgCircle(canvas->vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2,
              WATCHFACE_GRADIENT_RING3 * WATCHFACE_GRADIENT_SCLAE / 2);
    nvgFillColor(canvas->vg, nvgRGBA(94, 92, 230, 0.5 * 0xff));
    nvgFill(canvas->vg);
    static float second;
    second++;
    float hour_degree = (second / 3600.0f) / 12.0f * 2 * NVG_PI;

    {
        //for hour point
        nvgResetTransform(vg);

        nvgBeginPath(vg);

        float width = 5 * WATCHFACE_GRADIENT_SCLAE;
        float height = 24 * WATCHFACE_GRADIENT_SCLAE;
        float x = width / 2;
        float y = height;

        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgRotate(vg, hour_degree * 2.0f);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -x, -y);

        nvgRoundedRect(vg, 0, 0, width, height, 0);
        nvgFillColor(vg, nvgRGBA(255, 255, 255, 1 * 255));
        nvgFill(vg);
    }
    {
        float r0, r1, ax, ay, bx, by, cx, cy, aeps, r;
        float a0, a1;
        cx = GET_BASE(canvas)->w / 2;
        cy = GET_BASE(canvas)->h / 2;
        r1 = WATCHFACE_GRADIENT_RING2 * WATCHFACE_GRADIENT_SCLAE  / 2.0F;
        r0 = WATCHFACE_GRADIENT_RING3 * WATCHFACE_GRADIENT_SCLAE  / 2.0F;
        a0 = hour_degree * 2.0f - NVG_PI / 2.0f;
        a1 = a0 - NVG_PI / 1.7f;
        nvgResetTransform(vg);
        nvgBeginPath(vg);
        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -(dc->screen_width / 2 - GET_BASE(this)->x),
                     -(dc->screen_height / 2 - GET_BASE(this)->y));
        nvgArc(vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2, r1, a1, a0, NVG_CW);
        nvgArc(vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2, r0, a0, a1, NVG_CCW);
        nvgClosePath(vg);
        ax = cx + cosf(a0) * (r0 + r1) * 0.5f;
        ay = cy + sinf(a0) * (r0 + r1) * 0.5f;
        bx = cx + cosf(a1) * (r0 + r1) * 0.5f;
        by = cy + sinf(a1) * (r0 + r1) * 0.5f;
        NVGpaint paint = nvgLinearGradient(vg, ax, ay, bx, by, nvgRGBA(255, 153, 102, 1 * 255), nvgRGBA(255,
                                           153, 102, 0));
        nvgFillPaint(vg, paint);
        nvgFill(vg);
    }

    {
        //for hour point
        nvgResetTransform(vg);

        nvgBeginPath(vg);

        float width = 15 * WATCHFACE_GRADIENT_SCLAE;
        float height = 73 * WATCHFACE_GRADIENT_SCLAE ;
        float x = width / 2;
        float y = height + (20 + 3) * WATCHFACE_GRADIENT_SCLAE;

        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgRotate(vg, hour_degree * 2.0f);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -x, -y);

        nvgRoundedRect(vg, 0, 0, width, height, width / 2.0f);
        nvgFillColor(vg, nvgRGBA(255, 255, 255, 255));
        nvgFill(vg);
    }
    {
        //for hour point
        nvgResetTransform(vg);

        nvgBeginPath(vg);

        float width = 9 * WATCHFACE_GRADIENT_SCLAE;
        float height = 67 * WATCHFACE_GRADIENT_SCLAE;
        float x = width / 2;
        float y = height + (20 + 3 + 3) * WATCHFACE_GRADIENT_SCLAE;

        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgRotate(vg, hour_degree * 2.0f);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -x, -y);

        nvgRoundedRect(vg, 0, 0, width, height, width / 2.0f);
        nvgFillColor(vg, nvgRGBA(255, 153, 102, 1 * 255));
        nvgFill(vg);
    }



    {
        //for minuts point
        nvgResetTransform(vg);

        nvgBeginPath(vg);

        float width = 5;
        float height = 28;
        float x = width / 2;
        float y = height;

        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgRotate(vg, hour_degree * 10.0F);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -x, -y);

        nvgRoundedRect(vg, 0, 0, width, height, 0);
        nvgFillColor(vg, nvgRGBA(255, 255, 255, 1 * 255));
        nvgFill(vg);
    }
    {
        float r0, r1, ax, ay, bx, by, cx, cy, aeps, r;
        float a0, a1;
        cx = GET_BASE(canvas)->w / 2;
        cy = GET_BASE(canvas)->h / 2;
        r1 = WATCHFACE_GRADIENT_RING1 * WATCHFACE_GRADIENT_SCLAE  / 2;
        r0 = WATCHFACE_GRADIENT_RING2 * WATCHFACE_GRADIENT_SCLAE  / 2.0F;
        a0 = hour_degree * 10.0F - NVG_PI / 2.0f;
        a1 = a0 - NVG_PI / 1.7f;
        nvgResetTransform(vg);
        nvgBeginPath(vg);
        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -(dc->screen_width / 2 - GET_BASE(this)->x),
                     -(dc->screen_height / 2 - GET_BASE(this)->y));
        nvgArc(vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2, r1, a1, a0, NVG_CW);
        nvgArc(vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2, r0, a0, a1, NVG_CCW);
        nvgClosePath(vg);
        ax = cx + cosf(a0) * (r0 + r1) * 0.5f;
        ay = cy + sinf(a0) * (r0 + r1) * 0.5f;
        bx = cx + cosf(a1) * (r0 + r1) * 0.5f;
        by = cy + sinf(a1) * (r0 + r1) * 0.5f;
        NVGpaint paint = nvgLinearGradient(vg, ax, ay, bx, by, nvgRGBA(168, 167, 241, 1 * 255), nvgRGBA(94,
                                           92, 230, 0));
        nvgFillPaint(vg, paint);
        nvgFill(vg);
    }
    {
        //for minuts point
        nvgResetTransform(vg);

        nvgBeginPath(vg);

        float width = 15 * WATCHFACE_GRADIENT_SCLAE;
        float height = 123 * WATCHFACE_GRADIENT_SCLAE;
        float x = width / 2;
        float y = height + (20 + 5) * WATCHFACE_GRADIENT_SCLAE;

        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgRotate(vg, hour_degree * 10.0F);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -x, -y);

        nvgRoundedRect(vg, 0, 0, width, height, width / 2.0f);
        nvgFillColor(vg, nvgRGBA(255, 255, 255, 255));
        nvgFill(vg);
    }
    {
        //for minuts point
        nvgResetTransform(vg);

        nvgBeginPath(vg);

        float width = 9 * WATCHFACE_GRADIENT_SCLAE;
        float height = 116 * WATCHFACE_GRADIENT_SCLAE;
        float x = width / 2;
        float y = height + (20 + 5 + 3) * WATCHFACE_GRADIENT_SCLAE;

        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgRotate(vg, hour_degree * 10.0F);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -x, -y);

        nvgRoundedRect(vg, 0, 0, width, height, width / 2.0f);
        nvgFillColor(vg, nvgRGBA(94, 92, 230, 1 * 255));
        nvgFill(vg);
    }
    {
        //for sceond point
        float r0, r1, ax, ay, bx, by, cx, cy, aeps, r;
        float a0, a1;
        cx = GET_BASE(canvas)->w / 2;
        cy = GET_BASE(canvas)->h / 2;
        r1 = GET_BASE(canvas)->h / 2;
        r0 = 2 / 2.0F;
        a0 = hour_degree * 60.0f - NVG_PI / 2.0f;
        a1 = a0 - NVG_PI / 1.7f;
        nvgResetTransform(vg);
        nvgBeginPath(vg);
        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgRotate(vg, hour_degree * 60.0F);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -(dc->screen_width / 2 - GET_BASE(this)->x),
                     -(dc->screen_height / 2 - GET_BASE(this)->y));
        nvgRect(vg, cx, cy, cx * 2, cy * 1.3f);

        nvgClosePath(vg);
        NVGpaint paint = nvgLinearGradient(vg, cx * 2.0f, cy * 2.5f, cx * 2.0f, cy, nvgRGBA(255, 51, 119,
                                           1 * 255), nvgRGBA(255, 51, 119, 0));
        nvgFillPaint(vg, paint);

        nvgFill(vg);
    }
    {
        //for sceond point
        nvgResetTransform(vg);
        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -(dc->screen_width / 2 - GET_BASE(this)->x),
                     -(dc->screen_height / 2 - GET_BASE(this)->y));
        nvgBeginPath(vg);
        nvgCircle(vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2, 15.0f / 2.0f);
        nvgFillColor(vg, nvgRGBA(255, 255, 255, 1 * 255));
        nvgFill(vg);
    }
    {
        //for sceond point
        nvgResetTransform(vg);
        nvgTranslate(vg, GET_BASE(this)->dx, GET_BASE(this)->dy);
        nvgTranslate(vg, GET_BASE(this)->tx, GET_BASE(this)->ty);
        nvgTranslate(vg, GET_BASE(this)->ax, GET_BASE(this)->ay);
        nvgTranslate(vg, dc->screen_width / 2 - GET_BASE(this)->x,
                     dc->screen_height / 2 - GET_BASE(this)->y);
        nvgScale(vg, this->base.sx, this->base.sy);
        nvgTranslate(vg, -(dc->screen_width / 2 - GET_BASE(this)->x),
                     -(dc->screen_height / 2 - GET_BASE(this)->y));
        nvgBeginPath(vg);
        nvgCircle(vg, GET_BASE(canvas)->w / 2, GET_BASE(canvas)->h / 2, 7.0f / 2.0f);
        nvgFillColor(vg, nvgRGBA(0, 0, 0, 1 * 255));
        nvgFill(vg);
    }

}
static void watchface_gradient_ctor(gui_watchface_gradient_t *this, gui_obj_t *parent,
                                    const char *name,
                                    int16_t x,
                                    int16_t y, int16_t w, int16_t h)
{
    extern void widget_nanovg_ctor(gui_canvas_t *this, gui_obj_t *parent, const char *name,
                                   void *data,
                                   int16_t x,
                                   int16_t y, int16_t w, int16_t h);
    widget_nanovg_ctor((gui_canvas_t *)this, parent, name, NULL, x, y, w, h);
    gui_canvas_set_canvas_cb((gui_canvas_t *)this, canvas_design);
}



gui_watchface_gradient_t *gui_watchface_gradient_create(void *parent,  const char *name,
                                                        int16_t x, int16_t y, int16_t w, int16_t h)
{
    GUI_ASSERT(parent != NULL);
    if (name == NULL)
    {
        name = "watchface_gradient";
    }
    gui_watchface_gradient_t *this = gui_malloc(sizeof(gui_watchface_gradient_t));
    GUI_ASSERT(this != NULL);
    memset(this, 0x00, sizeof(gui_watchface_gradient_t));

    watchface_gradient_ctor(this, (gui_obj_t *)parent, name, x, y, w, h);

    gui_list_init(&(GET_BASE(this)->child_list));
    if ((GET_BASE(this)->parent) != NULL)
    {
        gui_list_insert_before(&((GET_BASE(this)->parent)->child_list),
                               &(GET_BASE(this)->brother_list));
    }

    GET_BASE(this)->create_done = true;
    return this;
}


