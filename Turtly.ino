// Turtly Firmware for the M5 Stack Stick C Plus
// github.com/higorjardini - Fork from  

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
  "@unagironin",
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

#if defined(LANGUAGE_EN_US)
  #define TXT_BACK "Back"
  #define TXT_CLOCK "Clock"
  #define TXT_SETTINGS "Settings"
  #define TXT_NEVER "Never"
  #define TXT_SEC "seconds"
  #define TXT_MIN	"minutes"
  #define TXT_AUTO_DIM "SET AUTO DIM TIME"
  #define TXT_SET_BRIGHT "SET BRIGHTNESS"
  #define TXT_BATT_INFO "Battery Info"
  #define TXT_BRIGHT "Brightness"
  #define TXT_SET_CLOCK "Set Clock"
  #define TXT_ROTATION "Rotation"
  #define TXT_ABOUT "About"
  #define TXT_REBOOT "Reboot"
  #define TXT_CLR_SETTINGS "Clear Settings"
  #define TXT_CLRING_SETTINGS "Restoring Default\nSettings..."
  #define TXT_RIGHT "Right"
  #define TXT_LEFT "Left"
  #define TXT_BATT "Battery: "
  #define TXT_EXIT "Press any key to exit"
  #define TXT_RG_AMERICAS "Region:\nAmericas / Asia\n"
  #define TXT_RG_EMEA "Region: EMEA"
  #define TXT_SEL_GO_PAUSE "Select: Go/Pause"
  #define TXT_SEL_EXIT "Next: Exit"
  #define TXT_TRIG_TV "triggered TVBG"
  #define TXT_MN_AMERICA "Americas / Asia"
  #define TXT_MN_EMEA "EU/MidEast/Africa"
  #define TXT_REGION "Region"
  #define TXT_FK_GP "Front Key: Go/Pause"
  #define TXT_SET_HOUR "SET HOUR"
  #define TXT_SET_MIN "SET MINUTE"
  #define TXT_ADV "Advertising:\n"  
  #define TXT_SP_RND "Swift Pair Random"
  #define TXT_SEL_EXIT2 "\n\nNext: Exit"
  #define TXT_BT_SPAM "BT Spam"
  #define TXT_SA_CRASH "SourApple Crash"
  #define TXT_CMB_BT_SPAM " Combined BT Spam"
  #define TXT_AD_SPAM "Android Spam"
  #define TXT_AJ_TRANSF_NM "Transfer Number"
  #define TXT_AJ_TV_COLOR "TV Color Balance"
  #define TXT_STP_NW_PH "Setup New Phone"
  #define TXT_SA_ADV "SourApple Advertisement: "
  #define TXT_SP_ADV "SwiftPair Advertisement: '%s' - "
  #define TXT_AD_SPAM_ADV "Android Spam Advertisement: "
  #define TXT_AJ_ADV "AppleJuice Advertisement: "
  #define TXT_WF_SP "WiFi Spam"
  #define TXT_RND_SSID " - Random SSIDs\n"
  #define TXT_WF_SCAN "Scan Wifi"
  #define TXT_WF_SPAM_FUN "Spam Funny"
  #define TXT_WF_SPAM_RR "Spam Rickroll"
  #define TXT_WF_SPAM_RND "Spam Random"
  #define TXT_WF_RESCAN "[RESCAN]"
  #define TXT_WF_OPEN "Open"
  #define TXT_WF_CHANN "Chan : %d\n"
  #define TXT_WF_CRYPT "Crypt: %s\n"
  #define TXT_SEL_BACK "\nNext: Back\n"
  #define TXT_HOLD_CLONE "Hold Select: Clone\n"
  #define TXT_WF_SCN "WiFi Scan"
  #define TXT_WF_SCNING "Scanning..."
  #define TXT_INST_NXT "Next: Down Arrow"
  #define TXT_INST_PRV "Prev: Up Arrow"
  #define TXT_INST_SEL "Sel : Enter or ->"
  #define TXT_INST_HOME "Home: Esc   or <- "
  #define TXT_INST_PRSS_KEY "         Press a key"
  #define TXT_STK_NXT "Next: Side Button"
  #define TXT_STK_SEL "Sel : M5 Button"
  #define TXT_STK_HOME "Home: Power Button"
  #define TXT_SDCARD "Mount/Unmount SD"
  #define TXT_DEAUTH_START "Select>Start DEAUTH\n"
  #define TXT_DEAUTH_STOP "Select>Stop DEAUTH \n"
  #define TXT_HOLD_ATTACK "Hold Select: Attack\n"
  #define TXT_WFA_PORTAL "Clone Portal"
  #define TXT_WFA_DEAUTH "Deauth attack"
  #define TXT_WFA_COMBINED "Deauth+Clone"
  #define TXT_BLACK "Black"
  #define TXT_NAVY "Navy"
  #define TXT_DARKGREEN "Dark Green"
  #define TXT_DARKCYAN "Dark Cyan"
  #define TXT_MAROON "Maroon"
  #define TXT_PURPLE "Purple"
  #define TXT_OLIVE "Olive"
  #define TXT_LIGHTGREY "Light Grey"
  #define TXT_DARKGREY "Dark Grey"
  #define TXT_BLUE "Blue"
  #define TXT_GREEN "Green"
  #define TXT_CYAN "Cyan"
  #define TXT_RED "Red"
  #define TXT_MAGENTA "Magenta"
  #define TXT_YELLOW "Yellow"
  #define TXT_WHITE "White"
  #define TXT_ORANGE "Orange"
  #define TXT_GREENYELLOW "Green Yellow"
  #define TXT_PINK "Pink"
  #define TXT_COLOR "Custom Colors"
  #define TXT_SET_FGCOLOR "MAIN COLOR"
  #define TXT_SET_BGCOLOR "BACKGROUND COLOR"
  #define TXT_THEME "Color Theme"
  #define TXT_EVIL_TOOLS "Evil Tools"
  #define TXT_UTILITIES "Utilities"
  #define TXT_POWER_OFF "Power Off"
#endif

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
  }
}