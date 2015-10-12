// input.h

#ifndef INCLUDED_INPUT
# define INCLUDED_INPUT

#include "itickable.h"
#include <SFML/Window.hpp>

#define INPUT_NUMBER 109

namespace StevensDev
{
namespace sgdi
{

class Input : public sgds::ITickable
{
public:
enum InputType
{
  UNKNOWN_KEY,
  A_KEY,
  B_KEY,
  C_KEY,
  D_KEY,
  E_KEY,
  F_KEY,
  G_KEY,
  H_KEY,
  I_KEY,
  J_KEY,
  K_KEY,
  L_KEY,
  M_KEY,
  N_KEY,
  O_KEY,
  P_KEY,
  Q_KEY,
  R_KEY,
  S_KEY,
  T_KEY,
  U_KEY,
  V_KEY,
  W_KEY,
  X_KEY,
  Y_KEY,
  Z_KEY,
  NUM0_KEY,
  NUM1_KEY,
  NUM2_KEY,
  NUM3_KEY,
  NUM4_KEY,
  NUM5_KEY,
  NUM6_KEY,
  NUM7_KEY,
  NUM8_KEY,
  NUM9_KEY,
  ESCAPE_KEY,
  LCONTROL_KEY,
  LSHIFT_KEY,
  LALT_KEY,
  LSYSTEM_KEY,
  RCONTROL_KEY,
  RSHIFT_KEY,
  RALT_KEY,
  RSYSTEM_KEY,
  MENU_KEY,
  LBRACKET_KEY,
  RBRACKET_KEY,
  SEMICOLON_KEY,
  COMMA_KEY,
  PERIOD_KEY,
  QUOTE_KEY,
  SLASH_KEY,
  BACKSLASH_KEY,
  TILDE_KEY,
  EQUAL_KEY,
  DASH_KEY,
  SPACE_KEY,
  RETURN_KEY,
  BACKSPACE_KEY,
  TAB_KEY,
  PAGEUP_KEY,
  PAGEDOWN_KEY,
  END_KEY,
  HOME_KEY,
  INSERT_KEY,
  DELETE_KEY,
  ADD_KEY,
  SUBTRACT_KEY,
  MULTIPLY_KEY,
  DIVIDE_KEY,
  LEFT_KEY,
  RIGHT_KEY,
  UP_KEY,
  DOWN_KEY,
  NUMPAD0_KEY,
  NUMPAD1_KEY,
  NUMPAD2_KEY,
  NUMPAD3_KEY,
  NUMPAD4_KEY,
  NUMPAD5_KEY,
  NUMPAD6_KEY,
  NUMPAD7_KEY,
  NUMPAD8_KEY,
  NUMPAD9_KEY,
  F1_KEY,
  F2_KEY,
  F3_KEY,
  F4_KEY,
  F5_KEY,
  F6_KEY,
  F7_KEY,
  F8_KEY,
  F9_KEY,
  F10_KEY,
  F11_KEY,
  F12_KEY,
  F13_KEY,
  F14_KEY,
  F15_KEY,
  PAUSE_KEY,
  KEYCOUNT_KEY,
  LEFT_MOUSE,
  RIGHT_MOUSE,
  MIDDLE_MOUSE,
  XBUTTON1_MOUSE,
  XBUTTON2_MOUSE,
  BUTTONCOUNT_MOUSE
};

private:
  static Input* d_inst;
  bool d_pressed[INPUT_NUMBER]{0};
  bool d_down[INPUT_NUMBER]{0};

  // CONSTRUCTORS
  Input();
    // Default constructor
  Input( const Input& copy ) = delete;
    // Copy constructor
  Input& operator=( const Input& assign ) = delete;
    // Assignment operator
public:
  // Destructor
  ~Input();

  // ACCESSORS
  static Input& inst();

  // MEMBER FUNCTIONS
  bool isDown( InputType type );
    // Current state down
  bool isUp( InputType type );
    // Current state up
  bool wasPressed( InputType type );
    // Was down and now is up
  void preTick();
    // Poll input state at this point, setup internal state
  void tick( float dtS );
  void postTick();
};

} // End sgdi namespace
} // End StevensDev namespace

#endif
