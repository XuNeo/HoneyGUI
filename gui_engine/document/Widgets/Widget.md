|Widget  | Brief  |
|--|--|
|screen  |The root widget of the widget tree|
|window  |A rectangular container widget|
|tab  |Commonly used widget for watches, the card is extended from the screen in the cross direction, switch the currently displayed card by sliding|
|curtain  |Drag and drop from all sides of the screen to cover the current screen|
|page |Larger than the screen size, you can drag and drop to browse|
|iconlist   |A page with vertical icons|
|icon  |A button which can listen to click events|
|image  |Display a picture, you can do transformation, support multiple color formats|
|textbox  |Show some text|
|progressbar  |Show progress|
|seekbar  |Draggable progress bar|
|switch  |Click to toggle switch state, listen to open and close events|
|canvas  |Draw circles, rectangles, rounded rectangles, and more|
|......  |


## 5.1 screen
* The screen widget is the root node of a control tree. The screen coordinate system is set as follows. The origin of the polar coordinates is the negative direction of the Y axis, and the positive direction of the polar coordinates is clockwise.：
![输入图片说明](https://foruda.gitee.com/images/1669963637201743951/88578c71_10088396.jpeg "1229.jpg")


## 5.2 window
* The api for creating win is as follows

```
/**
 * @brief create a window widget.
 * @param parent the father widget the window nested in.
 * @param filename the window widget name.
 * @param x the X-axis coordinate.
 * @param y the Y-axis coordinate.
 * @param w the width.
 * @param h the hight.
 * @return return the widget object pointer
 *
 */
gui_win_t *gui_win_create(void *parent, const char *filename, int16_t x, int16_t y,
                          int16_t w, int16_t h);
```




* The demo code is  to create a window as follows.


```
gui_win_t *win = gui_win_create(screen, "win", 0, 0, 320, 320);

```







## 5.3 tabview & tab
* The tabview and tab widgets can achieve the effect of sliding and switching multiple pages. Each tab is used as a page, nested in the parent control tabview, extending from the screen in the cross direction.
![输入图片说明](https://foruda.gitee.com/images/1661827539206769834/cab110df_11406702.png "微信图片_20220830104519.png")

* The api for creating tabview & tab is as follows

```
/**
 * @brief create a tabview widget,which can nest tabs.
 * @param parent the father widget it nested in.
 * @param filename this tabview widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the width of the widget.
 * @param h the hight of the widget.
 * @return return the widget object pointer.
 *
 */
gui_tabview_t *gui_tabview_create(void *parent, const char *filename, int16_t x, int16_t y,
                                  int16_t w, int16_t h);

/**
 * @brief create a tab widget,which should be nested in a tabview.
 * @param parent the father widget it nested in.
 * @param filename this tab widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the width of the widget.
 * @param h the hight of the widget.
 * @param idx the X-axis index in a tabview.
 * @param idy the Y-axis index in a tabview.
 * @return return the widget object pointer.
 *
 */
gui_tab_t *gui_tab_create(void *parent, const char *filename, int16_t x, int16_t y,
                          int16_t w, int16_t h, int16_t idx, int16_t idy);
```



* The demo code is to create tabview and tab as follows.


```
gui_tabview_t *app_dialing_window = gui_tabview_create(screen, "dialing_win", 0, 0, 0, 0);

gui_tab_create(app_dialing_window, "tab0", 0, 0, 0, 0, 0, 0);
```



## 5.4 curtain_view & curtain
* The curtain_view and curtain widgets can realize the effect of dragging the curtains around to the middle. Each curtain is nested in the parent widget curtain_view.



* `float scope`This parameter indicates the percentage that the curtain can be dragged out.


![输入图片说明](https://foruda.gitee.com/images/1661827875719370154/dfe05236_11406702.png "微信图片_20220830105041.png")

* The api for creating curtain_view & curtain is as follows.


```
/**
 * @brief create a curtainview widget,which can nest curtains.
 * @param parent the father widget it nested in.
 * @param filename this curtainview widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the width of the widget.
 * @param h the hight of the widget.
 * @param scope the scope of every curtain.
 * @return return the widget object pointer.
 *
 */
gui_curtainview_t *gui_curtainview_create(void *parent, const char *filename, int16_t x,
                                          int16_t y,
                                          int16_t w, int16_t h);

/**
 * @brief create a curtain widget,which should be nested in a curtainview.
 * @param parent the father widget nested in.
 * @param filename this curtain widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the width of the widget.
 * @param h the hight of the widget.
 * @param orientation the orientation of the curtain,using gui_curtain_enum_t range.
 * @return return the widget object pointer.
 *
 */
gui_curtain_t *gui_curtain_create(void *parent, const char *filename, int16_t x, int16_t y,
                                  int16_t w, int16_t h, gui_curtain_enum_t orientation, float scope);
```


* The demo code is to create curtain_view and curtain as follows.

```
gui_curtainview_t *curtainview = gui_curtainview_create(screen, "curtainview", 0, 0, 0,
			0, 0.5);

gui_curtain_t *curtain_left = gui_curtain_create(curtainview, "curtain_left", 0, 0, 0, 0, LEFT,0.5);
```






## 5.5 page

* The api for creating page is as follows.

```
/**
 * @brief create a page widget.
 * @param parent the father widget the pagedow nested in.
 * @param filename the pagedow widget name.
 * @param x the X-axis coordinate.
 * @param y the Y-axis coordinate.
 * @param w the width.
 * @param h the hight.
 * @return return the widget object pointer
 *
 */
gui_page_t *gui_page_create(void *parent, const char *filename, int16_t x, int16_t y,
                          int16_t w, int16_t h);
```


* The demo code is to create page as follows.


```
gui_page_t *page1 = gui_page_create（screen,"gui_page1", 10, 10, 20, 20）;
```





## 5.6 iconlist & icon
* The combination of iconlist and icon widgets can realize the effect of sliding browsing of icon list。Each icon is nested in the parent iconlist。In addition, the icon widget can be used independently without depending on the iconlist. You can set the event callback for the icon control.




   - `int16_t id`This input parameter, incremented from 0, is the order of the icon's position in the iconlist.
   - The area of ​​the icon determines the response range triggered by the callback。When the icon is nested in the parent  iconlist，`int16_t x, int16_t y` is automatically generated and arranged.Otherwise，`int16_t x, int16_t y` need to set manually。

![输入图片说明](https://foruda.gitee.com/images/1661828274419437196/4a8306d8_11406702.png "微信图片_20220830105745.png")


* The api for creating iconlist & icon is as follows.

```
/**
 * @brief create a iconlist widget,which can nest icons.
 * @param parent the father widget nested in.
 * @param filename this iconlist widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the width of the widget.
 * @param h the hight of the widget.
 * @return return the widget object pointer.
 *
 */
gui_iconlist_t *gui_iconlist_create(void *parent, const char *filename, int16_t x, int16_t y,
                                    int16_t w, int16_t h, uint16_t *config, uint8_t count);

/**
 * @brief create a icon widget,which can nest images,texts,and so on.
 * @note icon widgets can be nested in a icon list widget or not.if nested in a icon list,the idx and idy parameters will be used.
 * @param parent the father widget nested in.
 * @param filename this iconlist widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the width of the widget.
 * @param h the hight of the widget.
 * @param id the index in a icon list.
 * @return return the widget object pointer.
 *
 */
gui_icon_t *gui_icon_create(void *parent, const char *filename, int16_t x, int16_t y,
                            int16_t w, int16_t h, int16_t id);
```






* The demo code is as follows.


```
gui_iconlist_t *menu = gui_iconlist_create(screen, "menu", 0, 0, app->win_width,
                                               app->win_height, NULL, NULL);

gui_icon_t *icon1 = gui_icon_create(menu, "icon1", 0, 0, 320, 65, 0);

```










## 5.7 image
* The image control can display pictures at specified positions, and has matrix operation mechanisms such as scaling and rotation,and setting transparency。




*The api for creating an image is as follows. There are two creation modes, file system mode and memory address mode.。The input parameter `const char *filename` in the file system mode is the absolute path of the image file。The input parameter `void *addr` of the memory address mode is the starting address of the picture data。

```
/**
* @brief create a image widget in file system mode,without using gpu.
* @param parent the father widget which the image nested in.
* @param filename the image flie name
* @param x the X-axis coordinate of the image
* @param y the Y-axis coordinate of the image
* @param w the width of the image
* @param h the hight of the image
* @return return the widget object pointer
*
*/
gui_obj_t *gui_img_create(gui_obj_t *parent, const char *filename, int16_t x, int16_t y,
                          int16_t w, int16_t h);

/**
* @brief create a image widget in from memory mode,without using gpu.
* @param parent the father widget which the image nested in.
* @param filename the image flie name
* @param x the X-axis coordinate of the picture
* @param y the Y-axis coordinate of the picture
* @param w the width of the picture
* @param h the hight of the picture
* @return return the widget object pointer
*
*/
gui_img_t *gui_img_create_from_mem(gui_obj_t *parent, void *addr, int16_t x, int16_t y,
                                  int16_t w, int16_t h);

/**
 * @brief set x,y and file path
 *
 * @param img image widget
 * @param filename change filename if using filesystem picture
 * @param addr change picture address
 * @param x X-axis coordinate
 * @param y Y-axis coordinate
 */
void gui_img_set_attribute(gui_img_t *img, const char *filename, void *addr, int16_t x,
                           int16_t y);

/**
 * @brief load the image to read it's width
 *
 * @param img the image widget pointer.
 * @return uint16_t image's width
 */
uint16_t gui_img_get_width(gui_img_t *img);

/**
 * @brief load the image to read it's hight
 *
 * @param img the image widget pointer.
 * @return uint16_t image's height
 */
uint16_t gui_img_get_height(gui_img_t *img);

/**
 * @brief set the image's location
 *
 * @param img the image widget pointer.
 * @param x the x coordinate
 * @param y the y coordinate
 */
void gui_img_set_location(gui_img_t *img, uint16_t x, uint16_t y);

/**
 * @brief set the image's mode.
 *
 * @param img the image widget pointer.
 * @param mode the enumeration value of the mode is IMAGE_MODE.
 * @return void
 *
 */
void gui_img_set_mode(gui_img_t *img, BLEND_MODE_TYPE mode);
```


* The demo code is as follows.

```
  gui_img_t *image_fs = gui_img_create(screen, "/clock/clock.bin", 0, 0, 0, 0);
  gui_img_t *image_from_mem = gui_img_create_from_mem(screen, "name", (void *)0xB30000, 10, 10, 0, 0);
  gui_img_set_attribute(image_from_mem, "name", (void *)0xB30000, 100, 20);
```



## 5.8 textbox

* The api for creating an textbox is as follows
```
/**
 * @brief create a text box widget.
 * @note the area of the text box should be larger than that of the string to be shown.
 * @param parent the father widget which the text nested in.
 * @param filename the widget's name.
 * @param x the X-axis coordinate of the text box.
 * @param x the Y-axis coordinate of the text box.
 * @param w the width of the text box.
 * @param h the hight of the text box.
 * @return return the widget object pointer
 *
 */
gui_text_t *gui_text_create(void *parent, const char *filename, int16_t x, int16_t y,
                            int16_t w, int16_t h);
```
* The apis for set properties of this widget are as follows.
```
/**
* @brief set the string in a text box widget.
* @note the area of the text box should be larger than that of the string to be shown.
* @param this the text box widget pointer.
* @param text the text string.
* @param font_type the font's name.
* @param color the text's color.
* @param length the text string's length.
* @param font_size the text string's font size.
* @return void
*/
void gui_text_set(gui_text_t *this, const char *text, char *text_type, uint32_t color,
                  uint16_t length, uint8_t font_size);
/**
 * @brief set text mode of this text widget
 * @note if text line count was more than one, it will display on the left even if it was set lft or right
 * @param this the text widget pointer.
 * @param mode there was three mode: LEFT, CENTER and RIGHT.
 */
void gui_text_mode_set(gui_text_t *this, TEXT_MODE mode);
/**
 * @brief set font size or width and height
 * @note if use freetype, width and height is effective, else height will be applied as font size
 * @param this the text box widget pointer.
 * @param height font height or font size.
 * @param width font width(only be effective when freetype was used).
 */
void gui_text_size_set(gui_text_t *this, uint8_t height, uint8_t width);
```

* The demo code is as follows.

```
  gui_text_t *text = gui_text_create(&app->screen, "text", 0, 30, 320, 100);
  gui_text_set(text, "Text to display", "rtk_font_mem32", 0xffffffff, strlen("Text to display"), 24);
  gui_text_mode_set(text, CENTER);

  static char str_test[] = "000\n111\n222\n333\n444";
  gui_text_t *text = gui_text_create(&app->screen,  "text",  0, 200, 320, 100);
  gui_text_set(text, str_test, "rtk_font_mem32", 0x80808080, sizeof(str_test)-1, 32);
  gui_text_mode_set(text, MUTI_LEFT);
```



## 5.9 scroll textbox
If you want to use the scroll text box, you must add gui_text.c before.
* The api for creating an scroll textbox is as follows
```
/**
 * @brief Creat a scroll text widget.
 * @note Scroll text widget can show horizontal and vertical scroll text.
 * @note If the width of the text is less than the width of the text box, the text will stand still.
 * @note Scroll and text properties need to be set by gui_scrolltext_scroll_set and gui_scrolltext_text_set.
 * @param parent The father widget which the scroll text nested in.
 * @param name The widget's name.
 * @param x The X-axis coordinate of the text box.
 * @param x The Y-axis coordinate of the text box.
 * @param w The width of the text box.
 * @param h The hight of the text box.
 * @return Return the widget object pointer: gui_scroll_text_t*
 */
gui_scroll_text_t *gui_scrolltextbox_create(void *parent, const char *name, int16_t x,
                                            int16_t y, int16_t w, int16_t h);
```

* The apis for set scroll and text properties of this widget are as follows.
```
/**
 * @brief Set the text scroll property of the scroll text box.
 *
 * @param this the scroll text widget pointer.
 * @param mode the mode of this scroll text widget, SCROLL_X or SCROLL_Y.
 * @param start_value the number of pixels to the left of the text in the first frame
 * @param end_value the number of pixels to the right of the text at the last frame.
 * @param interval_time_ms the time for one loop.
 * @param duration_time_ms the total time that text scrolling lasts.
 */
void gui_scrolltext_scroll_set(gui_scroll_text_t *this, TEXT_MODE mode, uint8_t start_value,
                               uint8_t end_value,
                               uint32_t interval_time_ms, uint32_t duration_time_ms);
/**
* @brief set the string in a scroll text box widget.
* @note
* @param this the scroll text box widget pointer.
* @param text the scroll text string.
* @param font_type the font's name.
* @param color the text's color.
* @param length the text string's length.
* @param font_size the text string's font size.
* @return void
*/
void gui_scrolltext_text_set(gui_scroll_text_t *this, const char *text, char *text_type,
                             uint32_t color,
                             uint16_t length, uint8_t font_size);
```
* The demo code is as follows.
```
    gui_scroll_text_t *scroll_text = gui_scrolltext_create(&app->screen,  "scroll_text", 100, 60, 120, 30);
    gui_scrolltext_scroll_set(scroll_text, SCROLL_X, 100, 0, 3000, 1500000);
    gui_scrolltext_text_set(scroll_text, "gui_scroll_text_t", "rtk_font_mem", 0xffffffff, strlen("gui_scroll_text_t"), 24);

    static char str_test[] = "000\n111\n222\n333\n444";
    gui_scroll_text_t *scroll_text = gui_scrolltext_create(&app->screen,  "scroll_text",  0, 100, 320, 64);
    gui_scrolltext_scroll_set(scroll_text, SCROLL_Y, 32, 32, 10000, 150000);
    gui_scrolltext_text_set(scroll_text, str_test, "rtk_font_mem", 0xffffffff, sizeof(str_test) - 1, 32);
```






## 5.9 canvas



The api for creating an canvas is as follows
```
/**
 * @brief create a canvas widget.
 * @param parent the father widget it nested in.
 * @param name this canvas widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the width of the widget.
 * @param h the hight of the widget.
 * @param color the color of the widget.
 * @return return the widget object pointer.
 */
gui_canvas_t *gui_canvas_create(void *parent, const char *name, int16_t x, int16_t y,int16_t w, int16_t h, uint32_t color);

/**
 * @brief create a rectangle widget.
 * @param parent the father widget it nested in.
 * @param name this rectangle widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the width of the widget.
 * @param h the hight of the widget.
 * @param color the color of the widget.
 * @return return the widget object pointer.
 */
gui_rectangle_t *gui_rectangle_create(void *parent, const char *name, int16_t x, int16_t y,
                                      int16_t w, int16_t h, uint32_t color);

/**
 * @brief create a circle widget.
 * @param parent the father widget it nested in.
 * @param name this circle widget's name.
 * @param center_x the center X-axis coordinate of the widget.
 * @param center_y the center Y-axis coordinate of the widget.
 * @param radius the radius of the widget.
 * @param color the hight of the widget.
 * @return return the widget object pointer.
 */
gui_circle_t *gui_circle_create(void *parent, const char *name, int16_t center_x, int16_t center_y,
                                uint16_t radius, uint32_t color);

/**
 * @brief create a round rectangle widget.
 * @param parent the father widget it nested in.
 * @param name this round rectangle widget's name.
 * @param x the X-axis coordinate of the widget.
 * @param y the Y-axis coordinate of the widget.
 * @param w the hight of the widget.
 * @param h the hight of the widget.
 * @param color the color of the widget.
 * @return return the widget object pointer.
 */
gui_round_rect_t *gui_round_rect_create(void *parent, const char *name, int16_t x, int16_t y,
                                      int16_t w, int16_t h, uint32_t color);



```


* The demo code is as follows.

```
gui_canvas_t *c1 = gui_canvas_create(screen, "1", 0, 0, 320, 85, 0x00CDCDFF);
c1->draw_round_rect(c1, 0, 0, 85, 85);
c1->draw_circle(c1, 100,100,50);

gui_rectangle_create(screen, "gui_rectangle", 0,0,100, 100, 0xff00ffff);

gui_circle_create(screen, "gui_circle", 20,20, 20, 0xffff00ff);

```














































































