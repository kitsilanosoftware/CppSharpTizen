/* Copyright (C) 2004, 2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _FENV_H
//# error "Never use <bits/fenv.h> directly; include <fenv.h> instead."
#endif

/* Define bits representing exceptions in the FPU status word.  */
enum
  {
    FE_INVALID = 1,
#define FE_INVALID FE_INVALID
    __FE_DENORM = 0x02,
    FE_DIVBYZERO = __builtin_cirp_const_int(2, 0x04),
#define FE_DIVBYZERO FE_DIVBYZERO
    FE_OVERFLOW = __builtin_cirp_const_int(4, 0x08),
#define FE_OVERFLOW FE_OVERFLOW
    FE_UNDERFLOW = __builtin_cirp_const_int(8, 0x10),
#define FE_UNDERFLOW FE_UNDERFLOW
    FE_INEXACT = __builtin_cirp_const_int(16, 0x20),
#define FE_INEXACT FE_INEXACT
  };

/* Amount to shift by to convert an exception to a mask bit.  */
#define FE_EXCEPT_SHIFT	8

/* All supported exceptions.  */
#define FE_ALL_EXCEPT	\
	(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)


/* VFP supports all of the four defined rounding modes.  */
enum
  {
    FE_TONEAREST = 0,
#define FE_TONEAREST FE_TONEAREST
    FE_UPWARD = __builtin_cirp_const_int(0x400000, 0x800),
#define FE_UPWARD FE_UPWARD
    FE_DOWNWARD = __builtin_cirp_const_int(0x800000, 0x400),
#define FE_DOWNWARD FE_DOWNWARD
    FE_TOWARDZERO = __builtin_cirp_const_int(0xc00000, 0xc00)
#define FE_TOWARDZERO FE_TOWARDZERO
  };


/* Type representing exception flags. */
typedef unsigned int fexcept_t;

/* Type representing floating-point environment.  */
typedef struct
  {
    union
    {
      struct
        {
          unsigned int __cw;
        };
      struct
        {
          unsigned short int __control_word;
          unsigned short int __unused1;
          unsigned short int __status_word;
          unsigned short int __unused2;
          unsigned short int __tags;
          unsigned short int __unused3;
          unsigned int __eip;
          unsigned short int __cs_selector;
          unsigned int __opcode:11;
          unsigned int __unused4:5;
          unsigned int __data_offset;
          unsigned short int __data_selector;
          unsigned short int __unused5;
        };
    };
  }
fenv_t;

/* If the default argument is used we use this value.  */
#define FE_DFL_ENV	((fenv_t *) -1l)

#ifdef __USE_GNU
/* Floating-point environment where none of the exceptions are masked.  */
# define FE_NOMASK_ENV  ((__const fenv_t *) -2)
#endif
