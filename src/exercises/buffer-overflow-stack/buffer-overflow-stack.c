/*
 * SPDX-License-Identifier: BSD-2-Clause
 * Copyright (c) 2022 Microsoft Corporation
 */
#include <stddef.h>
#include <printf.h>
#include <sel4/assert.h>

#pragma weak write_buf
void
write_buf(char *buf, size_t ix)
{
	buf[ix] = 'b';
}

void
init(void)
{
	char upper[0x10];
	char lower[0x10];

	printf("upper = %p, lower = %p, diff = %zx\n",
	    upper, lower, (size_t)(upper - lower));

	/* Assert that these get placed how we expect */
	seL4_Assert((ptraddr_t)upper == (ptraddr_t)&lower[sizeof(lower)]);

	upper[0] = 'a';
	printf("upper[0] = %c\n", upper[0]);

	write_buf(lower, sizeof(lower));

	printf("upper[0] = %c\n", upper[0]);
}

void notified(){}
