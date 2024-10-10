#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print_bar(int size, float progress, int strike_zone) {
    int progress_pos = round(size * progress);  //current progress
    int strike_start = (size - strike_zone) / 2;  //calc start of strike zone
    int strike_end = strike_start + strike_zone;  //calc end of strike zone

    printf("|");  //start

    
    for (int i = 0; i < size; i++) {  // for loop that loops through the length of the bar and puts in strike zone
        if (i == strike_start) {
            printf("[");  
        } else if (i == strike_end - 1) {
            printf("]");  
        } else if (i > strike_start && i < strike_end - 1) {
            if (i < progress_pos) {
                printf("=");  
            } else {
                printf(" ");  
            }
        } else {
            if (i < progress_pos) {
                printf("=");  
            } else {
                printf(" ");  
            }
        }
    }

    printf("|\n");  //end
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <size> <progress> <strike_zone>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    float progress = atof(argv[2]);
    int strike_zone = atoi(argv[3]);

    print_bar(size, progress, strike_zone);
    return 0;
}
