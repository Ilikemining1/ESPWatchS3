#include "Arduino.h"

#include "lvgl.h"
#include "TFT_eSPI.h"
#include "SparkFunBQ27441.h"
#include "Wire.h"

#include "ui.h"

// Define battery parameters
#define BATTERY_CAPACITY 290
#define TERMINATION_VOLTAGE 2600
#define TAPER_CURRENT 14

#define ONE_MINUTE_MS (60 * 1000)
#define ONE_HOUR_MS (60 * 60 * 1000)
#define TWELVE_HOUR_MS (12 * 60 * 60 * 1000)

static uint32_t ms_offset;

static uint8_t power_off = 0;

static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight);

// Write pixel data to display
void disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *) &color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

// Read encoder keys
void encoder_keys_read(lv_indev_drv_t *drv, lv_indev_data_t *data) {

}

void set_power_down(void) {
  power_off = 1;
}

void setup() {

    pinMode(8, OUTPUT); // Configure charger strapping pins
    pinMode(9, OUTPUT);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);

    pinMode(4, INPUT); // Configure button pins as input, set up power button interrupt.
    pinMode(5, INPUT); 
    pinMode(6, INPUT);
    pinMode(7, INPUT);

    ledcSetup(0, 1000, 8); // Configure backlight PWM, 15.6 percent duty cycle
    ledcAttachPin(41, 0);
    ledcWrite(0, 40);

    Wire.begin(1, 2);

    Serial.begin(115200);
    Serial.println("ESPWatchS3 Firmware V0.1");

    if(!lipo.begin()) { // Set up communication with fuel gauge
      Serial.println("Failed to communicate with BQ27441 fuel gauge");
      Serial.println("Please check connections!");
      while(1);
    }

    if(lipo.itporFlag()) { // Check if fuel gauge needs to be reprogrammed. If not, don't to avoid losing battery data.
      Serial.println("Programming fuel gauge settings");

      lipo.enterConfig();

      lipo.setCapacity(BATTERY_CAPACITY);
      lipo.setDesignEnergy(BATTERY_CAPACITY * 3.7f);
      lipo.setTerminateVoltage(TERMINATION_VOLTAGE);
      lipo.setTaperRate(10 * BATTERY_CAPACITY / TAPER_CURRENT);

      lipo.exitConfig();

      Serial.println("Fuel gauge programmed!");

    } else {
      Serial.println("Using existing fuel gauge programming");
    }

    lv_init();  // Initialize LVGL and display
    tft.begin();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

    static lv_disp_drv_t disp_drv; // Display driver setup
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = encoder_keys_read;
    lv_indev_drv_register(&indev_drv);

    ms_offset = 0;

    ui_init();

    attachInterrupt(4, set_power_down, RISING);
}

void loop() {
  lv_timer_handler();
  unsigned long ms = millis();

  unsigned long clock_ms = (ms_offset + ms) % TWELVE_HOUR_MS;
  uint8_t hour = clock_ms / ONE_HOUR_MS;
  uint8_t minute = (clock_ms % ONE_HOUR_MS) / ONE_MINUTE_MS;
  int16_t angle = (clock_ms % ONE_MINUTE_MS) * 3600 / ONE_MINUTE_MS;
  lv_img_set_angle(ui_SecondHand, angle);
  angle = (angle + (minute * 3600)) / 60;
  lv_img_set_angle(ui_MinuteHand, angle);
  angle = (angle + (hour * 3600)) / 12;
  lv_img_set_angle(ui_HourHand, angle);

  lv_label_set_text_fmt(ui_SystemStats, "%u / %u mAh %i mW %u mV", lipo.capacity(REMAIN), lipo.capacity(FULL), lipo.power(), lipo.voltage());

  if (lipo.power() > 0) {
    lv_obj_set_style_bg_color(ui_ChargingIndicator, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
  } else {
    lv_obj_set_style_bg_color(ui_ChargingIndicator, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  if (power_off) {
    Serial.println("Powering down!");
    power_off = 0;
    pinMode(48, OUTPUT);
    digitalWrite(48, LOW);
  }
}
