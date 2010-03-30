#include "pause_state.h"

Pause_State::Pause_State(void)
: State(), dspparameq(0) {}

Pause_State::Pause_State(FMOD_SYSTEM *system, FMOD_DSP *pe, Game_State *gs,
              Drawable *b, Drawable *m, Drawable *p)
:State(system), dspparameq(pe), game_state(gs), background(b),
map(m), pointer(p), selected(0) {}

void Pause_State::draw(void)
{
  game_state->draw();
  background->draw();
  map->draw();
  pointer->draw();
}

void Pause_State::update(int &delta)
{
  state_update();
}

void Pause_State::key_pressed(unsigned char key, int x, int y)
{
  switch(key)
  {
    case 'w':
      if(selected == 0)
      {
        selected = MENU_ITEMS - 1;
        pointer->move(0, POINTER_MOVE * 2);
      }
      else
      {
        --selected;
        pointer->move(0, -POINTER_MOVE);
      }
      break;
    case 's':
      selected = (++selected) % MENU_ITEMS;
      if (selected == 0)
      {
        pointer->move(0, -POINTER_MOVE * 2);
      }
      else
      {
        pointer->move(0, POINTER_MOVE);
      }
      break;
  }
}

void Pause_State::key_released(unsigned char key, int x, int y) {}

void Pause_State::reset_selected(void)
{
  while (selected != 0)
  {
    key_pressed('w', 0, 0);
  }
}

void Pause_State::clean(void)
{
  state_clean();
}
