#include "Element.hpp"
#include "_CommonMacros.hpp"



// ---------------------------------------------------------
// SANDAL2::Element Constructor(s) / Destructor / operators
SANDAL2::Element::Element(::Element * self)
    :self_(self)
    ,data_(NULL)
    ,freeData_(NULL)
    ,isAllocated(false)
{
    setDataElement(self, this);
    setFreeDataElement(self, true_freeData);
}

SANDAL2::Element::~Element(){
    if(data_ && freeData_){
	freeData_(data_);
    }
}

/*virtual*/ void * SANDAL2::Block::operator new(size_t s){
    SANDAL2::Element * e = malloc(s);
    e->isAllocated = true;
    return (void *)e;
}
// ---------------------------------------------------------





// ---------------------------------------------------------
// SANDAL2::Element Getters
bool SANDAL2::Element::isDisplaied() const{
    return isDisplaiedElement(self_);
}

float SANDAL2::Element::getX() const{
    float x = 0;

    SANDAL2PP_GENERIC_SETTER(getCoordXElement,
		       "Failed to get x coordinate",
		       &x);

    return x;
}

float SANDAL2::Element::getY() const{
    float y = 0;

    SANDAL2PP_GENERIC_SETTER(getCoordYElement,
		       "Failed to get y coordinate",
		       &y);

    return y;
}

float SANDAL2::Element::getWidth() const{
    float w = 0;

    SANDAL2PP_GENERIC_SETTER(getWidthElement,
			     "Failed to get width",
			     &w);

    return w;
}

float SANDAL2::Element::getHeight() const{
    float h = 0;

    SANDAL2PP_GENERIC_SETTER(getHeightElement,
			     "Failed to get height",
			     &h);

    return h;
}

void * SANDAL2::Element::getData() const{
    return data_;
}

bool SANDAL2::Element::isSelected() const{
    int selected = false;

    SANDAL2PP_GENERIC_SETTER(isSelectedElement,
			     "Failed to get isSelected",
			     &selected);

    return selected;
}
// ---------------------------------------------------------





// ---------------------------------------------------------
// SANDAL2::Element Setters
void SANDAL2::Element::setX(float x){
    SANDAL2PP_GENERIC_SETTER(setCoordXElement,
		   "Failed to set X coordinate",
		   x);
}

void SANDAL2::Element::setY(float y){
    SANDAL2PP_GENERIC_SETTER(setCoordYElement,
		   "Failed to set Y coordinate",
		   y);
}

void SANDAL2::Element::setWidth(float width){
    SANDAL2PP_GENERIC_SETTER(setWidthElement,
		   "Failed to set width",
		   width);
}

void SANDAL2::Element::setHeight(float height){
    SANDAL2PP_GENERIC_SETTER(setHeightElement,
		   "Failed to set height",
		   height);
}

void SANDAL2::Element::setIsDisplay(int displayCode, bool isDisplaied){
    SANDAL2PP_GENERIC_SETTER(setDisplayCodeElement,
		   "Failed to set height",
		   displayCode, (int)isDisplaied);
}

void SANDAL2::Element::setPlan(int displayCode, int plan){
    SANDAL2PP_GENERIC_SETTER(setPlanElement,
		   "Failed to set the plan",
		   displayCode, plan);
}

void SANDAL2::Element::setData(void * d){
    data_ = d;
}

void SANDAL2::Element::setFreeData(void (*freeData)(void *)){
    freeData_ = freeData;
}
// ---------------------------------------------------------






// ---------------------------------------------------------
// SANDAL2::Element Other methods
void SANDAL2::Element::move(float x, float y){
    SANDAL2PP_GENERIC_SETTER(moveElement,
			     "Failed to move",
			     x, y);
}

void SANDAL2::Element::addDisplayCode(int displayCode, int plan){
    SANDAL2PP_GENERIC_SETTER(addDisplayCodeElement,
			     "Failed to add display code",
			     displayCode, plan);
}

void SANDAL2::Element::delDisplayCode(int displayCode){
    SANDAL2PP_GENERIC_SETTER(delDisplayCodeElement,
			     "Failed to delete display code",
			     displayCode);
}

void SANDAL2::Element::addSon(Element * e){
    SANDAL2PP_GENERIC_SETTER(addElementToElement,
			     "Failed to add a son",
			     e ? e->self_ : nullptr);
}

void SANDAL2::Element::addSon(Element& e){
    addSon(&e);
}

void SANDAL2::Element::delSon(Element * e){
    SANDAL2PP_GENERIC_SETTER(delElementToElement,
			     "Failed to remove a son",
			     e ? e->self_ : nullptr);
}

void SANDAL2::Element::delSon(Element& e){
    delSon(&e);
}

void SANDAL2::Element::clearSons(){
    SANDAL2PP_GENERIC_SETTER(clearElementToElement,
			     "Failed to remove all sons");
}
// ---------------------------------------------------------







// ---------------------------------------------------------
// SANDAL2::Element  methods (to be redefined by user)
/*virtual*/ void SANDAL2::Element::action(){}
/*virtual*/ void SANDAL2::Element::keyPressed(SDL_Keycode c){}
/*virtual*/ void SANDAL2::Element::keyReleased(SDL_Keycode c){}
/*virtual*/ void SANDAL2::Element::onClick(int button){}
/*virtual*/ void SANDAL2::Element::unClick(int button){}
/*virtual*/ void SANDAL2::Element::onMouseMotion(){}
/*virtual*/ void SANDAL2::Element::unMouseMotion(){}
/*virtual*/ void SANDAL2::Element::unSelect(){}
/*virtual*/ void SANDAL2::Element::endSprite(int currentCode){}
// ---------------------------------------------------------







// ---------------------------------------------------------
// SANDAL2::Element  static methods (not to be touch by user)

/*static*/ void SANDAL2::Element::true_action(::Element * self){
    SANDAL2PP_GENERIC_ACTION(action);
}

/*static*/ void SANDAL2::Element::true_keyPressed(::Element * self, SDL_Keycode c){
    SANDAL2PP_GENERIC_ACTION(keyPressed, c);
}

/*static*/ void SANDAL2::Element::true_keyReleased(::Element * self, SDL_Keycode c){
    SANDAL2PP_GENERIC_ACTION(keyReleased, c);
}

/*static*/ void SANDAL2::Element::true_onClick(::Element * self, int button){
    SANDAL2PP_GENERIC_ACTION(onClick, button);
}

/*static*/ void SANDAL2::Element::true_unClick(::Element * self, int button){
    SANDAL2PP_GENERIC_ACTION(unClick, button);
}

/*static*/ void SANDAL2::Element::true_onMouseMotion(::Element * self){
    SANDAL2PP_GENERIC_ACTION(onMouseMotion);
}

/*static*/ void SANDAL2::Element::true_unMouseMotion(::Element * self){
    SANDAL2PP_GENERIC_ACTION(unMouseMotion);
}

/*static*/ void SANDAL2::Element::true_unSelect(::Element * self){
    SANDAL2PP_GENERIC_ACTION(unSelect);
}

/*static*/ void SANDAL2::Element::true_endSprite(::Element * self, int currentCode){
    SANDAL2PP_GENERIC_ACTION(endSprite, currentCode);
}

/*static*/ void SANDAL2::Element::true_freeData(void * self){
    SANDAL2::Element * e = static_cast<SANDAL2::Element*>(self);

    if(e && e->isAllocated){
	delete e;
    }
}
// ---------------------------------------------------------
