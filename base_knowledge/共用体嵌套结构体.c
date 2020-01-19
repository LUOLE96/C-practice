#include <stdio.h>
#include <stdint.h>

union //共用体嵌套结构体
{
    struct
    {
        uint16_t i;
        uint16_t j;
    }x;
    uint32_t y;
    
}a;


int main(void)
{
    a.y = 0x11223344;

    printf("%x\n",a.x.i + a.x.j);

    return 0;
}