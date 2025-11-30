export module sicfg;
import jute;
import traits;

using namespace traits::ints;

export namespace sicfg {
  void boolean(jute::view name, bool value);
  bool boolean(jute::view name);

  void number(jute::view name, uint32_t value);
  uint32_t number(jute::view name);
}

#if LECO_TARGET_APPLE
#pragma leco add_impl osx
#elif LECO_TARGET_WINDOWS
#pragma leco add_impl windows
#elif LECO_TARGET_WASM
#pragma leco add_impl wasm
#endif
