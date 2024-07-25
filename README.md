# What is it
Raybrick is a breakout game built with the raylib library in C++. There are available binaries for Linux and Windows.

| ![Debian 12 Menu Screen](https://github.com/Tyfee/raybrick/blob/main/screenshots/main_menu_debian.png) | ![Debian 12 Game Screen](https://github.com/Tyfee/raybrick/blob/main/screenshots/game_debian.png) |
|--|--|
|![Debian 12 Paused Screen](https://github.com/Tyfee/raybrick/blob/main/screenshots/paused_debian.png)  |  ![enter image description here](https://images.prismic.io/hatica/1c408ef0-4190-4e03-b76d-a01a2df82a93_Screenshot+2023-03-14+at+12.42.51+PM.png?auto=compress,format&rect=0,0,1521,620&w=1200&h=489)|

The game background comes from https://freepik.com.

The song sonderland, is an original and is available on [Bandcamp](https://tyfee.bandcamp.com/track/sonderland)

# Compiling it yourslef

In order to compile the source code into a binary file, you will need to have the Raylib installed and compile it as well, getting something like: 

`g++ -o main main.cpp -lraylib`

To compile it into a windows executable, you will need to cross compile it including the necessary libraries, i do it using MinGW like the following: 

`x86_64-w64-mingw32-g++ main.cpp -o raybrick.exe -I<RAYLIB_INCLUDE_PATH> -L<RAYLIB_BUILD_PATH> -lraylib -lopengl32 -lgdi32 -lwinmm`



