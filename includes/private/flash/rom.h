#ifndef _ROM_H_
#define _ROM_H_

FILE *romfopen(char *fn, char *mode);
int rom_present(char *fn);

typedef struct rom_t {
        uint8_t *rom;
        uint32_t mask;
        mem_mapping_t mapping;
} rom_t;

int rom_init(rom_t *rom, char *fn, uint32_t address, int size, int mask, int file_offset, uint32_t flags);
int rom_init_interleaved(rom_t *rom, char *fn_low, char *fn_high, uint32_t address, int size, int mask, int file_offset,
                         uint32_t flags);

uint8_t rom_read(uint32_t addr, void *p);
uint16_t rom_readw(uint32_t addr, void *p);
uint32_t rom_readl(uint32_t addr, void *p);

#endif /* _ROM_H_ */
