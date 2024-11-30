#include <basics.h>
#include <debug.h>
#include <minitui.h>
#include <mainscr.h>

tui_widget *reg_mainscr(tui_point start, tui_point end, const char *msg) {
  auto mainscr_0 = new mainscr(
    (tui_rect) {start, end},
    NULL
  );
  mainscr_0->set_global_formatter(
    tui_formatter(0x00ff0000u, 0x00ffffffu)
  );

  mainscr_0->set_central_message(
    msg,
    tui_formatter(0x0063065fu, 0x00ffffffu)
  );

  tui_reg_widget(mainscr_0);
  return mainscr_0;
}

int main(int argc, char *argv[]) {
  tui_init(argc, argv);
  ansi_title("NJU Universalis");

  auto mainscr_0 = reg_mainscr(
    (tui_point) {0, 0},
    (tui_point) {SCR_HEIGHT - 1, SCR_WIDTH - 1},
    "Hello, Nanjing University!"
  );

  tui_ncanvas *ncanvas_0 = new tui_ncanvas(
    (tui_rect) {(tui_point) {SCR_HEIGHT - 5, SCR_WIDTH / 2}, (tui_point) {SCR_HEIGHT - 1, SCR_WIDTH - 1}},
    mainscr_0
  );
  tui_reg_widget(ncanvas_0);

  

  int ret_value = tui_exec();
  if (ret_value != 0)
    Warn("tui_exec() returns with a non-zero value %d", ret_value);
  
  return ret_value;
}
