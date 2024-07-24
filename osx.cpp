module;
#include <CoreFoundation/CoreFoundation.h>

module sicfg;
import hai;

namespace {
struct deleter {
  void operator()(CFStringRef r) { CFRelease(r); }
};
using cfstr = hai::holder<const __CFString, deleter>;
} // namespace

static auto to_cfstr(jute::view name) {
  return cfstr{CFStringCreateWithBytesNoCopy(
      nullptr, reinterpret_cast<const UInt8 *>(name.begin()), name.size(),
      kCFStringEncodingUTF8, false, kCFAllocatorNull)};
}

void sicfg::boolean(jute::view name, bool val) {
  auto key = to_cfstr(name);
  auto value = val ? kCFBooleanTrue : kCFBooleanFalse;

  CFPreferencesSetAppValue(*key, value, kCFPreferencesCurrentApplication);
  CFPreferencesAppSynchronize(kCFPreferencesCurrentApplication);
}
bool sicfg::boolean(jute::view name) {
  auto key = to_cfstr(name);

  Boolean exists{};
  auto res = CFPreferencesGetAppBooleanValue(
      *key, kCFPreferencesCurrentApplication, &exists);
  return exists ? res : false;
}
