#ifndef SANDAL2PP_BLOCK_KLEVH_H
#define SANDAL2PP_BLOCK_KLEVH_H

#include "Element.hpp"
#include "Tools.hpp"

namespace SANDAL2{
    class Block : virtual public Element{
    protected:
	Block(::Element * self);

    public:
	// Constructor(s) / Destructor / operators
	Block(Point position = Point(), Point dimension = Point(1, 1),
	      Color color = Color(),
	      int displayCode = 0, int plan = 0);

	// Getters
	Color getColor() const;
	
	// setters
	void setColor(Color color);
    };
};

#endif
