#îfndef SANDAL2PP_TEXT_OR_IMAGE_KLEVH_HPP
#define SANDAL2PP_TEXT_OR_IMAGE_KLEVH_HPP

#include "Element.hpp"

namespace SANDAL2{
    class _TextOrImage : virtual public Element{
    private:
	_TextOrImage();
	
    protected:
	// Constructor(s) / Destructor / operators
	_TextOrImage(::Element * self);
    
    public:
	
	// Getters
	float getAngle() const;
	float getRotationSpeed() const;
	FLIP getFlipState() const;
	
	// setters
	void setRotationSpeed(float rotationSpeed);
	void setAngle(float angle);
	void setRotationPoint(Point p);
	void setFlipState(FLIP flip);
	
	// other methods
	void addClickable(Clickable * hb, bool blocking);
	void addRotationSpeed(float rotationSpeed);
	void addAngle(float angle);
    };
};

#endif
