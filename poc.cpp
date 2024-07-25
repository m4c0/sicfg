#pragma leco tool

import sicfg;
import silog;

int main() {
  bool val = sicfg::boolean("test");
  silog::log(silog::info, "test was %d", val);
  
  sicfg::boolean("test", !val);

  val = sicfg::boolean("test");
  silog::log(silog::info, "test is %d", val);

  sicfg::number("num", 1 + sicfg::number("num"));
  silog::log(silog::info, "num is %d", sicfg::number("num"));
}
