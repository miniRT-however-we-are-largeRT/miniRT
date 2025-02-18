# MiniRT Project
## How To Use
1. image build
```bash
docker build -t minirt .
```
2. Host’s X server access rights
```bash
xhost +local:docker
```
3. Run container
```bash
docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix minirt
```
## Overview
The **MiniRT** project is part of the 42 curriculum, where the objective is to implement a ray tracing program. The goal is to render 3D scenes described in a configuration file using a ray tracing algorithm.

This project introduces students to the fundamentals of computer graphics, specifically focusing on the ray tracing technique, which simulates the behavior of light to generate realistic images.

> ### _ScreenShot!_
> <img width="1392" alt="raytracing" src="https://github.com/user-attachments/assets/48f05350-96b3-4123-b66b-308ae71d3d3b" />


---

## Features
- Render basic geometric shapes such as spheres, planes, and cylinders.
- Support for lighting effects including ambient, diffuse, and specular reflections.
- Multi-light source support (ambient light, point light).
- Parse and render scenes from a configuration file.
- Handle shadows and reflections for enhanced realism.

---

## Objectives
1. Understand the basics of ray tracing, including ray-object intersections, lighting models, and color rendering.
2. Develop a parser to read and interpret scene configuration files.
3. Build a minimal graphics engine that outputs images to the screen.
4. Gain hands-on experience with vector math, linear algebra, and light behavior in computer graphics.

---

## Getting Started

### Prerequisites
To run **MiniRT**, ensure you have the following:
- A Unix-based system (Linux or macOS)
- A compiler supporting C99 or later (e.g., GCC or Clang)
- `make` utility
- A basic understanding of vector mathematics

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/miniRT-however-we-are-largeRT/miniRT
   cd minirt
   ```
2. Build the project:
   ```bash
   make
   ```
3. Run the program with a scene file:
   ```bash
   ./minirt scenes/example.rt
   ```

### Example Scene File
Scene files describe the objects, lights, and camera in the 3D space. Here's an example:
```
A 0.2 255,255,255
C 0,0,-10 0,0,1 70
L 5,5,-10 1.0 255,255,255

sp 0,0,10 5 255,0,0
pl 0,-5,0 0,1,0 0,255,0
cy 2,0,10 0,1,0 3 10 0,0,255
```
- **A**: Ambient light [ratio] [color]
- **C**: Camera [position] [orientation] [FOV]
- **L**: Light source [position] [brightness] [color]
- **sp**: Sphere [position] [diameter] [color]
- **pl**: Plane [position] [normal vector] [color]
- **cy**: Cylinder [position] [orientation] [diameter] [height] [color]

---

## Controls
- **ESC or Ctrl + C**: Exit the program

---

## Project Structure
```
minirt/
├── src/              # Source files
├── include/          # Header files
├── scenes/           # Example scene files
├── lib/              # Libraries (if applicable)
├── Makefile          # Build script
└── README.md         # Project documentation
```

---

## Technical Details

### Ray Tracing Algorithm
1. **Ray Generation**: Cast rays from the camera's position through each pixel on the screen.
2. **Intersection Testing**: Check for intersections between the ray and scene objects (sphere, plane, cylinder).
3. **Shading**: Compute lighting effects based on light sources and object materials.
4. **Pixel Coloring**: Determine the final color of each pixel and render the image.

### Lighting Model
The project implements the **Phong Reflection Model**, which includes:
- **Ambient Lighting**: Uniform light applied to all objects.
- **Diffuse Reflection**: Light scattered in multiple directions based on surface orientation.
- **Specular Reflection**: Light reflected in a specific direction, creating highlights.

---

## Challenges
- Implementing precise mathematical calculations for ray-object intersections.
- Handling edge cases such as objects partially out of the camera's view.
- Optimizing the program for performance while maintaining accurate rendering.

---

## Roadmap
Potential future improvements:
- Implement multithreading to improve rendering speed.

---

## Acknowledgments
- The 42 Network for providing this challenging and educational project.
- Resources and tutorials on computer graphics and ray tracing.

---
