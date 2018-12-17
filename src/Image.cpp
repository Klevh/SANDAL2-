#include "Image.hpp"

#include "_CommonTools.hpp"




// ---------------------------------------------------------
// SANDAL2::Image Constructor(s) / Destructor / operators
SANDAL2::Image::Image(const char * imagePath,
		      Point coordinate, Point dimension,
		      int displayCode, int plan)
    :SANDAL2::_TextOrImage(createImage(coordinate.x, coordinate.y, dimension.x, dimension.y, imagePath, displayCode, plan))
{}
// ---------------------------------------------------------





// ---------------------------------------------------------
// SANDAL2::Image Setters
void SANDAL2::Image::setLifeSpanSpriteAnimation(int code, int codeSprite, unsigned lifespan){
    SANDAL2PP_GENERIC_SETTER(setLifeSpanSpriteAnimationElement,
			     "Failed to set life span sprite animation",
			     code, codeSprite, lifespan);
}

void SANDAL2::Image::setWaySpriteAnimation(int code, int way){
    SANDAL2PP_GENERIC_SETTER(setWaySpriteAnimationElement,
			     "Failed to set way of sprite animation",
			     code, way);
}

void SANDAL2::Image::setAnimation(int code){
    SANDAL2PP_GENERIC_SETTER(setAnimationElement,
			     "Failed to set animation",
			     code);
}

void SANDAL2::Image::setImage(const char * image){
    SANDAL2PP_GENERIC_SETTER(setImageElement,
			     "Failed to set image",
			     image);
}

void SANDAL2::Image::setImageTexture(SDL_Texture * image){
    SANDAL2PP_GENERIC_SETTER(setImageTextureElement,
			     "Failed to set image texture",
			     image);
}
// ---------------------------------------------------------






// ---------------------------------------------------------
// SANDAL2::Image Other methods
void SANDAL2::Image::addAnimation(int code){
    SANDAL2PP_GENERIC_SETTER(addAnimationElement,
			     "Failed to add an animation",
			     code);
}

void SANDAL2::Image::delAnimation(int code){
    SANDAL2PP_GENERIC_SETTER(delAnimationElement,
			     "Failed to remove an animation",
			     code);
}

void SANDAL2::Image::addSpriteAnimation(int code, int codeSprite){
    SANDAL2PP_GENERIC_SETTER(addSpriteAnimationElement,
			     "Failed to add a sprite",
			     code, codeSprite);
}

void SANDAL2::Image::delSpriteAnimation(int code, int codeSprite){
    SANDAL2PP_GENERIC_SETTER(delSpriteAnimationElement,
			     "Failed to remove a sprite",
			     code, codeSprite);
}

void SANDAL2::Image::nextSprite(){
    SANDAL2PP_GENERIC_SETTER(nextSpriteElement,
			     "Failed to go to next sprite");
}

void SANDAL2::Image::previousSprite(){
    SANDAL2PP_GENERIC_SETTER(previousSpriteElement,
			     "Failed to go to previous sprite");
}

void SANDAL2::Image::nextAnimation(){
    SANDAL2PP_GENERIC_SETTER(nextAnimationElement,
			     "Failed to go to next animation");
}

void SANDAL2::Image::previousAnimation(){
    SANDAL2PP_GENERIC_SETTER(previousAnimationElement,
			     "Failed to go to previous animation");
}
// ---------------------------------------------------------


