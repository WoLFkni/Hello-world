#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "field.h"
#include <ostream>

// Generate a random field
Field randomField(int size);

// The game engine
void play(std::ostream& os, int size);

#endif // ENGINE_H_INCLUDED
