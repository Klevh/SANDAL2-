#ifndef SANDAL2PP_ELEMENT_KLEVH_H
#define SANDAL2PP_ELEMENT_KLEVH_H

#include <SANDAL2/Element.h>

#include <cstdlib>

#include "Tools.hpp"

namespace SANDAL2{    
    // Classe parente element
    // deux enfants (avec / sans image)
    // 7 enfants (chaque element), ou moin que 7
    class Element{
	void      * data_;
	void     (* freeData_)(void *);

    protected:
	bool        isAllocated;
	::Element * self_;

    public:
	// Constructor(s) / Destructor / operators
	Element(::Element * self);
	virtual ~Element();
	void * operator new(size_t s);
	
	// Getters
	bool isDisplaied() const;
        float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	void * getData() const;
	bool isSelected() const;
	// text
	int getTextStyle() const;
	const char * getTextElement() const;

	// setters
	void setX(float x);
	void setY(float y);
	void setWidth(float width);
	void setHeight(float height);
	void setIsDisplay(int displayCode, bool isDisplaied);
	void setPlan(int displayCode, int plan);
	void setData(void * d);
	void setFreeData(void (*freeData)(void *));
	// text
	void setTextSize(float textSize);
	void setFont(const char * font);
	void setTextColor(Color r);
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
