/*----------------------------------------------------------------------------
 *  boottype_generic.c - functions for handling generic boot types
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
 *----------------------------------------------------------------------------
 */

#include <libmkfli4l/defs.h>
#include <libmkfli4l/str.h>
#include <libmkfli4l/log.h>
#include <libmkfli4l/options.h>
#include <archive/archive.h>
#include <archive/arch_type_cpio.h>
#include <archive/arch_type_tar.h>
#include <ziplist/opt.h>
#include "boottype_generic.h"

static int
add_generic_boot_type_entries(struct boot_type_backend_t *backend)
{
    (void) backend;
    return OK;
}

static BOOL
filter_entry(struct entry_t *entry, void *data)
{
    int const ziptgt = *(int *) data;
    return entry->ziptgt == ziptgt;
}

static int
create_generic_boot_type_archives(struct boot_type_backend_t *backend, struct arch_comp_backend_t *comp_rootfs_backend, struct arch_comp_backend_t *comp_opt_backend)
{
    int ziptgt;
    int rc;

    ziptgt = ZIP_TGT_OPT;
    if ((rc = create_complete_archive(opt_img_file,
                                      build_dir,
                                      scratch_dir,
                                      create_tar_backend(),
                                      comp_opt_backend,
                                      filter_entry,
                                      &ziptgt)) != OK) {
        return rc;
    }

    ziptgt = ZIP_TGT_ROOTFS;
    if ((rc = create_complete_archive(rootfs_img_file,
                                      build_dir,
                                      scratch_dir,
                                      create_cpio_backend(),
                                      comp_rootfs_backend,
                                      filter_entry,
                                      &ziptgt)) != OK) {
        return rc;
    }

    (void) backend;
    return OK;
}

static void
destroy_generic_boot_type_backend(struct boot_type_backend_t *backend)
{
    (void) backend;
}

struct boot_type_backend_t *
create_generic_boot_type_backend(void)
{
    struct boot_type_backend_t *backend = (struct boot_type_backend_t *)
            safe_malloc(sizeof(struct boot_type_backend_t));

    backend->add_entries = &add_generic_boot_type_entries;
    backend->create_archives = &create_generic_boot_type_archives;
    backend->destroy_backend = &destroy_generic_boot_type_backend;
    backend->extra_data = NULL;

    return backend;
}
