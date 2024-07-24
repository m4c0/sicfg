export module sicfg;
import jute;

export namespace sicfg {
  void boolean(jute::view name, bool value);
  bool boolean(jute::view name);
}
