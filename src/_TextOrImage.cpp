#include "_TextOrImage.hpp"

#include "_CommonTools.hpp"




// ---------------------------------------------------------
// SANDAL2::_TextOrImage Constructor(s) / Destructor / operators
SANDAL2::_TextOrImage::_TextOrImage(::Element * self)
    :SANDAL2::Element(self)
{}
// ---------------------------------------------------------





// ---------------------------------------------------------
// SANDAL2::_TextOrImage Getters
float SANDAL2::_TextOrImage::getAngle() const{
    float a = 0;

    SANDAL2PP_GENERIC_SETTER(getAngleElement,
			     "Failed to get angle",
			     &a);

    return a;
}

float SANDAL2::_TextOrImage::getRotationSpeed() const{
    float rs = 0;

    SANDAL2PP_GENERIC_SETTER(getRotationSpeedElement,
			     "Failed to get rotation speed",
			     &rs);

    return rs;
}

SANDAL2::FLIP SANDAL2::_TextOrImage::getFlipState() const{
    SANDAL2::FLIP f;

    SANDAL2PP_GENERIC_SETTER(getFlipStateElement,
			     "Failed to get flip state",
			     &f);

    return f;
}
// ---------------------------------------------------------





// ---------------------------------------------------------
// SANDAL2::_TextOrImage Setters
void SANDAL2::_TextOrImage::setRotationSpeed(float rotationSpeed){
    SANDAL2PP_GENERIC_SETTER(setRotationSpeedElement,
			     "Failed to set rotation speed",
			     rotationSpeed);
}

void SANDAL2::_TextOrImage::setAngle(float angle){
    SANDAL2PP_GENERIC_SETTER(setAngleElement,
			     "Failed to set angle",
			     angle);
}

void SANDAL2::_TextOrImage::setRotationPoint(Point p){
    SANDAL2PP_GENERIC_SETTER(setRotationPoint,
			     "Failed to set rotation point",
			     p.x, p.y);
}

void SANDAL2::_TextOrImage::setFlipState(SANDAL2::FLIP flip){
    SANDAL2PP_GENERIC_SETTER(setFlipStateElement,
			     "Failed to set flip state",
			     flip);
}
// ---------------------------------------------------------






// ---------------------------------------------------------
// SANDAL2::_TextOrImage Other methods
void SANDAL2::_TextOrImage::addClickable(Clickable * hb, bool blocking){
    SANDAL2PP_GENERIC_SETTER(addClickableElement,
			     "Failed to add a clickable",
			     hb, (int)blocking);
}

void SANDAL2::_TextOrImage::addRotationSpeed(float rotationSpee){
    SANDAL2PP_GENERIC_SETTER(addRotationSpeedElement,
			     "Failed to add a rotation speed",
			     rotationSpeed);
}

void SANDAL2::_TextOrImage::addAngle(float angle){
    SANDAL2PP_GENERIC_SETTER(addAngleElement,
			     "Failed to add angle",
			     angle);
}
// ---------------------------------------------------------
