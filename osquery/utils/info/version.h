/**
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under both the Apache 2.0 license (found in the
 *  LICENSE file in the root directory of this source tree) and the GPLv2 (found
 *  in the COPYING file in the root directory of this source tree).
 *  You may select, at your option, one of the above-listed licenses.
 */

#pragma once

#include <string>

#include <osquery/utils/macros/macros.h>

namespace osquery {

#if !defined(OSQUERY_VERSION)
#error The build must define OSQUERY_VERSION.
#endif

#if !defined(OSQUERY_BUILD_VERSION)
#warning The build should define OSQUERY_BUILD_VERSION.
#define OSQUERY_BUILD_VERSION 1.0.0-unknown
#endif

#if !defined(OSQUERY_BUILD_SDK_VERSION)
#error The build must define OSQUERY_BUILD_SDK_VERSION.
#endif

#define OSQUERY_SDK_VERSION STR(OSQUERY_BUILD_SDK_VERSION)

/// The version of osquery
extern const std::string kVersion;

/// The osquery SDK version
extern const std::string kSDKVersion;

/**
 * @brief Compare osquery SDK/extenion/core version strings.
 *
 * SDK versions are in major.minor.patch-commit-hash form. We provide a helper
 * method for performing version comparisons to allow gating and compatibility
 * checks throughout the code.
 *
 * @param v version to check
 * @param sdk (optional) the SDK version to check against.
 * return true if the input version is at least the SDK version.
 */
bool versionAtLeast(const std::string& v,
                    const std::string& version = kVersion);

} // namespace osquery
