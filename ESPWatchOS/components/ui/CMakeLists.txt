cmake_minimum_required(VERSION 3.5)
idf_component_register(SRCS "screens/ui_WatchScreen.c"  
                            "ui.c"
                            "ui_helpers.c"
                            "images/ui_img_dial_face_png.c"
                            "images/ui_img_hour_hand_png.c"
                            "images/ui_img_minute_hand_png.c"
                            "images/ui_img_second_hand_png.c"
                    INCLUDE_DIRS "./screens"
                                 "./images"
                                 "."
                    REQUIRES "arduino" # Library requires Arduino
                             "lvgl"
                    )

project(ui)