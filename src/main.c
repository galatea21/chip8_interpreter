#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include "chip8.h"

int main()
{
    CHIP8 *cpu = CHIP8_new();

    printf("%d", cpu->v[5]);

    return 0;
}