/*****************************************************************************
 *  @file hash_string.c
 *  Hash function for strings.
 *
 *  Copyright (c) 2012-2016 The fli4l team
 *
 *  This file is part of fli4l.
 *
 *  fli4l is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  fli4l is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with fli4l.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Last Update: $Id$
 *****************************************************************************
 */

#include <container/hashfunc.h>
#include <ctype.h>

/**
 * Used to improve the hash value.
 */
#define HASH_PRIME 37

unsigned
hash_string(void const *key)
{
    char const *s = *(char const *const *) key;
    unsigned hash = 0;
    while (*s) {
        hash = hash * HASH_PRIME + *s++;
    }
    return hash;
}

unsigned
hash_ci_string(void const *key)
{
    char const *s = *(char const *const *) key;
    unsigned hash = 0;
    while (*s) {
        hash = hash * HASH_PRIME + toupper(*s++);
    }
    return hash;
}
