#include <iostream>

void test() {
  //test_sfml_window_manager();
  test_normal_char();
}

int show_sfml_drawing_screen() {
  sfml_title_screen ts;
  ts.exec();
  return 0;
}

int main() {
  #ifndef NDEBUG
  test();
  #else
  assert(1 == 2);
  #endif
  
  const std::vector<std::string> args(argv, argv + argc);

  //----------------------------------------------------------------------------
  //Things with early exits
  //----------------------------------------------------------------------------
  //Show the SFML version and quit
  if (std::count(std::begin(args), std::end(args), "--version")) {
    // Travis: 2.1
    // RuG: 2.3.2
    std::cout
      << "SFML version: " << SFML_VERSION_MAJOR
      << "." << SFML_VERSION_MINOR
      #if(SFML_VERSION_MINOR > 1)
      << "." << SFML_VERSION_PATCH
      #endif
      << std::endl
    ;
    return 0;
  }
  
  if (std::count(std::begin(args), std::end(args), "--test")) {
    std::cout << "Hello world!" << std::endl;
  }
  
  while (sfml_window_manager::get().get_window().isOpen()) {
    switch (sfml_window_manager::get().get_state()) {
      case game_state::drawing:
        show_sfml_drawing_screen();
        break;
    }
  }
  
  return 0;
}