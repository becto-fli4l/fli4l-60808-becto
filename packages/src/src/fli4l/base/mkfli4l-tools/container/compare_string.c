/*****************************************************************************
 *  @file compare_string.c
 *  Function comparing string keys.
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

#include <container/cmpfunc.h>
#include <string.h>
#include <strings.h>

BOOL
compare_string_keys(void const *key1, void const *key2)
{
    return strcmp(*(char const *const *) key1, *(char const *const *) key2) == 0;
}

BOOL
compare_ci_string_keys(void const *key1, void const *key2)
{
    return strcasecmp(*(char const *const *) key1, *(char const *const *) key2) == 0;
}
