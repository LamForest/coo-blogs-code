/* The weak pthread functions for Linux.
   Copyright (C) 1996, 1997 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#include <errno.h>
#include <limits.h>
#include <stdlib.h>

/* This is from <pthread.h>.  */
typedef unsigned int pthread_key_t;

extern int __pthread_return_0 __P ((void));
extern int __pthread_return_1 __P ((void));
extern void __pthread_return_void __P ((void));

/* Those are pthread functions which return 0 if successful. */
weak_alias (__pthread_return_0, pthread_attr_init)
weak_alias (__pthread_return_0, pthread_attr_destroy)
weak_alias (__pthread_return_0, pthread_attr_setdetachstate)
weak_alias (__pthread_return_0, pthread_attr_getdetachstate)
weak_alias (__pthread_return_0, pthread_attr_setschedparam)
weak_alias (__pthread_return_0, pthread_attr_getschedparam)
weak_alias (__pthread_return_0, pthread_attr_setschedpolicy)
weak_alias (__pthread_return_0, pthread_attr_getschedpolicy)
weak_alias (__pthread_return_0, pthread_attr_setinheritsched)
weak_alias (__pthread_return_0, pthread_attr_getinheritsched)
weak_alias (__pthread_return_0, pthread_attr_setscope)
weak_alias (__pthread_return_0, pthread_attr_getscope)
weak_alias (__pthread_return_0, pthread_mutex_init)
weak_alias (__pthread_return_0, pthread_mutex_destroy)
weak_alias (__pthread_return_0, pthread_mutex_lock)
weak_alias (__pthread_return_0, pthread_mutex_unlock)
weak_alias (__pthread_return_0, pthread_mutexattr_setkind_np)
weak_alias (__pthread_return_0, pthread_mutexattr_getkind_np)
weak_alias (__pthread_return_0, pthread_condattr_init)
weak_alias (__pthread_return_0, pthread_condattr_destroy)
weak_alias (__pthread_return_0, pthread_setschedparam)
weak_alias (__pthread_return_0, pthread_getschedparam)
weak_alias (__pthread_return_0, pthread_setcancelstate)
weak_alias (__pthread_return_0, pthread_setcanceltype)
weak_alias (__pthread_return_0, pthread_self)
weak_alias (__pthread_return_0, pthread_cond_init)
weak_alias (__pthread_return_0, pthread_cond_destroy)
weak_alias (__pthread_return_0, pthread_cond_wait)
weak_alias (__pthread_return_0, pthread_cond_signal)
weak_alias (__pthread_return_0, pthread_cond_broadcast)


/* Those are pthread functions which return 1 if successful. */
weak_alias (__pthread_return_1, pthread_equal)

/* pthread_exit () is a special case. */
void
weak_function
pthread_exit (void *retval)
{
  exit (EXIT_SUCCESS);
}

int
__pthread_return_0 (void)
{
  return 0;
}

int
__pthread_return_1 (void)
{
  return 1;
}

void
__pthread_return_void (void)
{
}


/* The key and thread-specific data functions cannot simply be dummies
   since data might be stored in any case.  */

/* Number of supported keys.  */

/* Table of keys. */
struct pthread_key_struct
  {
    int occupied;
    void (*destr) (void *);
    const void *data;
  };

static struct pthread_key_struct keys[PTHREAD_KEYS_MAX] =
  {
    { 0, NULL, NULL },
  };


int
__attribute__ ((weak))
__pthread_key_create (pthread_key_t *key, void (*destructor) (void *))
{
  unsigned int cnt;

  for (cnt = 0; cnt < PTHREAD_KEYS_MAX; ++cnt)
    if (! keys[cnt].occupied)
      {
	keys[cnt].occupied = 1;
	keys[cnt].destr = destructor;
	*key = cnt;
	return 0;
      }
  return EAGAIN;
}


int
__attribute__ ((weak))
__pthread_key_delete (pthread_key_t key)
{
  if (key >= PTHREAD_KEYS_MAX || ! keys[key].occupied)
    return EINVAL;
  keys[key].occupied = 0;
  keys[key].destr = NULL;
  keys[key].data = NULL;
  return 0;
}


int
__attribute__ ((weak))
__pthread_setspecific (pthread_key_t key, const void *ptr)
{
  if (key >= PTHREAD_KEYS_MAX || ! keys[key].occupied)
    return EINVAL;
  keys[key].data = ptr;
  return 0;
}


void *
__attribute__ ((weak))
__pthread_getspecific (pthread_key_t key)
{
  if (key >= PTHREAD_KEYS_MAX || ! keys[key].occupied)
    return NULL;
  return (void *) keys[key].data;
}
