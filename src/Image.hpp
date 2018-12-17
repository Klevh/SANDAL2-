#ifndef SANDAL2PP_IMAGE_KLEVH_HPP
#define SANDAL2PP_IMAGE_KLEVH_HPP

#include "_TextOrImage.hpp"

namespace SANDAL2{
    class Image : virtual public _TextOrImage{
    public:
	// Constructor(s) / Destructor / operators
	Image(const char * imagePath,
	      Point coordinate = Point(), Point dimension = Point(1, 1),
	      int displayCode = 0, int plan = 0);

	// Setters
	void setLifeSpanSpriteAnimation(int code, int codeSprite, unsigned lifespan);
	void setWaySpriteAnimation(int code, int way);
	void setAnimation(int code);
	void setImage(const char * image);
	void setImageTexture(SDL_Texture * image);
	
	// other methods
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
