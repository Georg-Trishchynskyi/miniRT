# miniRT

Project for 42 Wolfsburg.

As it's said in the name it's a mini/basic ray-tracing using the CPU based on Blinn–Phong reflection model.
This project can handle several shapes such as spheres, planes, cylinders, triangles, and hyperboloids.
Support features like reflection, refraction, colored light, multithreading, textures, and bump textures.

## Examples

![image](https://user-images.githubusercontent.com/92743778/216372825-924ad3ad-cb01-4e7e-920f-80c003a38006.png)
![image](https://user-images.githubusercontent.com/92743778/216373019-5242a245-ac9d-454f-b23a-5862923cf531.png)
![image](https://user-images.githubusercontent.com/92743778/216373125-128df63f-3214-4f9a-8bd4-c7b5e7b62807.png)
![image](https://user-images.githubusercontent.com/92743778/216373160-c1fe6c6a-90b0-4f37-bb52-b0667a6afd58.png)
![image](https://user-images.githubusercontent.com/92743778/216373205-55125653-cbc2-4410-8dbc-13d35b8b636b.png)
![image](https://user-images.githubusercontent.com/92743778/216373251-9794210c-1d4d-48ab-b097-60c71b6647ee.png)

## Installation

   clone repo then change a directory and compile
 + `https://github.com/kraf24/miniRT.git`
 + `cd miniRT
 + `make`

## Usage
   When you run the program it must have two arguments, the first one is the program and the second one is a map file that should end with ".rt"
  
  `./miniRT scenes/<some_scene>.rt`

## Map Creation
  If you want to create your own map or change the existing one here is information about existing presets
   
   | Abbriviation | Name | Properties |
| :------------ |:---------------:| :----- |
| c | camera | Center, direction, fov |
| A | ambient light |  intensity, collor |
| l | light  |  position, intensity color |
| sp | sphere |  position, diameter, color, material |
| pl | plane |  position, surface normal, color, material |
| cy | cylinder |  position, tube axis direction, diameter, length, color, material |
| tr | trinagle |  point1, point2, point3, color, material |
| hy | hyperboloid |  origin point, axis orientation, semi-major axis parameteres, radius, color, material |

Materials are stored as numbers, here are explanation of what those numbers mean:

| Number | Type |
|:------| :--------|
| 1 | Regular surface |
| 2 | Reflective surface |
| 3 | Refractive (only with spheres) |
| 4 | Earth texture no bump (only with spheres) |
| 5 | Mirror |
| 6 | Space texture (only with spheres) |
| 7 | Checkered surface |
| 8 | Sun texture (only with spheres) |
| 9 | Moon texture no bump (only with spheres) |
| 10 | Mars texture no bump (only with spheres) |
| 11 | Mercury texture no bump (only with spheres) |
| 12 | Venus texture no bump (only with spheres) |
| 13 | Jupiter texture no bump (only with spheres) |
| 14 | Earth texture WITH bumps (only with spheres) |
