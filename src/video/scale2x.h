/*
 * This file is part of the Scale2x project.
 *
 * Copyright (C) 2001, 2002, 2003, 2004 Andrea Mazzoleni
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __SCALE2X_H
#define __SCALE2X_H

typedef unsigned char scale2x_uint8;
typedef unsigned short scale2x_uint16;
typedef unsigned scale2x_uint32;

/**
 * Enable the SSE2 implementation.
 *
 *      if generating x86_64 code (all 64bits x86 CPUs support SSE2)
 *      if __SSE2__ is defined (-msse2 with GCC)
 *      if _M_IX86_FP == 2 (/arch:SSE2 with MS Visual C++)
 */
#if defined(__x86_64__) || defined(_M_X64) || defined(__SSE2__) || (defined(_M_IX86_FP) && (_M_IX86_FP == 2))
#define USE_SCALE2X_SSE2 1
#endif

/**
 * Enable the MMX implementation
 */
#if !defined(USE_SCALE2X_SSE2)
#if defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))
#define USE_SCALE2X_MMX 1
#endif
#endif

void scale2x_8_def(scale2x_uint8* dst0, scale2x_uint8* dst1, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x_16_def(scale2x_uint16* dst0, scale2x_uint16* dst1, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x_32_def(scale2x_uint32* dst0, scale2x_uint32* dst1, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);

void scale2x3_8_def(scale2x_uint8* dst0, scale2x_uint8* dst1, scale2x_uint8* dst2, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x3_16_def(scale2x_uint16* dst0, scale2x_uint16* dst1, scale2x_uint16* dst2, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x3_32_def(scale2x_uint32* dst0, scale2x_uint32* dst1, scale2x_uint32* dst2, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);

void scale2x4_8_def(scale2x_uint8* dst0, scale2x_uint8* dst1, scale2x_uint8* dst2, scale2x_uint8* dst3, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x4_16_def(scale2x_uint16* dst0, scale2x_uint16* dst1, scale2x_uint16* dst2, scale2x_uint16* dst3, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x4_32_def(scale2x_uint32* dst0, scale2x_uint32* dst1, scale2x_uint32* dst2, scale2x_uint32* dst3, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);

#if defined(__x86_64__) || defined(_M_X64) || defined(__SSE2__) || (defined(_M_IX86_FP) && (_M_IX86_FP == 2))
/* use SSE2 code :
 *      if generating x86_64 code (all 64bits x86 CPUs support SSE2)
 *      if __SSE2__ is defined (-msse2 with GCC)
 *      if _M_IX86_FP == 2 (/arch:SSE2 with MS Visual C++)   */
void scale2x_8_sse2(scale2x_uint8* dst0, scale2x_uint8* dst1, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x_16_sse2(scale2x_uint16* dst0, scale2x_uint16* dst1, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x_32_sse2(scale2x_uint32* dst0, scale2x_uint32* dst1, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);

void scale2x3_8_sse2(scale2x_uint8* dst0, scale2x_uint8* dst1, scale2x_uint8* dst2, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x3_16_sse2(scale2x_uint16* dst0, scale2x_uint16* dst1, scale2x_uint16* dst2, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x3_32_sse2(scale2x_uint32* dst0, scale2x_uint32* dst1, scale2x_uint32* dst2, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);

void scale2x4_8_sse2(scale2x_uint8* dst0, scale2x_uint8* dst1, scale2x_uint8* dst2, scale2x_uint8* dst3, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x4_16_sse2(scale2x_uint16* dst0, scale2x_uint16* dst1, scale2x_uint16* dst2, scale2x_uint16* dst3, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x4_32_sse2(scale2x_uint32* dst0, scale2x_uint32* dst1, scale2x_uint32* dst2, scale2x_uint32* dst3, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);
#endif /* USE_SCALE2X_SSE2 */

#if defined(USE_SCALE2X_MMX)

void scale2x_8_mmx(scale2x_uint8* dst0, scale2x_uint8* dst1, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x_16_mmx(scale2x_uint16* dst0, scale2x_uint16* dst1, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x_32_mmx(scale2x_uint32* dst0, scale2x_uint32* dst1, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);

void scale2x3_8_mmx(scale2x_uint8* dst0, scale2x_uint8* dst1, scale2x_uint8* dst2, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x3_16_mmx(scale2x_uint16* dst0, scale2x_uint16* dst1, scale2x_uint16* dst2, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x3_32_mmx(scale2x_uint32* dst0, scale2x_uint32* dst1, scale2x_uint32* dst2, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);

void scale2x4_8_mmx(scale2x_uint8* dst0, scale2x_uint8* dst1, scale2x_uint8* dst2, scale2x_uint8* dst3, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
void scale2x4_16_mmx(scale2x_uint16* dst0, scale2x_uint16* dst1, scale2x_uint16* dst2, scale2x_uint16* dst3, const scale2x_uint16* src0, const scale2x_uint16* src1, const scale2x_uint16* src2, unsigned count);
void scale2x4_32_mmx(scale2x_uint32* dst0, scale2x_uint32* dst1, scale2x_uint32* dst2, scale2x_uint32* dst3, const scale2x_uint32* src0, const scale2x_uint32* src1, const scale2x_uint32* src2, unsigned count);

/**
 * End the use of the MMX instructions.
 * This function must be called before using any floating-point operations.
 */
static __inline__ void scale2x_mmx_emms(void)
{
	__asm__ __volatile__ (
		"emms"
	);
}

#endif

#if defined(__ALTIVEC__)
void scale2x_8_altivec(scale2x_uint8* dst0, scale2x_uint8* dst1, const scale2x_uint8* src0, const scale2x_uint8* src1, const scale2x_uint8* src2, unsigned count);
#endif /* __ALTIVEC__ */

#endif

