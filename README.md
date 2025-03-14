# Brick Breaker

![Brick Breaker Logo](Resources/icon.png)

**Version 1.0.0**

Brick Breaker is a modern take on the classic arcade game, developed with C++ and the SFML library. Smash bricks, collect power-ups, and conquer three challenging levels with a sleek UI and customizable settings. Perfect for players and developers alike.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Overview
Built from scratch, Brick Breaker combines nostalgic gameplay with modern enhancements. It features a robust game engine (`GameLogic`), a dynamic UI (`Interface`, `HUD`), and screen management (`ScreenManager`), all powered by SFML for graphics and audio. This project is open-source under the MIT License, inviting contributions from the community.

## Features
- **Multi-Level Gameplay**: Three levels with increasing difficulty (4-6 rows of bricks).
- **Power-Ups**:
  - **Speed Boost**: Temporarily increases ball speed.
  - **Paddle Size**: Extends paddle width for easier hits.
- **Settings**:
  - Sound toggle (ON/OFF).
  - Game speed options (0.5x, 1.0x, 1.5x, 2.0x).
  - High score reset.
- **User Interface**:
  - Main menu with level selection.
  - In-game HUD with score, lives, level, and controls.
  - Game Over screen with reset/exit options.
- **Persistent Data**: High scores saved via `GameRecords`.
- **Audio**: Effects for paddle hits, brick breaks, power-ups, and more via `ResourceManager`.

## Installation
### Prerequisites
- **C++ Compiler**: GCC 9+ (C++11 required).
- **SFML**: Version 2.5.1 or higher ([Download](https://www.sfml-dev.org/download.php)).
- **CMake**: Version 3.10+ (optional, for build automation).
- **OS**: Windows 10+, macOS 10.15+, or Linux (Ubuntu 20.04+ tested).

### Steps
1. **Clone the Repository**:
   ```sh
   git clone https://github.com/vijay-kumar-mahto/brick-breaker.git
   cd brick-breaker
   ```
2. **Install SFML**:
  - Windows: Extract SFML to `C:\SFML` and set environment variables.
  - Linux:
    ```sh
    sudo apt-get install libsfml-dev
    ```
  - macOS:
    ```sh
    brew install sfml
    ```
3. **Build the Project**:
   ```sh
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```
4. **Run**:
   Navigate to `build/` and execute `./BrickBreaker` (Linux/macOS) or `BrickBreaker.exe` (Windows).

## Usage
1. **Start the Game**: Run the executable.
2. **Main Menu**:
  - **New Game**: Pick Level 1, 2, or 3.
  - **Resume**: Continue a paused session.
  - **Settings**: Adjust sound/speed or reset high score.
3. **Play**: Use the paddle to break bricks and collect power-ups.
4. **Settings**: Toggle sound, set speed (persists across levels), or reset scores.

## Controls
| Action           | Key/Input       |
|-----------------|---------------|
| Move Paddle Left | Left Arrow     |
| Move Paddle Right | Right Arrow    |
| Pause/Resume    | Esc            |
| Reset Game      | R (game over)  |
| Exit to Menu    | Esc or Menu Btn |
| Exit Game       | Exit Button    |
| Select Menu Option | Left Mouse Click |

## Project Structure
```
BrickBreaker/
├── include/                  # Header files
│   ├── Core/                # Core game components
│   │   ├── Ball.h           # Ball mechanics
│   │   ├── Brick.h          # Brick properties
│   │   ├── GameLogic.h      # Main game logic
│   │   ├── GameRecords.h    # High score management
│   │   ├── Paddle.h         # Paddle controls
│   │   └── PowerUp.h        # Power-up effects
│   ├── Screen/              # Screen management
│   │   ├── GameScreen.h     # Gameplay screen
│   │   ├── MenuScreen.h     # Menu screen
│   │   └── Screen.h         # Base screen class
│   └── UI/                  # UI components
│       ├── HUD.h            # Heads-up display
│       ├── Interface.h      # Menu interface
│       └── ScreenManager.h  # Screen transitions
├── src/                     # Source files
├── Resources/               # Assets
├── CMakeLists.txt          # CMake build configuration
├── LICENSE                 # MIT License file
└── README.md               # Markdown README (this file)
```

## Contributing
1. **Fork**: Clone the repo to your GitHub account.
2. **Branch**:
   ```sh
   git checkout -b feature/your-feature
   ```
3. **Develop**: Add features or fix bugs.
4. **Test**: Verify functionality across levels.
5. **Commit**:
   ```sh
   git commit -m "Add your message"
   ```
6. **Push**:
   ```sh
   git push origin feature/your-feature
   ```
7. **PR**: Submit a pull request with a detailed description.

### Guidelines
- Use consistent C++ style (camelCase, comments).
- Test with all speed settings and levels.
- Update docs for major changes.

## License
This project is licensed under the MIT License.

## Contact
For questions, suggestions, or issues:
- **GitHub**: [vijay-kumar-mahto](https://github.com/vijay-kumar-mahto)
- **Issues**: [Report a bug](https://github.com/vijay-kumar-mahto/brick-breaker/issues)

