#if defined _WIN32
extern unsigned char resource_root[1024 * 1024 * 20];

#define   ACTIVITY_BIN                            (void *)(resource_root + 0x000005b8)
#define   BLOODOXYGEN_BIN                         (void *)(resource_root + 0x000a15f8)
#define   CLOCKN_BIN                              (void *)(resource_root + 0x00142638)
#define   CONTROLMENU_0_BIN                       (void *)(resource_root + 0x001e3678)
#define   CONTROLMENU_1_BIN                       (void *)(resource_root + 0x002846b8)
#define   DINCOND_MEDIUM_SIZE32_BITS8_FONT_BIN    (void *)(resource_root + 0x003256f8)
#define   HEARTRATE_BIN                           (void *)(resource_root + 0x0039d8b8)
#define   MESSAGE_BIN                             (void *)(resource_root + 0x0043e8f8)
#define   MUSIC_BIN                               (void *)(resource_root + 0x004df938)
#define   QUICKCARD_BIN                           (void *)(resource_root + 0x00580978)
#define   SLEEPN_BIN                              (void *)(resource_root + 0x006219b8)
#define   STRESS_BIN                              (void *)(resource_root + 0x006c29f8)
#define   WEATHER_BIN                             (void *)(resource_root + 0x00763a38)
#define   ALARM_CLOCK_OFF_BIN                     (void *)(resource_root + 0x00804a78)
#define   ALARM_CLOCK_ON_BIN                      (void *)(resource_root + 0x00814d78)
#define   BACKGROUND_BIN                          (void *)(resource_root + 0x00825078)
#define   BEIJIN_BIN                              (void *)(resource_root + 0x008c60b8)
#define   BRIGHT_OFF_BIN                          (void *)(resource_root + 0x008d8078)
#define   BRIGHT_ON_BIN                           (void *)(resource_root + 0x008e8378)
#define   C1_BIN                                  (void *)(resource_root + 0x008f8678)
#define   C2_BIN                                  (void *)(resource_root + 0x009186b8)
#define   C3_BIN                                  (void *)(resource_root + 0x009386f8)
#define   C4_BIN                                  (void *)(resource_root + 0x00958738)
#define   C5_BIN                                  (void *)(resource_root + 0x00978778)
#define   C6_BIN                                  (void *)(resource_root + 0x009987b8)
#define   CALL_OFF_BIN                            (void *)(resource_root + 0x009b87f8)
#define   CALL_ON_BIN                             (void *)(resource_root + 0x009c8af8)
#define   DIANHUAGUAN_BIN                         (void *)(resource_root + 0x009d8df8)
#define   DIANHUAKAI_BIN                          (void *)(resource_root + 0x009eadb8)
#define   FLASHLIGHT_OFF_BIN                      (void *)(resource_root + 0x009fcd78)
#define   FLASHLIGHT_ON_BIN                       (void *)(resource_root + 0x00a0d078)
#define   JINGYINGUAN_BIN                         (void *)(resource_root + 0x00a1d378)
#define   JINGYINKAI_BIN                          (void *)(resource_root + 0x00a2f338)
#define   JUYUANMOSHIGUAN_BIN                     (void *)(resource_root + 0x00a412f8)
#define   JUYUANMOSHIKAI_BIN                      (void *)(resource_root + 0x00a532b8)
#define   LIANGDUGUAN_BIN                         (void *)(resource_root + 0x00a65278)
#define   LIANGDUKAI_BIN                          (void *)(resource_root + 0x00a77238)
#define   LINGSHENGGUAN_BIN                       (void *)(resource_root + 0x00a891f8)
#define   LINGSHENGKAI_BIN                        (void *)(resource_root + 0x00a9b1b8)
#define   MUTE_OFF_BIN                            (void *)(resource_root + 0x00aad178)
#define   MUTE_ON_BIN                             (void *)(resource_root + 0x00abd478)
#define   NAOZHONGGUAN_BIN                        (void *)(resource_root + 0x00acd778)
#define   NAOZHONGKAI_BIN                         (void *)(resource_root + 0x00adf738)
#define   NO_DISTURB_OFF_BIN                      (void *)(resource_root + 0x00af16f8)
#define   NO_DISTURB_ON_BIN                       (void *)(resource_root + 0x00b019f8)
#define   R1_BIN                                  (void *)(resource_root + 0x00b11cf8)
#define   R10_BIN                                 (void *)(resource_root + 0x00b12e38)
#define   R11_BIN                                 (void *)(resource_root + 0x00b13f78)
#define   R12_BIN                                 (void *)(resource_root + 0x00b150b8)
#define   R13_BIN                                 (void *)(resource_root + 0x00b161f8)
#define   R14_BIN                                 (void *)(resource_root + 0x00b17338)
#define   R15_BIN                                 (void *)(resource_root + 0x00b18478)
#define   R16_BIN                                 (void *)(resource_root + 0x00b195b8)
#define   R17_BIN                                 (void *)(resource_root + 0x00b1a6f8)
#define   R18_BIN                                 (void *)(resource_root + 0x00b1b838)
#define   R19_BIN                                 (void *)(resource_root + 0x00b1c978)
#define   R2_BIN                                  (void *)(resource_root + 0x00b1dab8)
#define   R20_BIN                                 (void *)(resource_root + 0x00b1ebf8)
#define   R3_BIN                                  (void *)(resource_root + 0x00b1fd38)
#define   R4_BIN                                  (void *)(resource_root + 0x00b20e78)
#define   R5_BIN                                  (void *)(resource_root + 0x00b21fb8)
#define   R6_BIN                                  (void *)(resource_root + 0x00b230f8)
#define   R7_BIN                                  (void *)(resource_root + 0x00b24238)
#define   R8_BIN                                  (void *)(resource_root + 0x00b25378)
#define   R9_BIN                                  (void *)(resource_root + 0x00b264b8)
#define   RING_OFF_BIN                            (void *)(resource_root + 0x00b275f8)
#define   RING_ON_BIN                             (void *)(resource_root + 0x00b378f8)
#define   SET_OFF_BIN                             (void *)(resource_root + 0x00b47bf8)
#define   SET_ON_BIN                              (void *)(resource_root + 0x00b57ef8)
#define   SHEZHIGUAN_BIN                          (void *)(resource_root + 0x00b681f8)
#define   SHEZHIKAI_BIN                           (void *)(resource_root + 0x00b7a1b8)
#define   SHIZHONGGUAN_BIN                        (void *)(resource_root + 0x00b8c178)
#define   SHIZHONGKAI_BIN                         (void *)(resource_root + 0x00b9e138)
#define   SHOUDIANTONGGUAN_BIN                    (void *)(resource_root + 0x00bb00f8)
#define   SHOUDIANTONGKAI_BIN                     (void *)(resource_root + 0x00bc20b8)
#define   SIGNAL_OFF_BIN                          (void *)(resource_root + 0x00bd4078)
#define   SIGNAL_ON_BIN                           (void *)(resource_root + 0x00be4378)
#define   THEATRE_OFF_BIN                         (void *)(resource_root + 0x00bf4678)
#define   THEATRE_ON_BIN                          (void *)(resource_root + 0x00c04978)
#define   VIBRATE_OFF_BIN                         (void *)(resource_root + 0x00c14c78)
#define   VIBRATE_ON_BIN                          (void *)(resource_root + 0x00c24f78)
#define   WATCH_OFF_BIN                           (void *)(resource_root + 0x00c35278)
#define   WATCH_ON_BIN                            (void *)(resource_root + 0x00c45578)
#define   WURAOGUAN_BIN                           (void *)(resource_root + 0x00c55878)
#define   WURAOKAI_BIN                            (void *)(resource_root + 0x00c67838)
#define   XINHAOGUAN_BIN                          (void *)(resource_root + 0x00c797f8)
#define   XINHAOKAI_BIN                           (void *)(resource_root + 0x00c8b7b8)
#define   ZHENDONGGUAN_BIN                        (void *)(resource_root + 0x00c9d778)
#define   ZHENDONGKAI_BIN                         (void *)(resource_root + 0x00caf738)

#else
#define   ACTIVITY_BIN                            (void *)(0x044005b8)
#define   BLOODOXYGEN_BIN                         (void *)(0x044a15f8)
#define   CLOCKN_BIN                              (void *)(0x04542638)
#define   CONTROLMENU_0_BIN                       (void *)(0x045e3678)
#define   CONTROLMENU_1_BIN                       (void *)(0x046846b8)
#define   DINCOND_MEDIUM_SIZE32_BITS8_FONT_BIN    (void *)(0x047256f8)
#define   HEARTRATE_BIN                           (void *)(0x0479d8b8)
#define   MESSAGE_BIN                             (void *)(0x0483e8f8)
#define   MUSIC_BIN                               (void *)(0x048df938)
#define   QUICKCARD_BIN                           (void *)(0x04980978)
#define   SLEEPN_BIN                              (void *)(0x04a219b8)
#define   STRESS_BIN                              (void *)(0x04ac29f8)
#define   WEATHER_BIN                             (void *)(0x04b63a38)
#define   ALARM_CLOCK_OFF_BIN                     (void *)(0x04c04a78)
#define   ALARM_CLOCK_ON_BIN                      (void *)(0x04c14d78)
#define   BACKGROUND_BIN                          (void *)(0x04c25078)
#define   BEIJIN_BIN                              (void *)(0x04cc60b8)
#define   BRIGHT_OFF_BIN                          (void *)(0x04cd8078)
#define   BRIGHT_ON_BIN                           (void *)(0x04ce8378)
#define   C1_BIN                                  (void *)(0x04cf8678)
#define   C2_BIN                                  (void *)(0x04d186b8)
#define   C3_BIN                                  (void *)(0x04d386f8)
#define   C4_BIN                                  (void *)(0x04d58738)
#define   C5_BIN                                  (void *)(0x04d78778)
#define   C6_BIN                                  (void *)(0x04d987b8)
#define   CALL_OFF_BIN                            (void *)(0x04db87f8)
#define   CALL_ON_BIN                             (void *)(0x04dc8af8)
#define   DIANHUAGUAN_BIN                         (void *)(0x04dd8df8)
#define   DIANHUAKAI_BIN                          (void *)(0x04deadb8)
#define   FLASHLIGHT_OFF_BIN                      (void *)(0x04dfcd78)
#define   FLASHLIGHT_ON_BIN                       (void *)(0x04e0d078)
#define   JINGYINGUAN_BIN                         (void *)(0x04e1d378)
#define   JINGYINKAI_BIN                          (void *)(0x04e2f338)
#define   JUYUANMOSHIGUAN_BIN                     (void *)(0x04e412f8)
#define   JUYUANMOSHIKAI_BIN                      (void *)(0x04e532b8)
#define   LIANGDUGUAN_BIN                         (void *)(0x04e65278)
#define   LIANGDUKAI_BIN                          (void *)(0x04e77238)
#define   LINGSHENGGUAN_BIN                       (void *)(0x04e891f8)
#define   LINGSHENGKAI_BIN                        (void *)(0x04e9b1b8)
#define   MUTE_OFF_BIN                            (void *)(0x04ead178)
#define   MUTE_ON_BIN                             (void *)(0x04ebd478)
#define   NAOZHONGGUAN_BIN                        (void *)(0x04ecd778)
#define   NAOZHONGKAI_BIN                         (void *)(0x04edf738)
#define   NO_DISTURB_OFF_BIN                      (void *)(0x04ef16f8)
#define   NO_DISTURB_ON_BIN                       (void *)(0x04f019f8)
#define   R1_BIN                                  (void *)(0x04f11cf8)
#define   R10_BIN                                 (void *)(0x04f12e38)
#define   R11_BIN                                 (void *)(0x04f13f78)
#define   R12_BIN                                 (void *)(0x04f150b8)
#define   R13_BIN                                 (void *)(0x04f161f8)
#define   R14_BIN                                 (void *)(0x04f17338)
#define   R15_BIN                                 (void *)(0x04f18478)
#define   R16_BIN                                 (void *)(0x04f195b8)
#define   R17_BIN                                 (void *)(0x04f1a6f8)
#define   R18_BIN                                 (void *)(0x04f1b838)
#define   R19_BIN                                 (void *)(0x04f1c978)
#define   R2_BIN                                  (void *)(0x04f1dab8)
#define   R20_BIN                                 (void *)(0x04f1ebf8)
#define   R3_BIN                                  (void *)(0x04f1fd38)
#define   R4_BIN                                  (void *)(0x04f20e78)
#define   R5_BIN                                  (void *)(0x04f21fb8)
#define   R6_BIN                                  (void *)(0x04f230f8)
#define   R7_BIN                                  (void *)(0x04f24238)
#define   R8_BIN                                  (void *)(0x04f25378)
#define   R9_BIN                                  (void *)(0x04f264b8)
#define   RING_OFF_BIN                            (void *)(0x04f275f8)
#define   RING_ON_BIN                             (void *)(0x04f378f8)
#define   SET_OFF_BIN                             (void *)(0x04f47bf8)
#define   SET_ON_BIN                              (void *)(0x04f57ef8)
#define   SHEZHIGUAN_BIN                          (void *)(0x04f681f8)
#define   SHEZHIKAI_BIN                           (void *)(0x04f7a1b8)
#define   SHIZHONGGUAN_BIN                        (void *)(0x04f8c178)
#define   SHIZHONGKAI_BIN                         (void *)(0x04f9e138)
#define   SHOUDIANTONGGUAN_BIN                    (void *)(0x04fb00f8)
#define   SHOUDIANTONGKAI_BIN                     (void *)(0x04fc20b8)
#define   SIGNAL_OFF_BIN                          (void *)(0x04fd4078)
#define   SIGNAL_ON_BIN                           (void *)(0x04fe4378)
#define   THEATRE_OFF_BIN                         (void *)(0x04ff4678)
#define   THEATRE_ON_BIN                          (void *)(0x05004978)
#define   VIBRATE_OFF_BIN                         (void *)(0x05014c78)
#define   VIBRATE_ON_BIN                          (void *)(0x05024f78)
#define   WATCH_OFF_BIN                           (void *)(0x05035278)
#define   WATCH_ON_BIN                            (void *)(0x05045578)
#define   WURAOGUAN_BIN                           (void *)(0x05055878)
#define   WURAOKAI_BIN                            (void *)(0x05067838)
#define   XINHAOGUAN_BIN                          (void *)(0x050797f8)
#define   XINHAOKAI_BIN                           (void *)(0x0508b7b8)
#define   ZHENDONGGUAN_BIN                        (void *)(0x0509d778)
#define   ZHENDONGKAI_BIN                         (void *)(0x050af738)

#endif