/* info.h
 *
 * Copyright (C) 2025 Ivan Guerreschi.
 *
 * This file is part of cpwd.
 *
 * cpwd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cpwd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with cpwd.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef INFO_H
#define INFO_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* Returns the version string of the cpwd package. */
const char *version (void);

/* Returns the package name of the cpwd package. */
const char *package (void);

/* Returns the bug report address for the cpwd package. */
const char *bugreport (void);

/* Returns the license information for the cpwd package. */
const char *license (void);

/* Returns the help text for the cpwd package. */
const char *help (void);

#endif /* INFO_H */
