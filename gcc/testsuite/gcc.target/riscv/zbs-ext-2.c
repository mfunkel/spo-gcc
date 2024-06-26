/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zbb_zbs -mabi=lp64" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-Og" "-Os" } } */


typedef unsigned int uint32_t;
uint32_t foo(uint32_t pos)
{
    return (1 << (7-(pos) % 8));
}

typedef unsigned int uint32_t;
uint32_t foo2(uint32_t pos)
{
    return (1 << (pos & 0xf));
}

/* { dg-final { scan-assembler-not "sll\t" } } */
/* { dg-final { scan-assembler-times "bset\t" 2 } } */
/* { dg-final { scan-assembler-times "andi\t" 1 } } */
/* { dg-final { scan-assembler-times "andn\t" 1 } } */
/* { dg-final { scan-assembler-times "li\t" 1 } } */
/* { dg-final { scan-assembler-times "ret" 2 } } */

