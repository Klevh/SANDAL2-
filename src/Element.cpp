#include "Element.hpp"
#include "_CommonMacros.hpp"



// ---------------------------------------------------------
// SANDAL2::Element Constructor(s) / Destructor / operators
SANDAL2::Element::Element(::Element * self)
    :self_(self)
    ,data_(NULL)
    ,freeData_(NULL)
    ,isAllocated(self != NULL)
{
    setDataElement(self, this);
    setFreeDataElement(self, true_freeData);
}

SANDAL2::Element::~Element(){
    if(data_ && freeData_){
	freeData_(data_);
    }
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

SANDAL2::FLIP SANDAL2::Element::getFlipState() const{
    SANDAL2::FLIP flip;

    SANDAL2PP_GENERIC_SETTER(getFlipStateElement,
			     "Failed to get Flip state",
			     &flip);

    return flip;
}

float SANDAL2::Element::getAngle() const{
    float angle = 0;

    SANDAL2PP_GENERIC_SETTER(getAngleElement,
			     "Failed to get angle",
			     &angle);

    return angle;
}

SANDAL2::Point SANDAL2::Element::getRotationPoint() const{
    float x, y;

    SANDAL2PP_GENERIC_SETTER(getRotationPointElement,
			     "Failed to get rotation point",
			     &x, &y);

    return SANDAL2::Point(x, y);
}

float SANDAL2::Element::getRotationSpeed() const{
    float rotSpeed = 0;

    SANDAL2PP_GENERIC_SETTER(getRotationSpeedElement,
			     "Failed to get rotation speed",
			     &rotSpeed);

    return rotSpeed;
}

int SANDAL2::Element::getTextStyle() const{
    int angle = 0;

    SANDAL2PP_GENERIC_SETTER(getAngleElement,
			     "Failed to get angle",
			     &angle);

    return angle;
}

std::string SANDAL2::Element::getText() const{
    char * s;

    SANDAL2PP_GENERIC_SETTER(getTextElement,
			     "Failed to get text of element",
			     &s);

    std::string result(s);

    free(s);

    return result;
}

SANDAL2::Color SANDAL2::Element::getColor() const{
    int color[4];

    SANDAL2PP_GENERIC_SETTER(getColorElement,
			     "Failed to get color of element",
			     color);

    return SANDAL2::Color(color);
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

void SANDAL2::Element::setRotationSpeed(float speed);
void SANDAL2::Element::setAngle(float angle);
void SANDAL2::Element::setRotationPoint(const SANDAL2::Point& p);
void SANDAL2::Element::setAnimation(int animationCode);
void SANDAL2::Element::setSpriteAnimation(int spriteCode);
void SANDAL2::Element::setFlipState(FLIP state);
void SANDAL2::Element::setColor(const SANDAL2::Color& color);
void SANDAL2::Element::setImage(const char * imagePath);
void SANDAL2::Element::setImageTexture(SDL_Texture * image);
void SANDAL2::Element::setTextSize(float textSize);
void SANDAL2::Element::setFont(const char * font);
void SANDAL2::Element::setTextColor(const SANDAL2::Color& r);
void SANDAL2::Element::setTextQuality(int quality);
void SANDAL2::Element::setText(const char * text);
void SANDAL2::Element::setTextStyle(int style);
void SANDAL2::Element::setSize(int min, int max);
void SANDAL2::Element::setScripted(bool isScripted);
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

// void SANDAL2::Element::addClickable(SANDAL2::Clickable& c);
// void SANDAL2::Element::addClickable(SANDAL2::Clickable * c);
// void SANDAL2::Element::addAnimation(SANDAL2::Animation& a);
// void SANDAL2::Element::addAnimation(SANDAL2::Animation * a);
void SANDAL2::Element::delAnimation(int animationCode);
void SANDAL2::Element::addRotationSpeed(float speed);
void SANDAL2::Element::addAngle(float angle);
void SANDAL2::Element::nextSprit();
void SANDAL2::Element::previousSprit();
void SANDAL2::Element::nextAnimation();
void SANDAL2::Element::previousAnimation();
void SANDAL2::Element::addChar(char c);
void SANDAL2::Element::delChar();
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
