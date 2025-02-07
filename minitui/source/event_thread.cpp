#include <event.h>
#include <debug.h>

static 
void 
tui_timer_interupter() {
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    tui_event *event = new tui_event(
      TUI_TIMER_INTERUPTER_EVENT,
      NULL
    );
    gbl_event_queue.push_event(event);
  }
}

static 
void 
tui_keyboard_interupter() {
  while (true) {
    auto event = tui_get_event();
    if (event) {
      gbl_event_queue.push_event(event);
    }
    else {
      Error("Event is NULL");
    }
  }
}

void 
tui_threads_init() {
  std::thread t_timer(tui_timer_interupter);
  std::thread t_keyboard(tui_keyboard_interupter);
  t_timer.detach();
  t_keyboard.detach();
}