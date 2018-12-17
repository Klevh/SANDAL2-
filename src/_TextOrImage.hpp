#îfndef SANDAL2PP_TEXT_OR_IMAGE_HPP
#define SANDAL2PP_TEXT_OR_IMAGE_HPP

#include "Element.hpp"

namespace SANDAL2{
    class TextOrImage : virtual public Element{
    public:
	// Constructor(s) / Destructor / operators
	TextOrImage(::Element * self);
	
	// Getters
	float getAngle() const;
	float getRotationSpeed() const;
	SANDAL2_FLIP getFlipStateElement() const;
	
	// setters
	void setRotationSpeed(float rotationSpeed);
	void setAngle(float angle);
	void setRotationPoint(Point p);
	void setLifeSpanSpriteAnimation(int code, int codeSprite, unsigned lifespan);
	void setWaySpriteAnimation(int code, int way);
	void setAnimation(int code);
	void setFlipState(SANDAL2_FLIP flip);
	
	// other methods
	void addClickable(Clickable * hb, bool blocking);
	void addRotationSpeed(float rotationSpeed);
	void addAngle(float angle);
	void addAnimation(int code);
	void delAnimation(int code);
	void addSpriteAnimation(int code, int codeSprite);
	void delSpriteAnimation(int code, int codeSprite);
	void nextSprite();
	void previousSprite();
	void nextAnimation();
	void previousAnimation();
    };
};

#endif
