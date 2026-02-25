# nCurses Game Engine

A TUI game engine built in C++ and ncurses.

Note: This project is a work in progress and is being actively developed.
* Active development is being done on the dev branch.

## Current Architecture

The engine is structured around a few core components:

- **Game** - An abstract base class users can use to derive their custom games from.
    - The Game Class provides users:
        - A public `run()` function to start their games.
        - Three pure virtual functions (`input()`, `update()` and `render()`) they can use <br>
        to interface into the game loop and write their custom game logic.
        - A simple `get_input()` function to get input chars from users.
        - An interface to the Screen class so users can create Windows.

- **Screen** - The main interface to the terminal.
    - The Screen Class:
        - Manages ncurses initialization and cleanup.
        - Lets us get user input (in Blocking and NonBlocking modes).
        - Creates and destroys all Windows.

- **Window** - The main interface users use to print output to the screen.
    - The Window Class provides users a way to:
        - Move the cursor (our current printing location) around the screen.
        - Add strings and chars to the screen.
        - Clear and refresh the screen.
    - Note: Windows need to be created through the Screen `create_window()` factory.<br>
        - We don't want windows to exist unless we already have a Screen initialized, <br>
        so we tie their creation, ownership and destruction to the Screen Class.

- **Coord** - A 2D coordinate struct with arithmetic and logical comparison operators.

A typical user game would have the following structure:
```
UserGame : Game (abstract)
 ├── run()          # game loop calls user defined: input() -> update() -> render()
 ├── get_input()    # users can call during input() to get input for their game
 ├── Window* w0     # users access the window through Window* handles
 ├── Window* w1
 └── Screen
      ├── Window w0 # Screen owns the actual Window objects
      └── Window w1
```

## Next Steps

- The next features I am about to start implementing are:
    - Entity Component System (ECS)
    - ASCII Sprite rendering system

## Demo

I currently have a very simple TestGame demo written out in test_game.h, test_game.cpp and main.cpp.
The demo prints a 2x2 cube to screen and lets the user move it around.

- Demo controls
    - Press the 'w' 'a' 's' 'd' keys to move the cube up, left, down and right.
    - Press the 'q' key to exit the game

## Build

You can use the following commands to either build, cleanup or run the TestGame demo:

```bash
make        # build TestGame and Game Engine Library
make clean  # cleanup the build
./main      # run the demo
```

Note: Building requires `ncurses` and `g++`
