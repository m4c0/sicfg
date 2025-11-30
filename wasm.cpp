module sicfg;

namespace sicfg {
  void boolean(jute::view name, bool value) {}
  bool boolean(jute::view name) { return false; }

  void number(jute::view name, uint32_t value) {}
  uint32_t number(jute::view name) { return 0; }
}

