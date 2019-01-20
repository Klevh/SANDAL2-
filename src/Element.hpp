#ifndef SANDAL2PP_ELEMENT_KLEVH_H
#define SANDAL2PP_ELEMENT_KLEVH_H

#include <SANDAL2/Element.h>

#include <cstdlib>

#include <string>

#include "Tools.hpp"

/* TODO:
     Iterator on this element
     Iterator on all elements of a display code
     class Animation
     class Clickable
     all sub classes of Element (block, text, ...)
 */

namespace SANDAL2{
    class Element{
	void      * data_;
	void     (* freeData_)(void *);

    protected:
	bool        isAllocated;
	::Element * self_;

    public:
	// Constructor(s) / Destructor / operators
	Element(::Element * self);
	virtual ~Element() = 0;
	
	// Getters
	bool isDisplaied() const;
        float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	void * getData() const;
	bool isSelected() const;
	// image
	FLIP getFlipState() const;
	float getAngle() const;
        Point getRotationPoint() const;
	float getRotationSpeed() const;
	// text
	int getTextStyle() const;
	std::string getText() const;
	// block
	Color getColor() const;

	// setters
	void setX(float x);
	void setY(float y);
	void setWidth(float width);
	void setHeight(float height);
	void setIsDisplay(int displayCode, bool isDisplaied);
	void setPlan(int displayCode, int plan);
	void setData(void * d);
	void setFreeData(void (*freeData)(void *));
	void setRotationSpeed(float speed);
	void setAngle(float angle);
	void setRotationPoint(const Point& p);
	void setAnimation(int animationCode);
	void setSpriteAnimation(int spriteCode);
	void setFlipState(FLIP state);
	// block
	void setColor(const Color& color);
	// Image
	void setImage(const char * imagePath);
	void setImageTexture(SDL_Texture * image);
	// text
	void setTextSize(float textSize);
	void setFont(const char * font);
	void setTextColor(const Color& r);
	void setTextQuality(int quality);
	void setText(const char * text);
	void setTextStyle(int style);
	// entry
	void setSize(int min, int max);
	void setScripted(bool isScripted);

	// other methods
	void move(float x, float y);
	void addDisplayCode(int displayCode, int plan);
	void delDisplayCode(int displayCode);
	void addSon(Element * e);
	void addSon(Element& e);
	void delSon(Element * e);
	void delSon(Element& e);
	void clearSons();
	// void addClickable(Clickable& c);
	// void addClickable(Clickable * c);
	// void addAnimation(Animation& a);
	// void addAnimation(Animation * a);
	void delAnimation(int animationCode);
	void addRotationSpeed(float speed);
	void addAngle(float angle);
	void nextSprit();
	void previousSprit();
	void nextAnimation();
	void previousAnimation();
	// entry
	void addChar(char c);
	void delChar();

	// methods (to be redefined by user)
	virtual void action();
	virtual void keyPressed(SDL_Keycode c);
	virtual void keyReleased(SDL_Keycode c);
	virtual void onClick(int button);
	virtual void unClick(int button);
	virtual void onMouseMotion();
	virtual void unMouseMotion();
	virtual void unSelect();
	virtual void endSprite(int currentCode);

    private:
	// static methods (not to be touch by user)
	static void true_action(::Element * self);
	static void true_keyPressed(::Element * self, SDL_Keycode c);
	static void true_keyReleased(::Element * self, SDL_Keycode c);
	static void true_onClick(::Element * self, int button);
	static void true_unClick(::Element * self, int button);
	static void true_onMouseMotion(::Element * self);
	static void true_unMouseMotion(::Element * self);
	static void true_unSelect(::Element * self);
	static void true_endSprite(::Element * self, int currentCode);
	static void true_freeData(void * self);
    };
};

#endif
