// input.cpp

#include "input.h"

namespace StevensDev
{
namespace sgdi
{

Input* Input::d_inst = 0;

// CONSTRUCTORS

Input::Input()
{
  for( unsigned int i = 0; i < INPUT_NUMBER; ++i )
  {
    d_pressed[i] = 0;
    d_down[i] = 0;
  }
}


// DESTRUCTOR

Input::~Input()
{
  delete d_inst;
}


// ACCESSORS

Input& Input::inst()
{
  if( !d_inst )
  {
    d_inst = new Input;
  }
  return *d_inst;
}


// MEMBER FUNCTIONS

bool Input::isDown( InputType type )
{
  return d_down[type];
}

bool Input::isUp( InputType type )
{
  return !d_down[type];
}

bool Input::wasPressed( InputType type )
{
  return d_pressed[type] && !d_down[type];
}

void Input::preTick()
{
  for( unsigned int i = 0; i < INPUT_NUMBER; ++i )
  {
    d_pressed[i] = d_down[i];
  }

  d_down[InputType::UNKNOWN_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Unknown );
  d_down[InputType::A_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::A );
  d_down[InputType::B_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::B );
  d_down[InputType::C_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::C );
  d_down[InputType::D_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::D );
  d_down[InputType::E_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::E );
  d_down[InputType::F_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F );
  d_down[InputType::G_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::G );
  d_down[InputType::H_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::H );
  d_down[InputType::I_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::I );
  d_down[InputType::J_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::J );
  d_down[InputType::K_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::K );
  d_down[InputType::L_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::L );
  d_down[InputType::M_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::M );
  d_down[InputType::N_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::N );
  d_down[InputType::O_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::O );
  d_down[InputType::P_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::P );
  d_down[InputType::Q_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::Q );
  d_down[InputType::R_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::R );
  d_down[InputType::S_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::S );
  d_down[InputType::T_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::T );
  d_down[InputType::U_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::U );
  d_down[InputType::V_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::V );
  d_down[InputType::W_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::W );
  d_down[InputType::X_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::X );
  d_down[InputType::Y_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::Y );
  d_down[InputType::Z_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::Z );
  d_down[InputType::NUM0_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num0 );
  d_down[InputType::NUM1_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num1 );
  d_down[InputType::NUM2_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num2 );
  d_down[InputType::NUM3_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num3 );
  d_down[InputType::NUM4_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num4 );
  d_down[InputType::NUM5_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num5 );
  d_down[InputType::NUM6_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num6 );
  d_down[InputType::NUM7_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num7 );
  d_down[InputType::NUM8_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num8 );
  d_down[InputType::NUM9_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Num9 );
  d_down[InputType::ESCAPE_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Escape );
  d_down[InputType::LCONTROL_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::LControl );
  d_down[InputType::LSHIFT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::LShift );
  d_down[InputType::LALT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::LAlt );
  d_down[InputType::LSYSTEM_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::LSystem );
  d_down[InputType::RCONTROL_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::RControl );
  d_down[InputType::RSHIFT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::RShift );
  d_down[InputType::RALT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::RAlt );
  d_down[InputType::RSYSTEM_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::RSystem );
  d_down[InputType::MENU_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Menu );
  d_down[InputType::LBRACKET_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::LBracket );
  d_down[InputType::RBRACKET_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::RBracket );
  d_down[InputType::SEMICOLON_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::SemiColon );
  d_down[InputType::COMMA_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Comma );
  d_down[InputType::PERIOD_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Period );
  d_down[InputType::QUOTE_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Quote );
  d_down[InputType::SLASH_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Slash );
  d_down[InputType::BACKSLASH_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::BackSlash );
  d_down[InputType::TILDE_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Tilde );
  d_down[InputType::EQUAL_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Equal );
  d_down[InputType::DASH_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Dash );
  d_down[InputType::SPACE_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Space );
  d_down[InputType::RETURN_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Return );
  d_down[InputType::BACKSPACE_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::BackSpace );
  d_down[InputType::TAB_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Tab );
  d_down[InputType::PAGEUP_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::PageUp );
  d_down[InputType::PAGEDOWN_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::PageDown );
  d_down[InputType::END_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::End );
  d_down[InputType::HOME_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Home );
  d_down[InputType::INSERT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Insert );
  d_down[InputType::DELETE_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Delete );
  d_down[InputType::ADD_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Add );
  d_down[InputType::SUBTRACT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Subtract );
  d_down[InputType::MULTIPLY_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Multiply );
  d_down[InputType::DIVIDE_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Divide );
  d_down[InputType::LEFT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Left );
  d_down[InputType::RIGHT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Right );
  d_down[InputType::UP_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Up );
  d_down[InputType::DOWN_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Down );
  d_down[InputType::NUMPAD0_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad0 );
  d_down[InputType::NUMPAD1_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad1 );
  d_down[InputType::NUMPAD2_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad2 );
  d_down[InputType::NUMPAD3_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad3 );
  d_down[InputType::NUMPAD4_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad4 );
  d_down[InputType::NUMPAD5_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad5 );
  d_down[InputType::NUMPAD6_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad6 );
  d_down[InputType::NUMPAD7_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad7 );
  d_down[InputType::NUMPAD8_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad8 );
  d_down[InputType::NUMPAD9_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Numpad9 );
  d_down[InputType::F1_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F1 );
  d_down[InputType::F2_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F2 );
  d_down[InputType::F3_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F3 );
  d_down[InputType::F4_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F4 );
  d_down[InputType::F5_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F5 );
  d_down[InputType::F6_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F6 );
  d_down[InputType::F7_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F7 );
  d_down[InputType::F8_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F8 );
  d_down[InputType::F9_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F9 );
  d_down[InputType::F10_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F10 );
  d_down[InputType::F11_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F11 );
  d_down[InputType::F12_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F12 );
  d_down[InputType::F13_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F13 );
  d_down[InputType::F14_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F14 );
  d_down[InputType::F15_KEY] = sf::Keyboard::isKeyPressed( sf::Keyboard::F15 );
  d_down[InputType::PAUSE_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::Pause );
  d_down[InputType::KEYCOUNT_KEY] =
    sf::Keyboard::isKeyPressed( sf::Keyboard::KeyCount );
  d_down[InputType::LEFT_MOUSE] =
    sf::Mouse::isButtonPressed( sf::Mouse::Left );
  d_down[InputType::RIGHT_MOUSE] =
    sf::Mouse::isButtonPressed( sf::Mouse::Right );
  d_down[InputType::MIDDLE_MOUSE] =
    sf::Mouse::isButtonPressed( sf::Mouse::Middle );
  d_down[InputType::XBUTTON1_MOUSE] =
    sf::Mouse::isButtonPressed( sf::Mouse::XButton1 );
  d_down[InputType::XBUTTON2_MOUSE] =
    sf::Mouse::isButtonPressed( sf::Mouse::XButton2 );
  d_down[InputType::BUTTONCOUNT_MOUSE] =
    sf::Mouse::isButtonPressed( sf::Mouse::ButtonCount );  
}

void Input::tick( float dtS )
{
}

void Input::postTick()
{
}

} // End sgdi namespace
} // End StevensDev namespace
