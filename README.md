# fdf_42 #

__*This is the fdf project from the 42 school. This project is about creating a simplified 3D graphic representation of a relief landscape.*__

## Usage

Compile using the command: `make`\
Then run the program with the command: `./fdf test_maps/the_map_you_want.fdf`

## Projections

Two types of projection are implemented:
* Isometric projection
* Cabinet projection

However, using the rotation options you can basically achieve any type of 3D projection.

## Options

The following options are available:
* Switch projection
* Rotations (on the X, Y or Z axis, or all three at the same time)
* Zoom in/out
* Color change (6 colors are available, as well as a cartographic mode)
* Center the object
* Move the camera up/down or left/right
* Reset the current projection

![img1](https://user-images.githubusercontent.com/67087093/98942971-1c914c00-24ef-11eb-83c5-428b128954b0.png)

![img2](https://user-images.githubusercontent.com/67087093/98943299-90cbef80-24ef-11eb-9645-4d2e72cf1ec9.png)

![img3](https://user-images.githubusercontent.com/67087093/98943334-9de8de80-24ef-11eb-9189-698987d40433.gif)

## Comptability

This project is based on a grapical library named "minilibx" provided by 42.\
\
This repository includes the minilibx version which is compatible with MacOS. This program should then run on MacOS without any problem.\
However this program won't work on Linux-based systems, since another version of the minilibx (which is not included here) is needed.
