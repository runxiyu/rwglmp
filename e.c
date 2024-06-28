#include "lib/monocypher.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int a()
{
	// These keys are taken from https://datatracker.ietf.org/doc/html/rfc7748#section-6.1
	uint8_t priv1[32] = { 0x77, 0x07, 0x6d, 0x0a, 0x73, 0x18, 0xa5, 0x7d, 0x3c, 0x16, 0xc1, 0x72, 0x51, 0xb2, 0x66, 0x45, 0xdf, 0x4c, 0x2f, 0x87, 0xeb, 0xc0, 0x99, 0x2a, 0xb1, 0x77, 0xfb, 0xa5, 0x1d, 0xb9, 0x2c, 0x2a };
	uint8_t pub1[32];
	uint8_t priv2[32] = { 0x5d, 0xab, 0x08, 0x7e, 0x62, 0x4a, 0x8a, 0x4b, 0x79, 0xe1, 0x7f, 0x8b, 0x83, 0x80, 0x0e, 0xe6, 0x6f, 0x3b, 0xb1, 0x29, 0x26, 0x18, 0xb6, 0xfd, 0x1c, 0x2f, 0x8b, 0x27, 0xff, 0x88, 0xe0, 0xeb };
	uint8_t pub2[32];
	uint8_t shared1[32];
	uint8_t shared2[32];
	crypto_x25519_public_key(pub1, priv1);
	crypto_x25519_public_key(pub2, priv2);
	crypto_x25519(shared1, priv1, pub2);
	crypto_x25519(shared2, priv2, pub1);
	write(1, shared1, 32);
	write(1, shared2, 32);
	return 0;
}

int b()
{
	// These keys are taken from https://datatracker.ietf.org/doc/html/rfc7748#section-6.1
	// Alright I admit to using a hexeditor to edit C code, aint that fun?
	uint8_t haha[192] = "wm\ns¥}<ÁrQ²fEßL/‡ëÀ™*±wû¥¹,*]«~bJŠKyá‹ƒ€æo;±)&¶ý/‹'ÿˆàë";
	crypto_x25519_public_key(haha + 64, haha);
	crypto_x25519_public_key(haha + 96, haha + 32);
	crypto_x25519(haha + 128, haha, haha+96);
	crypto_x25519(haha + 160, haha+32, haha+64);
	write(1, haha+128, 32);
	write(1, haha+160, 32);
	return 0;
}

int main()
{
	b();
	return 0;
}
