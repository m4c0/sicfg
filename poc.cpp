#pragma leco tool

import sicfg;
import silog;

int main() {
  bool val = sicfg::boolean("test");
  silog::log(silog::info, "test was %d", val);
  
  sicfg::boolean("test", !val);

  val = sicfg::boolean("test");
  silog::log(silog::info, "test is %d", val);
}
