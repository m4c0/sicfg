#pragma leco tool

import sicfg;

int main() {
  sicfg::boolean("test", true);
  bool b = sicfg::boolean("test");
}
