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
  RegCreateKeyExA(HKEY_CURRENT_USER, subkey.begin(), nullptr, "", 0, KEY_WRITE,
                  nullptr, &key, nullptr);
  return key;
}

void sicfg::boolean(jute::view name, bool val) {
  auto value_name = name.cstr();

  uint32_t dw = val ? 1 : 0;
  RegSetValueExA(key(), value_name.begin(), nullptr, REG_DWORD, &dw,
                 sizeof(dw));
}
bool sicfg::boolean(jute::view name) {
  auto value_name = name.cstr();

  uint32_t value{};
  auto res = RegQueryValueExA(key(), value_name.begin(), nullptr, REG_DWORD,
                              &value, sizeof(value));
  return res == ERROR_SUCCESS ? (value > 0) : false;
}
