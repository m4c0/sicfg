export module sicfg;
import jute;

export namespace sicfg {
  void boolean(jute::view name, bool value);
  bool boolean(jute::view name);
}

#if LECO_TARGET_MACOSX
#pragma leco add_impl osx
#elif LECO_TARGET_WINDOWS
#pragma leco add_impl windows
#endif
