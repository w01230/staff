/**
 * test purpose only
 *
 *
 * 2017/07/06 J.W@Shanghai
 */
#include <stdlib.h>
#include <stdio.h>

static inline unsigned char rotate_left(unsigned char data, unsigned char bits)
{
	return data << bits | data >> (sizeof(data) * 8 - bits);
}

static inline unsigned char rotate_right(unsigned char data, unsigned char bits)
{
	return data >> bits | data << (sizeof(data) * 8 - bits);
}

static unsigned char swap_8bits(unsigned char data)
{
	unsigned char swap = data;

	swap = (swap >> 4 & 0x0F) | (swap << 4 & 0xF0);
	swap = (swap >> 2 & 0x33) | (swap << 2 & 0xCC);
	swap = (swap >> 1 & 0x55) | (swap << 1 & 0xAA);

	return swap;
}

int main(int argc, char *argv[])
{
	unsigned char data = 0x78;

	printf("data:%X swap:%X\n", data, swap_8bits(data));

	return 0;
}
