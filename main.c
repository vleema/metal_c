#include "helper.h"
#include <stdint.h>

uint32_t root[1024]
    __attribute__((aligned(4096))) = {0x83, 0x83};

int global = 10;

int main() 
{
  puts("\nOlá mundo!\n");

  int* ptr1 = &global;
  int* ptr2 = (int*)((char*)&global + 4096 * 1024);

  set_cr3((uint32_t)&root[0]);
  set_cr4(get_cr4() | (1 << 4));
  set_cr0(get_cr0() | (1 << 31));

  *ptr2 = 20;

  puts("Paginação Habilitada!\n");
  puts("Valor de ptr1: ");
  put_hex(*ptr1);
  puts("\nValor de ptr2: ");
  put_hex(*ptr2);
  puts("\n");

  for (;;);
}
