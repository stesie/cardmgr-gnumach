/*
 * Copyright (C) 2006 Stefan Siegl <stesie@brokenpipe.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <assert.h>

/*
 * gnumach_do_ioctl
 *
 * try to send the ioctl() from the cardmgr to the gnumach kernel somehow.
 * `arg' is a pointer to any of `union ds_ioctl_arg_t'. Since there is no
 * ioctl RPC, we need to use a combination of get_status and set_status.
 *
 * In case of IOWR ioctls, first do a set_status call, sending the data.
 * The kernel will just cache that data and wait for a get_status call,
 * which will finally trigger the action.
 */
static int gnumach_do_ioctl(int fd, unsigned long int req, void *arg)
{
    kern_return_t err;
    mach_port_t port = (mach_port_t) fd;

    /* extract the data size in bytes */
    unsigned int sz = (req & IOCSIZE_MASK) >> IOCSIZE_SHIFT;
    assert((sz % sizeof(natural_t)) == 0);

    unsigned int bufsz = sz / sizeof(natural_t);
    dev_status_t buf = malloc(sz);

    if(! buf)
	return -1;

    if(req & IOC_IN) {
	/* we need to handle a Write-IOCTL, therefore we need
	 * to device_set_status first */
	
	assert(arg);
	memcpy(buf, arg, sz);

	err = device_set_status(port, req, buf, bufsz);
	if(err) goto out;
    } 

    err = device_get_status(port, req, buf, &bufsz);
    if(err) goto out;

    if(arg) memcpy(arg, buf, sz);

 out:
    free(buf);
    return err ? -1 : 0;
}
