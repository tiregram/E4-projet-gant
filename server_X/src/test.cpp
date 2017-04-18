#include <string>
extern "C" {
#include <SDL/SDL.h>
}
#include <stdlib.h>
#include <iostream>
#include <memory>
#include "X/XDisplay.hpp"


// void paint(SDL_Surface *surface, int x, int y,
//            Uint8 red, Uint8 green, Uint8 blue) {
//   if(SDL_MUSTLOCK(surface)) {
//     // The surface must be locked to access surface->pixels
//     SDL_LockSurface(surface);
//   }
//   // This is the size of each pixel in bytes
//   int bytes_per_pixel = surface->format->BytesPerPixel;
//   // surface->pixels is a pointer into memory, it points at the first pixel in
//   // the surface which is at (0, 0).
//   // We create our own pointer which we are going to move around until we find
//   // the pixel we want to modify.
//   Uint8 *pixel;

//   // We start at (0, 0)
//   pixel = (Uint8*) surface->pixels;
//   // surface->pitch is the number of bytes between each row of pixels, we move
//   // our pointer forward in memory until we find the start of the row for y
//   pixel += y * surface->pitch;
//   // We move our pointer forward in memory unitl we find the pixel in this row
//   // for x
//   pixel += x * bytes_per_pixel;
//   // For the given red, green, and blue values we need to know the corresponding
//   // number to write into memory to make that color
//   Uint32 color = SDL_MapRGB(surface->format, red, green, blue);
//   // Figure out the integer type used to write the color into memory
//   if(sizeof(Uint8) == bytes_per_pixel) {
//     *pixel = color;
//   } else if(sizeof(Uint16) == bytes_per_pixel) {
//     Uint16 *pixel2 = (Uint16 *)pixel;
//     *pixel2 = color;
//   } else if(sizeof(Uint32) == bytes_per_pixel) {
//     Uint32 *pixel4 = (Uint32 *)pixel;
//     *pixel4 = color;
//   }
//   if(SDL_MUSTLOCK(surface)) {
//     // We're done with surface->pixels so unlock the surface
//     SDL_UnlockSurface(surface);
//   }
//   // Make our changes to surface memory visible on the screen
//   Sint32 rect_width = 1, rect_height = 1;

// }


int main(int argc, char *argv[])
{

  std::string name = "xvfb";
  std::string addr = ":8";
  std::shared_ptr<G::Display> di;

try {
  di = std::make_shared<G::XDisplay>(name,addr);
 } catch (std::logic_error err) {
  std::cout << err.what() << "\n";
 }


//   int return_code = SDL_Init(SDL_INIT_VIDEO);

//   if(return_code < 0) {
//     fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
//     exit(1);
//   }
//   atexit(SDL_Quit);

//   // Set the video mode we want
//   SDL_Surface *surface;
//   int width = 0; // 0 means any width
//   int height = 0; // 0 means any height
//   int bits_per_pixel = 0; // 0 means use the current bpp
//   Uint32 flags = SDL_RESIZABLE; // make a resizable window
//   surface = SDL_SetVideoMode(width, height, bits_per_pixel, flags);
//   if(NULL == surface) {
//     fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
//     exit(2);
//   }


//   // Main loop
//   int painting = 0; // variable to keep track of mouse-down state
//   Uint8 red, green, blue; // variables to keep track of our current color
//   // while(1)
//   //   di->draw(surface,1);
//   exit(0);
//   while(1) {
//     SDL_Event event;

//     // Wait for the user to do something
//     SDL_WaitEvent(&event);
    
//     // Act on the various event types
//     if(SDL_QUIT == event.type) { // the user wants to quit
//       exit(0);
//     } else if(SDL_VIDEORESIZE == event.type) { // our window was resized
//       // Update our surface with the new size
//       width = event.resize.w;
//       height = event.resize.h;
//       surface = SDL_SetVideoMode(width, height, bits_per_pixel, flags);
//       if(NULL == surface) {
//         fprintf(stderr, "Unable to resize video mode: %s\n", SDL_GetError());
//         exit(2);
//       }
//     } else if(SDL_MOUSEBUTTONDOWN == event.type) { // a button is being pressed

//     } else if(SDL_MOUSEMOTION == event.type) { // the mouse moved
//       if(painting) {
//         // Continue painting
//         paint(surface, event.motion.x, event.motion.y, red, green, blue);
//       }
//     } else if(SDL_MOUSEBUTTONUP == event.type) { // a button is being released
//       // Stop painting
//       painting = 0;
//     }
// }
//   return 0;
}



