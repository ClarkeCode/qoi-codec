#ifndef QOI_CC_H
#define QOI_CC_H
#include "stdint.h"

struct qoi_header {
	char magic[4];
	uint32_t width;
	uint32_t height;
	uint8_t channels;
	uint8_t colorspace;
}

struct pixel {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
}

#define QOI_OP_RGB 63;
#define QOI_OP_RGBA 64;
#endif

#ifdef QOI_CC_IMPL
uint8_t hash (pixel* px) { 
	return (px.r * 3 + px.g * 5 + px.b * 7 + px.a * 11) % 64; 
}

void* decode(void* info, size_t size) {
	qoi_header header = {0};
	uint8_t* bytes = info;
	for (size_t x = 0; x < 4; x++) {
		header.magic[x] = *bytes;
	}
	header.width  = *(uint32_t*) bytes; bytes += 4;
	header.height = *(uint32_t*) bytes; bytes += 4;
	header.channels = *bytes++;
	header.colorspace = *bytes++;
}
#endif








