#include <stdint.h>

void invlpg(void *addr);

void puts(const char *s);
void put_hex(uint32_t v);

void set_cr4(uint32_t value);
uint32_t get_cr4(void);

void set_cr3(uint32_t value);
uint32_t get_cr3(void);

void set_cr0(uint32_t value);
uint32_t get_cr0(void);
