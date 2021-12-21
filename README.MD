
# Incore

Incore is a friends-project attempt to create a game engine and also learn in the process 
of developing it, using new technology to accomplish this goal with the sole objective to
make a single player rpg game.

## Setting things up
In order to set the incore envieroment on your computer a few things need to be done first.

* Install Python  3.10 or higher and the packages ```request``` and ```tqdm``` as a python script is used to download the vulkan sdk, build our building system and generating the project.
* Clone with ```git clone --recursive https://github.com/Incore-Division/Incore.git``` as there are sub-modules needed to build this project, more on these below.
* Run the python script under ```"Solution/setup.py"```,  it'll check if you have the vulkan sdk installed and attempt to download it if you don't. Instal the vulkan sdk and run the script again, now it'll try to build the premake-core submodule and after that generate the project solution, depending on your platform.
* ```On Windows a visual studio 2022 will be generated under Incore```
* ```On Linux a gnu makefile will be generated under Incore```
* ``` On macosx a xcode project will be generated under Incore``` 

Although multi-platform is supported it's not tested as right at the moment we're using windows but this will change once we have sothing to show.

## Thirdparty and Dependencies
* [Python](https://www.python.org/) as the scripting language (only setup.py right now);
* [Vulkan SDK](https://vulkan.lunarg.com/sdk/home) as the graphics api;
* [premake-core](https://github.com/premake/premake-core) as the building system;
* [GLFW](https://github.com/glfw/glfw) as the windowing system;
* [SPDLOG](https://github.com/gabime/spdlog) as the fast logging library;

## Thanks
* [GanBallD](https://github.com/orgs/Incore-Division/people/GanBallD);
* [MiMoeler](https://github.com/orgs/Incore-Division/people/MiMoeler);
* [Chilli](https://www.youtube.com/user/ChiliTomatoNoodle) and his [HW3D Engine](https://github.com/planetchili/hw3d);
* [Cherno](https://www.youtube.com/channel/UCQ-W1KE9EYfdxhL6S4twUNw) and his [Hazel Engine](https://github.com/TheCherno/Hazel/);
