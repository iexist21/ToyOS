#include "print.h"
#include "keyboard.h"
#include "ports.h"
#include <stdbool.h>
bool Edit_mode = false;
char keyboard_current_char;
char keyb_buffer[4000];
void kernel_main() {
    con_clear();
    print("Press T to test the console, and C to clear the Screen.\nF1 for text mode, and F2 for command mode\n");
        while (true) { // Kernel loop
            keyboard_current_char = getc();
            if (keyboard_current_char==0x01) {
                Edit_mode = true;
            } 
            if (keyboard_current_char == 0x02){
                Edit_mode = false;
            }
            if (!Edit_mode){
            if (keyboard_current_char == 'C') {
                con_clear();
            } 
            if (keyboard_current_char == 'T') {
                print("|    |\n|    |\n|    |\n|    |");
            }
            if (keyboard_current_char == 'Q') {
                gets();
                print(keyb_buffer);
                clear_kbuf();
            }
            }
            if (Edit_mode && keyboard_current_char != 0x02 && keyboard_current_char != 0x01 && keyboard_current_char != -1 && keyboard_current_char != -2){
            print_c(keyboard_current_char);
            }
            while (keyboard_current_char == getc()){__asm__("nop");}
        }
    }