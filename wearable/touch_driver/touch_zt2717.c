/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2020-08-04     tyustli  first version
 */

#include "wristband_sdk_config.h"

#ifdef BSP_USING_TOUCH
#include "rtl_gpio.h"
#include "rtl_rcc.h"
#include "drv_gpio.h"
#include "drv_i2c.h"
#include "drv_touch.h"
#include "touch_zt2717.h"
#include "string.h"
#include "trace.h"
#include "utils.h"


static void ts_write_cmd(uint16_t cmd)
{
    uint8_t iic_write_buf[2];
    iic_write_buf[0] = cmd & 0xff;
    iic_write_buf[1] = cmd >> 8;

    drv_i2c0_write(TOUCH_ZT2717_ADDR, iic_write_buf, 2);
}

static void ts_write_reg(uint16_t reg, uint16_t data)
{
    uint8_t iic_write_buf[4];
    iic_write_buf[0] = reg & 0xff;
    iic_write_buf[1] = reg >> 8;
    iic_write_buf[2] = data & 0xff;
    iic_write_buf[3] = data >> 8;
    drv_i2c0_write(TOUCH_ZT2717_ADDR, iic_write_buf, 4);
}

static void ts_read_data(uint16_t reg, uint8_t *buf, uint16_t len)
{
    uint8_t iic_write_buf[2];
    iic_write_buf[0] = reg & 0xff;
    iic_write_buf[1] = reg >> 8;
    drv_i2c0_write(TOUCH_ZT2717_ADDR, iic_write_buf, 2);
    platform_delay_us(10);
    drv_i2c0_read(TOUCH_ZT2717_ADDR, buf, len);
}


static struct _ts_zinitix_point_info touch_info;
bool rtk_touch_hal_read_all(uint16_t *x, uint16_t *y, bool *pressing)
{

    ts_read_data(ZINITIX_POINT_STATUS_REG, (uint8_t *)&touch_info, 8);

//    APP_PRINT_INFO4("touch_info.event_flag = 0x%x, touch_info.status = 0x%x, touch_info.coord->x = %d, touch_info.coord->y = %d", \
//                touch_info.event_flag, touch_info.status, touch_info.coord->x, touch_info.coord->y);
    *x = touch_info.coord->x;
    *y = touch_info.coord->y;
    if ((touch_info.coord->x > 280) || (touch_info.coord->x < 0))
    {
        *x = 0;
    }
    if ((touch_info.coord->y > 456) || (touch_info.coord->y < 0))
    {
        *y = 0;
    }
    if (touch_info.status == 0x804 || touch_info.status == 0x803)
    {
        *pressing = true;
    }
    else
    {
        *pressing = false;
    }
    ts_write_cmd(ZINITIX_CLEAR_INT_STATUS_CMD);
    return true;
}



void rtk_touch_hal_init(void)
{
    drv_i2c0_set_scl_sda(TOUCH_ZT2717_SCL, TOUCH_ZT2717_SDA);
    drv_pin_mode(TOUCH_ZT2717_RST, PIN_MODE_OUTPUT);
    drv_pin_write(TOUCH_ZT2717_RST, 1);

    platform_delay_ms(100);
    drv_pin_write(TOUCH_ZT2717_RST, 0);
    platform_delay_ms(100);
    drv_pin_write(TOUCH_ZT2717_RST, 1);



    uint16_t chip_code = 0;
    uint16_t firmware_version = 0;
    uint16_t minor_firmware_version = 0;
    uint16_t reg_data_version = 0;

    ts_write_reg(0xc000, 0x0001);
    platform_delay_us(10);
    ts_read_data(0xcc00, (void *)&chip_code, 2);

    ts_write_cmd(0xc004);
    platform_delay_us(10);
    ts_write_reg(0xc002, 0x0001);
    platform_delay_ms(2);
    ts_write_reg(0xc001, 0x0001);
    platform_delay_ms(100);

    ts_write_cmd(ZINITIX_SWRESET_CMD);

    platform_delay_ms(10);

    ts_read_data(ZINITIX_FIRMWARE_VERSION, (void *)&firmware_version, 2);
    ts_read_data(ZINITIX_MINOR_FW_VERSION, (void *)&minor_firmware_version, 2);
    ts_read_data(ZINITIX_DATA_VERSION_REG, (void *)&reg_data_version, 2);

    DBG_DIRECT("chip_code = 0x%x; firmware_version = %x\r\n", chip_code, firmware_version);
    DBG_DIRECT("minor_firmware_version = 0x%x; reg_data_version = %x\r\n", minor_firmware_version,
               reg_data_version);

    ts_write_reg(ZINITIX_INITIAL_TOUCH_MODE, TOUCH_POINT_MODE);
    ts_write_reg(ZINITIX_TOUCH_MODE, TOUCH_POINT_MODE);
    ts_write_reg(ZINITIX_SUPPORTED_FINGER_NUM, (uint16_t)MAX_SUPPORTED_FINGER_NUM);
    ts_write_reg(ZINITIX_X_RESOLUTION, (uint16_t)(TPD_RES_MAX_X));
    ts_write_reg(ZINITIX_Y_RESOLUTION, (uint16_t)(TPD_RES_MAX_Y));
    ts_write_cmd(ZINITIX_CALIBRATE_CMD);
    for (uint32_t i = 0; i < 10; i++)
    {
        ts_write_cmd(ZINITIX_CLEAR_INT_STATUS_CMD);
        platform_delay_us(10);
    }

}

#endif /* BSP_USING_TOUCH */