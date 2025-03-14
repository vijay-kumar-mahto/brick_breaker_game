<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Brick Breaker - README</title>
    <style>
        body {
            font-family: 'Segoe UI', Arial, sans-serif;
            line-height: 1.6;
            margin: 0;
            padding: 20px;
            background-color: #f5f6f5;
            color: #2d3748;
        }
        .container {
            max-width: 900px;
            margin: 0 auto;
            background: #ffffff;
            padding: 30px;
            border-radius: 10px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
        h1 {
            color: #1a202c;
            text-align: center;
            font-size: 2.5em;
            margin-bottom: 10px;
        }
        h2 {
            color: #2d3748;
            border-bottom: 2px solid #3182ce;
            padding-bottom: 5px;
            font-size: 1.8em;
        }
        h3 {
            color: #4a5568;
            font-size: 1.4em;
        }
        p, li {
            font-size: 1em;
        }
        ul {
            list-style-type: disc;
            margin-left: 20px;
        }
        pre {
            background: #edf2f7;
            padding: 15px;
            border-radius: 5px;
            overflow-x: auto;
            position: relative;
            font-family: 'Fira Code', monospace;
        }
        code {
            font-family: 'Fira Code', monospace;
            background: #e2e8f0;
            padding: 2px 6px;
            border-radius: 3px;
        }
        .copy-btn {
            position: absolute;
            top: 10px;
            right: 10px;
            background: #3182ce;
            color: #fff;
            border: none;
            padding: 5px 10px;
            border-radius: 3px;
            cursor: pointer;
            font-size: 0.9em;
        }
        .copy-btn:hover {
            background: #2b6cb0;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
        }
        th, td {
            padding: 12px;
            border: 1px solid #e2e8f0;
            text-align: left;
        }
        th {
            background: #3182ce;
            color: #fff;
        }
        a {
            color: #3182ce;
            text-decoration: none;
            cursor: pointer;
        }
        a:hover {
            text-decoration: underline;
        }
        img {
            max-width: 150px;
            height: auto;
            display: block;
            margin: 20px auto;
            border-radius: 5px;
        }
        .badge {
            display: block;
            width: fit-content;
            padding: 5px 10px;
            background: #48bb78;
            color: #fff;
            border-radius: 3px;
            font-size: 0.9em;
            margin: 5px auto;
            text-align: center;
        }
        #license-text {
            display: none;
            background: #edf2f7;
            padding: 15px;
            border-radius: 5px;
            margin-top: 10px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Brick Breaker</h1>
        <img src="Resources/icon.png" alt="Brick Breaker Logo"> <!-- Replace with actual path -->
        <p><span class="badge">Version 1.0.0</span></p>

        <p>
            <strong>Brick Breaker</strong> is a modern take on the classic arcade game, developed with C++ and the SFML library. Smash bricks, collect power-ups, and conquer three challenging levels with a sleek UI and customizable settings. Perfect for players and developers alike.
        </p>

        <h2>Table of Contents</h2>
        <ul>
            <li><a href="#overview">Overview</a></li>
            <li><a href="#features">Features</a></li>
            <li><a href="#installation">Installation</a></li>
            <li><a href="#usage">Usage</a></li>
            <li><a href="#controls">Controls</a></li>
            <li><a href="#project-structure">Project Structure</a></li>
            <li><a href="#contributing">Contributing</a></li>
            <li><a href="#license">License</a></li>
            <li><a href="#contact">Contact</a></li>
        </ul>

        <h2 id="overview">Overview</h2>
        <p>
            Built from scratch, Brick Breaker combines nostalgic gameplay with modern enhancements. It features a robust game engine (<code>GameLogic</code>), a dynamic UI (<code>Interface</code>, <code>HUD</code>), and screen management (<code>ScreenManager</code>), all powered by SFML for graphics and audio. This project is open-source under the MIT License, inviting contributions from the community.
        </p>

        <h2 id="features">Features</h2>
        <ul>
            <li><strong>Multi-Level Gameplay</strong>: Three levels with increasing difficulty (4-6 rows of bricks).</li>
            <li><strong>Power-Ups</strong>:
                <ul>
                    <li><em>Speed Boost</em>: Temporarily increases ball speed.</li>
                    <li><em>Paddle Size</em>: Extends paddle width for easier hits.</li>
                </ul>
            </li>
            <li><strong>Settings</strong>:
                <ul>
                    <li>Sound toggle (ON/OFF).</li>
                    <li>Game speed options (0.5x, 1.0x, 1.5x, 2.0x) applied globally.</li>
                    <li>High score reset.</li>
                </ul>
            </li>
            <li><strong>User Interface</strong>:
                <ul>
                    <li>Main menu with level selection.</li>
                    <li>In-game HUD with score, lives, level, and controls.</li>
                    <li>Game Over screen with reset/exit options.</li>
                </ul>
            </li>
            <li><strong>Persistent Data</strong>: High scores saved via <code>GameRecords</code>.</li>
            <li><strong>Audio</strong>: Effects for paddle hits, brick breaks, power-ups, and more via <code>ResourceManager</code>.</li>
        </ul>

        <h2 id="installation">Installation</h2>
        <h3>Prerequisites</h3>
        <ul>
            <li><strong>C++ Compiler</strong>: GCC 9+, MSVC 2019+, or Clang 10+ (C++11 required).</li>
            <li><strong>SFML</strong>: Version 2.5.1 or higher (<a href="https://www.sfml-dev.org/download.php">Download</a>).</li>
            <li><strong>CMake</strong>: Version 3.10+ (optional, for build automation).</li>
            <li><strong>OS</strong>: Windows 10+, macOS 10.15+, or Linux (Ubuntu 20.04+ tested).</li>
        </ul>

        <h3>Steps</h3>
        <ol>
            <li><strong>Clone the Repository</strong>:
                <pre><code id="clone-cmd">git clone https://github.com/yourusername/brick-breaker.git
cd brick-breaker</code><button class="copy-btn" onclick="copyToClipboard('clone-cmd')">Copy</button></pre>
</li>
<li><strong>Install SFML</strong>:
<ul>
<li><strong>Windows</strong>: Extract SFML to <code>C:\SFML</code> and set environment variables.</li>
<li><strong>Linux</strong>: <pre><code id="sfml-linux">sudo apt-get install libsfml-dev</code><button class="copy-btn" onclick="copyToClipboard('sfml-linux')">Copy</button></pre></li>
<li><strong>macOS</strong>: <pre><code id="sfml-macos">brew install sfml</code><button class="copy-btn" onclick="copyToClipboard('sfml-macos')">Copy</button></pre></li>
</ul>
</li>
<li><strong>Build the Project</strong>:
<ul>
<li><strong>CMake</strong>:
<pre><code id="cmake-build">mkdir build
cd build
cmake ..
cmake --build .</code><button class="copy-btn" onclick="copyToClipboard('cmake-build')">Copy</button></pre>
</li>
<li><strong>Manual</strong>: Link SFML libraries (e.g., <code>-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio</code>).</li>
</ul>
</li>
<li><strong>Run</strong>:
<p>Navigate to <code>build/</code> and execute <code>./BrickBreaker</code> (Linux/macOS) or <code>BrickBreaker.exe</code> (Windows).</p>
</li>
</ol>

        <h2 id="usage">Usage</h2>
        <ol>
            <li><strong>Start the Game</strong>: Run the executable.</li>
            <li><strong>Main Menu</strong>:
                <ul>
                    <li><em>New Game</em>: Pick Level 1, 2, or 3.</li>
                    <li><em>Resume</em>: Continue a paused session.</li>
                    <li><em>Settings</em>: Adjust sound/speed or reset high score.</li>
                </ul>
            </li>
            <li><strong>Play</strong>: Use the paddle to break bricks and collect power-ups.</li>
            <li><strong>Settings</strong>: Toggle sound, set speed (persists across levels), or reset scores.</li>
        </ol>

        <h2 id="controls">Controls</h2>
        <table>
            <tr><th>Action</th><th>Key/Input</th></tr>
            <tr><td>Move Paddle Left</td><td>Left Arrow</td></tr>
            <tr><td>Move Paddle Right</td><td>Right Arrow</td></tr>
            <tr><td>Pause/Resume</td><td>"Pause" button or Esc to menu</td></tr>
            <tr><td>Reset Game</td><td>R (game over) or "Reset" button</td></tr>
            <tr><td>Exit to Menu</td><td>Esc or "Menu" button</td></tr>
            <tr><td>Exit Game</td><td>"Exit" button</td></tr>
            <tr><td>Select Menu Option</td><td>Left Mouse Click</td></tr>
        </table>

        <h2 id="project-structure">Project Structure</h2>
        <p>A breakdown of the project’s file organization:</p>
        <pre><code id="structure">BrickBreaker/
├── include/           # Header files
│   ├── Core/         # Core game components
│   │   ├── Ball.h        # Ball mechanics
│   │   ├── Brick.h       # Brick properties
│   │   ├── GameLogic.h   # Main game logic
│   │   ├── GameRecords.h # High score management
│   │   ├── Paddle.h      # Paddle controls
│   │   └── PowerUp.h     # Power-up effects
│   ├── Screen/       # Screen management
│   │   ├── GameScreen.h  # Gameplay screen
│   │   ├── MenuScreen.h  # Menu screen
│   │   └── Screen.h      # Base screen class
│   └── UI/           # UI components
│       ├── HUD.h         # Heads-up display
│       ├── Interface.h   # Menu interface
│       └── ScreenManager.h # Screen transitions
├── src/              # Source files
│   ├── Core/
│   │   ├── Ball.cpp
│   │   ├── Brick.cpp
│   │   ├── GameLogic.cpp
│   │   ├── GameRecords.cpp
│   │   ├── Paddle.cpp
│   │   └── PowerUp.cpp
│   ├── Screen/
│   │   ├── GameScreen.cpp
│   │   └── MenuScreen.cpp
│   └── UI/
│       ├── HUD.cpp
│       ├── Interface.cpp
│       └── ScreenManager.cpp
├── Resources/        # Assets
│   ├── font.ttf     # UI font
│   ├── paddle_hit.wav
│   ├── brick_break.wav
│   ├── power_up.wav
│   ├── life_lost.wav
│   └── menu_click.wav
├── CMakeLists.txt   # CMake build config
├── LICENSE          # MIT License
└── README.md        # Markdown README</code><button class="copy-btn" onclick="copyToClipboard('structure')">Copy</button></pre>

        <h2 id="contributing">Contributing</h2>
        <p>We welcome contributions to enhance Brick Breaker!</p>
        <ol>
            <li><strong>Fork</strong>: Clone the repo to your GitHub account.</li>
            <li><strong>Branch</strong>: <pre><code id="branch-cmd">git checkout -b feature/your-feature</code><button class="copy-btn" onclick="copyToClipboard('branch-cmd')">Copy</button></pre></li>
            <li><strong>Develop</strong>: Add features or fix bugs.</li>
            <li><strong>Test</strong>: Verify functionality across levels.</li>
            <li><strong>Commit</strong>: <pre><code id="commit-cmd">git commit -m "Add your message"</code><button class="copy-btn" onclick="copyToClipboard('commit-cmd')">Copy</button></pre></li>
            <li><strong>Push</strong>: <pre><code id="push-cmd">git push origin feature/your-feature</code><button class="copy-btn" onclick="copyToClipboard('push-cmd')">Copy</button></pre></li>
            <li><strong>PR</strong>: Submit a pull request with a detailed description.</li>
        </ol>
        <h3>Guidelines</h3>
        <ul>
            <li>Use consistent C++ style (camelCase, comments).</li>
            <li>Test with all speed settings and levels.</li>
            <li>Update docs for major changes.</li>
        </ul>

        <h2 id="license">License</h2>
        <p>This project is licensed under the MIT License. <a onclick="toggleLicense()">See LICENSE for details</a>.</p>
        <div id="license-text">
            <pre><code>MIT License

Copyright (c) 2025 [Your Name]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.</code></pre>
</div>

        <h2 id="contact">Contact</h2>
        <p>
            For questions, suggestions, or issues:
            <ul>
                <li><strong>Email</strong>: <a href="mailto:your.email@example.com">NULL</a></li>
                <li><strong>GitHub</strong>: <a href="https://github.com/vijay-kumar-mahto">vijay-kumar-mahto</a></li>
                <li><strong>Issues</strong>: <a href="https://github.com/vijay-kumar-mahto/brick-breaker/issues">Report a bug</a></li>
            </ul>
        </p>
    </div>

    <script>
        function copyToClipboard(elementId) {
            const text = document.getElementById(elementId).innerText;
            navigator.clipboard.writeText(text).then(() => {
                alert('Copied to clipboard!');
            }).catch(err => {
                console.error('Failed to copy: ', err);
            });
        }

        function toggleLicense() {
            const licenseText = document.getElementById('license-text');
            if (licenseText.style.display === 'block') {
                licenseText.style.display = 'none';
            } else {
                licenseText.style.display = 'block';
            }
        }
    </script>
</body>
</html>