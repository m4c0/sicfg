#pragma leco add_library advapi32
module;
#define WIN32_MEAN_AND_LEAN
#include <windows.h>

module sicfg;
import hai;
import jute;
import traits;

using namespace traits::ints;

// TODO: check errors

static auto key() {
  static HKEY key{};
  if (key)
    return key;

  hai::cstr path{MAX_PATH};
  GetModuleFileName(nullptr, path.begin(), path.size());

  auto [_, file] = jute::view{path}.rsplit('\\');
  auto [stem, ext] = file.split('.');

  auto subkey = ("Software\\m4c0\\" + stem).cstr();
  RegCreateKeyExA(HKEY_CURRENT_USER, subkey.begin(), 0, nullptr, 0,
                  KEY_WRITE | KEY_READ, nullptr, &key, nullptr);
  return key;
}

void sicfg::boolean(jute::view name, bool val) {
  auto value_name = name.cstr();

  uint32_t dw = val ? 1 : 0;
  RegSetValueExA(key(), value_name.begin(), 0, REG_DWORD,
                 reinterpret_cast<uint8_t *>(&dw), sizeof(dw));
}
bool sicfg::boolean(jute::view name) {
  auto value_name = name.cstr();

  uint32_t value{};
  DWORD size = sizeof(value);
  auto res = RegQueryValueExA(key(), value_name.begin(), nullptr, nullptr,
                              reinterpret_cast<uint8_t *>(&value), &size);
  return res == ERROR_SUCCESS ? (value > 0) : false;
}
