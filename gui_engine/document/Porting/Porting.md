    The porting files are in the sdk\src\app\wristband\gui_port folder.
    There are four files that need to be modified, corresponding to the input device, display device, OS, and file system.
    At present, it has been transplanted in FreeRtos, rt-thread, and Windows, you can refer to it.
### 6.1 the input device
- ``sdk\src\app\wristband\gui_port\gui_port_indev.c``
- The input information is abstracted as touch screen contacts, and the input information structure is as follows
```
typedef struct gui_touch_data
{
    uint8_t          event;                 /* The touch event of the data */
    uint8_t          track_id;              /* Track id of point */
    uint16_t         width;                 /* Point of width */
    uint16_t         x_coordinate;          /* Point of x coordinate */
    uint16_t         y_coordinate;          /* Point of y coordinate */
    uint32_t         timestamp;             /* The timestamp when the data was received */
    void            *data;
} gui_touch_data_t;
```
### 6.2 the display device
- ``sdk\src\app\wristband\gui_port\gui_port_dc.c``
- It is necessary to define the screen width and height, frame buffer address and mode, whether the resolution is scaled, and realize the refresh function. The structure is as follows
```
static struct gui_dispdev dc =
{
    .bit_depth = DRV_PIXEL_BITS,
    .fb_width = DRV_LCD_WIDTH,
    .fb_height = DRV_LCD_HIGHT,
    .screen_width =  DRV_LCD_WIDTH,
    .screen_height = DRV_LCD_HIGHT,
    .driver_ic_fps = 60,
    .driver_ic_hfp = 10,
    .driver_ic_hbp = 10,
    .driver_ic_active_width = DRV_LCD_WIDTH,
    .type = DC_RAMLESS,
    .adaption = false,
    .section = {0, 0, 0, 0},
    .section_count = 0,
    .lcd_update = port_gui_lcd_update,
    .flash_seq_trans_disable = flash_boost_disable,
    .flash_seq_trans_enable = flash_boost_enable,
    .reset_lcd_timer = reset_vendor_counter,
    .get_lcd_us = read_vendor_counter_no_display,
    .lcd_te_wait = port_lcd_te_wait,
    .gpu_type = GPU_SW,
};
```
### 6.3 the file system
- ``sdk\src\app\wristband\gui_port\gui_port_filesystem.c``
- Need to define several posix-style interface operation files and folders, as follows.
```
struct gui_fs
{
    int (*open)(const char *file, int flags, ...);
    int (*close)(int d);
    int (*read)(int fd, void *buf, size_t len);
    int (*write)(int fd, const void *buf, size_t len);
    int (*lseek)(int fd, int offset, int whence);
    /* directory api*/
    gui_fs_DIR *(*opendir)(const char *name);
    struct gui_fs_dirent *(*readdir)(gui_fs_DIR *d);
    int (*closedir)(gui_fs_DIR *d);
};
```
### 6.4 the os
- ``sdk\src\app\wristband\gui_port\gui_port_os.c``
- Need to define interfaces for threads and memory management, as follows
```
struct gui_os_api
{
    char *name;
    void *(*thread_create)(const char *name, void (*entry)(void *param), void *param,
                           uint32_t stack_size, uint8_t priority);
    bool (*thread_delete)(void *handle);
    bool (*thread_mdelay)(uint32_t ms);


    void *(*f_malloc)(uint32_t);
    void *(*f_realloc)(void *ptr, uint32_t);
    void (*f_free)(void *rmem);
    void *mem_addr;
    uint32_t mem_size;
    log_func_t log;
};
```














