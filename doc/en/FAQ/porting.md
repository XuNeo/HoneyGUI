# Porting

## User Data

User Data bin image generation need to consider user data address in flash_map.h. Normally the address in generate script is consistent with user data address in flash_map.h,
and if user data bin need to add image data header due to mppgtool requirement, the generate script address must increase by image data header size.

## JS Malloc Heap

JS(javascript) is include in GUI module, the heap space JS used maybe malloc failed by resource limition, so this heap space could relocate on psram if SoC support psram feture, the specific
infomation could see api `void *context_alloc(size_t size, void *cb_data_p)`.

## Feed Watch Dog

GUI task not support feed watch dog, so app should do this in hook function registered by APP and used by GUI. The registered function is `void gui_task_ext_execution_sethook(void (*hook)(void))`.

## Not Support FPU

If SoC not support FPU, some header and code should not include by macro, example as RTL8763EP.

## File System

SoC need to read image and font resource from flash by file system which should set a start address that is consistent with address in User Data generation script, GUI has supplied the related file which is 'romfs.c' where the start address is `ROMFS_ADDR`.

## Flash Setting

Flash speed mode should set to 4 bit mode; flash clock should set to a higher value based on chip capabilities.

## CPU Frequence

CPU frequence should set to a higher value based on chip capabilities.

## SCONS Version

Specific scons version is required, please use the `pip install scons==4.4.0` command to download.
