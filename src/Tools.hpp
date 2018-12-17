#ifndef SANDAL2PP_TOOLS_KLEVH_HPP
#define SANDAL2PP_TOOLS_KLEVH_HPP

#include <exception>
#include <string>

namespace SANDAL2{
    using FLIP = SANDAL2_FLIP;
    
    struct Color{
	int r;
	int g;
	int b;
	int a;
	Color(int r =  0, int g = 0, int b = 0, int a = 0);
	Color(int color[4]);
    };
    
    struct Point{
	float x;
	float y;
	Point(float x = 0, float y = 0);
    };

    class OperationFailure : std::exception{
	std::string message_;

    public:
	OperationFailure(const char * message);
	~OperationFailure() throw(){}
	const char * what() const throw ();
    };
};

#endif
