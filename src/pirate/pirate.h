
#define BP_VER 5

#define HW_PINS 10

// Buffer Direction Defines
#define BUFDIR0 0
#define BUFDIR1 1
#define BUFDIR2 2
#define BUFDIR3 3
#define BUFDIR4 4
#define BUFDIR5 5 
#define BUFDIR6 6
#define BUFDIR7 7

// Buffer IO defines
#define BUFIO0 8
#define BUFIO1 9
#define BUFIO2 10
#define BUFIO3 11
#define BUFIO4 12
#define BUFIO5 13
#define BUFIO6 14
#define BUFIO7 15  

#define BP_SPI_START_SPEED 1000 * 1000
#define BP_SPI_HIGH_SPEED 1000 * 1000 * 16
#define BP_SPI_SHIFT_SPEED 1000 * 1000 * 16

// BP5 REV 10
// SPI Defines
// We are going to use SPI 0 for on-board peripherals
#define BP_SPI_PORT spi0
#define BP_SPI_CDI 16
#define BP_SPI_CLK  18
#define BP_SPI_CDO 19

// NAND flash is on the BP_SPI_PORT, define Chip Select
#define FLASH_STORAGE_CS 26 

// LCD is on the BP_SPI_PORT, define CS and DP pins
#define DISPLAY_CS 25
#define DISPLAY_DP 24

// Two 74HC595 shift registers are on BP_SPI_PORT, define latch and enable pins
#define SHIFT_EN 21
#define SHIFT_LATCH 20

// Controller data out to SK6812 RGB LEDs
#define RGB_CDO 17
// The number of SK6812 LEDs in the string
#define RGB_LEN 18 

//PWM based PSU control pins
#define PSU_PWM_CURRENT_ADJ 22 //3A
#define PSU_PWM_VREG_ADJ 23 //3B

// A single ADC pin is used to measure the source selected by a 74hct4067
#define AMUX_OUT 28
#define AMUX_OUT_ADC (AMUX_OUT - 26)

// Current sense ADC
#define CURRENT_SENSE 29
#define CURRENT_SENSE_ADC (CURRENT_SENSE - 26)

// Two pins for front buttons
#define EXT1 27

// The two 75hc595 shift registers control various hardware on the board
#define AMUX_EN             (1u<<0)
#define AMUX_S0             (1u<<1)
#define AMUX_S1             (1u<<2)
#define AMUX_S2             (1u<<3)
#define AMUX_S3             (1u<<4)
#define DISPLAY_BACKLIGHT   (1u<<5)
#define DISPLAY_RESET       (1u<<6)
#define PULLUP_EN           (1u<<7)
//#define                   (1u<<8) 
#define CURRENT_EN          (1u<<9)
//#define                   (1u<<10)
#define CURRENT_RESET       (1u<<11)
//#define DAC_CS              (1u<<12)
#define CURRENT_EN_OVERRIDE (1u<<13)
//#define                   (1u<<14)
//#define                   (1u<<15)

//how many 595 shift registers are connected
#define SHIFT_REG_COUNT 2

// LCD size
#define BP_LCD_WIDTH 240
#define BP_LCD_HEIGHT 320

// LCD color pallet 5-6-5 RGB
#define BP_LCD_COLOR_RED    0b1111100000000000
#define BP_LCD_COLOR_ORANGE 0b1111100000000000
#define BP_LCD_COLOR_YELLOW 0b1111100000000000
#define BP_LCD_COLOR_GREEN  0b0000011111100000
#define BP_LCD_COLOR_BLUE   0b0000000000011111
#define BP_LCD_COLOR_PURPLE 0b1111100000011111
#define BP_LCD_COLOR_BROWN  0b1111100000011111
#define BP_LCD_COLOR_GREY   0b1111111111111111
#define BP_LCD_COLOR_WHITE  0b1111111111111111
#define BP_LCD_COLOR_BLACK  0b0000000000000000

void pirate_init(void);
