#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <nanovg.h>
#include <trace.h>
#include "vg_lite.h"

#define NANOVG_VGLITE_DEBUG
#ifdef NANOVG_VGLITE_DEBUG

#define NANOVG_LOG(format, ...) DBG_DIRECT(format, ##__VA_ARGS__)

#else

#define NANOVG_LOG(format, ...)

#endif

static int vglite_nvg_renderCreate(void *uptr)
{
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    NVG_NOTUSED(uptr);
    NANOVG_LOG(" uptr = 0x%x\n", uptr);
    return 1;
}
static int vglite_nvg_renderCreateTexture(void *uptr, int type, int w, int h, int imageFlags,
                                          const unsigned char *data)
{
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    NANOVG_LOG(" uptr = 0x%x, type = %d, w = %d, h = %d, imageFlags = %d, data = 0x%x\n", uptr, type, w,
               h, imageFlags, data);
    return 0;
}
static int vglite_nvg_renderDeleteTexture(void *uptr, int image)
{
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    NANOVG_LOG(" uptr = 0x%x, image = %d\n", uptr, image);
    return 0;
}
static int vglite_nvg_renderUpdateTexture(void *uptr, int image, int x, int y, int w, int h,
                                          const unsigned char *data)
{
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    NANOVG_LOG(" uptr = 0x%x, image = %d, x = %d, y = %d, w = %d, h = %d, data = 0x%x\n", uptr, image,
               x, y, w, h, data);
    return 0;
}
static void vglite_nvg_renderViewport(void *uptr, float width, float height, float devicePixelRatio)
{
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    NANOVG_LOG(" uptr = 0x%x, width = %f, height = %f, devicePixelRatio = %f\n", uptr, width, height,
               devicePixelRatio);
    NVG_NOTUSED(uptr);
    NVG_NOTUSED(width);
    NVG_NOTUSED(height);
    NVG_NOTUSED(devicePixelRatio);
}
static int vglite_nvg_renderGetTextureSize(void *uptr, int image, int *w, int *h)
{
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    NANOVG_LOG(" uptr = 0x%x, image = %d, w = 0x%x, h = 0x%x\n", uptr, image, w, h);
    return 0;
}
static void vglite_nvg_renderCancel(void *uptr)
{
    NVG_NOTUSED(uptr);
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    NANOVG_LOG(" uptr = 0x%x\n", uptr);
}

static void vglite_nvg_renderFlush(void *uptr)
{
    NVG_NOTUSED(uptr);
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    NANOVG_LOG(" uptr = 0x%x\n", uptr);

    vg_lite_finish();
}
static void vglite_nvg_renderDelete(void *uptr)
{
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
}

void vglite_nvg_renderStroke(void *uptr, NVGpaint *paint,
                             NVGcompositeOperationState compositeOperation,
                             NVGscissor *scissor, float fringe, float strokeWidth, const NVGpath *paths,
                             int npaths)
{
    NANOVG_LOG(" %s %d\n", __func__, __LINE__);
    vg_lite_buffer_t *target = (vg_lite_buffer_t *)uptr;

#define PATH_CMD_LEN 512
    static uint8_t path_cmd[PATH_CMD_LEN];
    static vg_lite_float_t path_data[PATH_CMD_LEN];
    uint32_t cmd_cnt = 0;
    uint32_t data_cnt = 0;

    for (int i = 0; i < npaths; i++)
    {
        const NVGpath *p = paths + i;
        for (int j = 0; j < p->nstroke; j++)
        {
            const NVGvertex *v = p->stroke + j;
            if (j == 0)
            {
                path_cmd[cmd_cnt++] = VLC_OP_MOVE;
                path_data[data_cnt++] = v->x;
                path_data[data_cnt++] = v->y;
            }
            else
            {
                path_cmd[cmd_cnt++] = VLC_OP_LINE;
                path_data[data_cnt++] = v->x;
                path_data[data_cnt++] = v->y;
            }
        }
        path_cmd[cmd_cnt++] = VLC_OP_END;
    }


    vg_lite_path_t path;
    memset(&path, 0, sizeof(vg_lite_path_t));
    uint32_t path_data_len = vg_lite_path_calc_length(path_cmd, sizeof(path_cmd), VG_LITE_FP32);
    vg_lite_init_path(&path, VG_LITE_FP32, VG_LITE_HIGH, path_data_len, NULL, 0, 0, 0, 0);
    vg_lite_path_append(&path, path_cmd, path_data, cmd_cnt);
    vg_lite_matrix_t matrix;
    vg_lite_identity(&matrix);

    vg_lite_set_stroke(&path, VG_LITE_CAP_ROUND, VG_LITE_JOIN_ROUND, strokeWidth, 60, NULL, 0, 0,
                       0xFF00FF00);
    vg_lite_update_stroke(&path);
    vg_lite_set_draw_path_type(&path, VG_LITE_DRAW_STROKE_PATH);
    vg_lite_draw(target, &path, VG_LITE_FILL_NON_ZERO, &matrix, VG_LITE_BLEND_NONE, 0xFF00FF00);
    vg_lite_finish();
    vg_lite_clear_path(&path);



}
void vglite_nvg_renderFill(void *uptr, NVGpaint *paint,
                           NVGcompositeOperationState compositeOperation,
                           NVGscissor *scissor, float fringe, const float *bounds, const NVGpath *paths,
                           int npaths)
{
    vg_lite_buffer_t *target = (vg_lite_buffer_t *)uptr;


#define PATH_CMD_LEN 512
    static uint8_t path_cmd[PATH_CMD_LEN];
    static vg_lite_float_t path_data[PATH_CMD_LEN];
    uint32_t cmd_cnt = 0;
    uint32_t data_cnt = 0;

    for (int i = 0; i < npaths; i++)
    {
        const NVGpath *p = paths + i;
        for (int j = 0; j < p->nfill; j++)
        {
            const NVGvertex *v = p->fill + j;
            if (j == 0)
            {
                path_cmd[cmd_cnt++] = VLC_OP_MOVE;
                path_data[data_cnt++] = v->x;
                path_data[data_cnt++] = v->y;
            }
            else
            {
                path_cmd[cmd_cnt++] = VLC_OP_LINE;
                path_data[data_cnt++] = v->x;
                path_data[data_cnt++] = v->y;
            }
        }
        path_cmd[cmd_cnt++] = VLC_OP_END;
    }

    vg_lite_path_t path;
    memset(&path, 0, sizeof(vg_lite_path_t));
    uint32_t path_data_len = vg_lite_path_calc_length(path_cmd, sizeof(path_cmd), VG_LITE_FP32);
    vg_lite_init_path(&path, VG_LITE_FP32, VG_LITE_HIGH, path_data_len, NULL, 0, 0, 0, 0);
    vg_lite_path_append(&path, path_cmd, path_data, cmd_cnt);
    vg_lite_matrix_t matrix;
    vg_lite_identity(&matrix);

    vg_lite_draw(target, &path, VG_LITE_FILL_NON_ZERO, &matrix, VG_LITE_BLEND_NONE, 0xFF00FF00);
    vg_lite_finish();
    vg_lite_clear_path(&path);
}


NVGcontext *nvgCreateAGGE(uint32_t w, uint32_t h, uint32_t stride, enum NVGtexture format,
                          uint8_t *data)
{
    NVGparams params;
    NVGcontext *ctx = NULL;
    //AGGENVGcontext* agge = new AGGENVGcontext();
    static vg_lite_buffer_t target;
    memset(&target, 0x00, sizeof(vg_lite_buffer_t));
    target.width  = w;
    target.height = h;
    target.format = VG_LITE_RGBA8888;
    target.memory = (void *)data;
    target.address = (uint32_t)data;
    target.stride = target.width * 4;

    //if (agge == NULL) goto error;

    memset(&params, 0, sizeof(params));
    params.renderCreate = vglite_nvg_renderCreate;
    params.renderCreateTexture = vglite_nvg_renderCreateTexture;
    params.renderDeleteTexture = vglite_nvg_renderDeleteTexture;
    params.renderUpdateTexture = vglite_nvg_renderUpdateTexture;
    params.renderGetTextureSize = vglite_nvg_renderGetTextureSize;
    params.renderViewport = vglite_nvg_renderViewport;
    params.renderCancel = vglite_nvg_renderCancel;
    params.renderFlush = vglite_nvg_renderFlush;
    params.renderDelete = vglite_nvg_renderDelete;
    params.renderTriangles = NULL;
    params.renderStroke = vglite_nvg_renderStroke;
    params.renderFill = vglite_nvg_renderFill;
    params.userPtr = (void *)&target;
    params.edgeAntiAlias = 1;

    //nvgInitAGGE(agge, &params, w, h, stride, format, data);


    //vg_lite_clear(&target, NULL, 0xFFFFAAAA);
    //vg_lite_finish();

    ctx = nvgCreateInternal(&params);
    if (ctx == NULL) { goto error; }

    return ctx;

error:
    if (ctx != NULL) { nvgDeleteInternal(ctx); }
    return NULL;
}

void nvgDeleteAGGE(NVGcontext *ctx)
{
    nvgDeleteInternal(ctx);
}