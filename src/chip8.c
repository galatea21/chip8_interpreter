#include <stdlib.h>
#include <string.h>
#include "chip8.h"

const u8 font[16][5] = {
    {0xF0, 0x90, 0x90, 0x90, 0xF0}, //  0
    {0x20, 0x60, 0x20, 0x20, 0x70}, //  1
    {0xF0, 0x10, 0xF0, 0x80, 0xF0}, //  2
    {0xF0, 0x10, 0xF0, 0x10, 0xF0}, //  3
    {0x90, 0x90, 0xF0, 0x10, 0x10}, //  4
    {0xF0, 0x80, 0xF0, 0x10, 0xF0}, //  5
    {0xF0, 0x80, 0xF0, 0x90, 0xF0}, //  6
    {0xF0, 0x10, 0x20, 0x40, 0x40}, //  7
    {0xF0, 0x90, 0xF0, 0x90, 0xF0}, //  8
    {0xF0, 0x90, 0xF0, 0x10, 0xF0}, //  9
    {0xF0, 0x90, 0xF0, 0x90, 0x90}, //  A
    {0xE0, 0x90, 0xE0, 0x90, 0xE0}, //  B
    {0xF0, 0x80, 0x80, 0x80, 0xF0}, //  C
    {0xE0, 0x90, 0x90, 0x90, 0xE0}, //  D
    {0xF0, 0x80, 0xF0, 0x80, 0xF0}, //  E
    {0xF0, 0x80, 0xF0, 0x80, 0x80}, //  F
};

CHIP8 *CHIP8_new()
{
    CHIP8 *cpu = calloc(61, sizeof(u8));
    cpu->ram = calloc(4096, sizeof(u8));
    memset(cpu->v, 0, sizeof(cpu->v));
    memset(cpu->stack, 0, sizeof(cpu->stack));
    // TODO: init delay, sound, pc, sp

    // Store built-in font in 0x50 - 0x9F
    for (size_t i = 0; i < 16; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            write_u8(cpu, (u16)(0x50 + i * 5 + j), font[i][j]);
        }
    }

    return cpu;
}

void CHIP8_destroy(CHIP8 *cpu)
{
    free(cpu->ram);
    free(cpu);
}
