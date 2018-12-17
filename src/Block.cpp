#include "Block.hpp"
#include "_CommonMacros.hpp"



// ---------------------------------------------------------
// SANDAL2::Block Constructor(s) / Destructor / operators
SANDAL2::Block::Block(Point position, Point dimension,
		      Color color,
		      int displayCode, int plan)
    :Element(createBlock(position.x, position.y,
			 position.x, position.y,
			 {0, 0, 0, 0}, displayCode, plan))
{
    setColor(color);
}
// ---------------------------------------------------------





// ---------------------------------------------------------
// SANDAL2::Block Getters
SANDAL2::Color SANDAL2::Block::getColor() const{
    int color[4] = {0};

    SANDAL2PP_GENERIC_SETTER(getColorElement,
			     "Failed to get the color",
			     color);

    return SANDAL2::Color(color);
}
// ---------------------------------------------------------





// ---------------------------------------------------------
// SANDAL2::Block Setters
void SANDAL2::Block::setColor(SANDAL2::Color color){
    int c[4] = {color.r, color.g, color.b, color.a};
    
    SANDAL2PP_GENERIC_SETTER(setColorElement,
			     "Failed to set the color",
			     c);
}
// ---------------------------------------------------------
