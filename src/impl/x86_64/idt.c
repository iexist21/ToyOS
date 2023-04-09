#include "idt.h"
#include <stdint.h>

#define KERNEL_CS 0x08

void set_idt_gate(int n, uint32_t handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].sel = 0x08;
    idt[n].always0 = 0;
    idt[n].flags = KERNEL_CS; 
    idt[n].high_offset = high_16(handler);
}

void set_idt() {
    idt_reg.base = (uint32_t) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    /* Don't make the mistake of loading &idt -- always load &idt_reg */
    asm volatile("lidtq (%0)" : : "r" (&idt_reg));
}