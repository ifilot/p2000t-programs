#include <stdint.h>

// forward declaration
extern void clearscreen(void);
void print_digit(uint8_t val);
void init(void);

// start of video
__at (0x5000) char vidmem[];
uint8_t row = 2;
uint8_t column = 0;

#define N (22 * 40)                 // number of digits
#define LEN (10L * N) / 3 + 10      // memory buffer

void main(void) {
    init();

    uint8_t predigit = 0;
    uint8_t nines = 0;
    uint8_t a[LEN];

    uint16_t x, q, k, i;

    for(uint16_t j=N; j; )  {
        q = 0;
        k = LEN+LEN-1;

        for(i=LEN; i; --i)  {
            x = (j == N ? 20 : 10L*a[i-1]) + q*i;
            q = x / k;
            a[i-1] = (unsigned)(x-q*k);
            k -= 2;
        }

        k = x % 10;

        if (k==9) {
          ++nines;  
        } else {
            if (j) {
                --j;
                print_digit(predigit+x/10);
            }

            for(; nines; --nines) {
                if (j) {
                  --j;
                  print_digit(x >= 10 ? 0 : 9);
                } 
            }

            predigit = (uint8_t)k;
        }
    }
}

/**
 * @brief      Put some information on the screen
 */
void init(void) {
    // clear the screen
    clearscreen();

    vidmem[0] = 0x06;    // cyan color
    vidmem[1] = 0x0D;    // double height
    char str[] = "Calculating digits of PI...";
    for(uint8_t i=0; i<27; i++) {
        vidmem[i+2] = str[i];
    }
}

/**
 * @brief      Print a digit to the screen
 *
 * @param[in]  Digit to print
 */
void print_digit(uint8_t val) {
    vidmem[row * 0x50 + column] = val + 0x30;

    column++;
    if(column == 40) {
        column = 0;
        row++;
    }
}