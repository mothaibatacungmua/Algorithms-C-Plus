/*
 * type-parse.hpp
 *
 *  Created on: Apr 17, 2016
 *      Author: asm
 */

#ifndef TYPE_PARSE_HPP_
#define TYPE_PARSE_HPP_

#include <string.h>
#include <string>
/*
* http://stackoverflow.com/questions/1055452/c-get-name-of-type-in-template
*/

template<typename T>
struct TypeParseTraits;

#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
        {static const char* name;}; const char* TypeParseTraits<X>::name = #X

#define COMPARE_TYPE(A,B) (strcmp(TypeParseTraits<A>::name, B) == 0)

namespace Utils{
    template<typename T>
    std::string ToString(T a);
}
#endif /* TYPE_PARSE_HPP_ */
