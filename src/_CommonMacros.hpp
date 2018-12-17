#ifndef SANDAL2PP_COMMON_MACROS_KLEVH_H
#define SANDAL2PP_COMMON_MACROS_KLEVH_H

#define SANDAL2PP_GENERIC_SETTER(name, exceptionMessage, ...)	\
    if(name(self_, ##__VA_ARGS__)){				\
	throw SANDAL2::OperationFailure(exceptionMessage);	\
    }

#define SANDAL2PP_GENERIC_ACTION(method, ...)			\
    SANDAL2::Element * e = NULL;				\
    if(!getDataElement(self, (void**)&e) && e){			\
	e-> method(__VA_ARGS__);				\
    }

#endif
