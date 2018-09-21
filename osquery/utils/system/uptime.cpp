/**
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under both the Apache 2.0 license (found in the
 *  LICENSE file in the root directory of this source tree) and the GPLv2 (found
 *  in the COPYING file in the root directory of this source tree).
 *  You may select, at your option, one of the above-listed licenses.
 */

#include <osquery/utils/system/uptime.h>

#if defined(__APPLE__)
#include <errno.h>
#include <sys/sysctl.h>
#include <time.h>
#elif defined(__linux__)
#include <sys/sysinfo.h>
#elif defined(WIN32)
#include <windows.h>
#endif

namespace osquery {

long getUptime() {
#if defined(DARWIN)
  struct timeval boot_time;
  size_t len = sizeof(boot_time);
  int mib[2] = {CTL_KERN, KERN_BOOTTIME};

  if (sysctl(mib, 2, &boot_time, &len, nullptr, 0) < 0) {
    return -1;
  }

  time_t seconds_since_boot = boot_time.tv_sec;
  time_t current_seconds = time(nullptr);

  return long(difftime(current_seconds, seconds_since_boot));
#elif defined(__linux__)
  struct sysinfo sys_info;

  if (sysinfo(&sys_info) != 0) {
    return -1;
  }

  return sys_info.uptime;
#elif defined(WIN32)
  return static_cast<long>(GetTickCount64() / 1000);
#endif

  return -1;
}

} // namespace osquery
