/*****************************************************************************
 * Optional in C
 *
 * An implementation of Rust's Optional type in C
 *
 * Dont use this in production code. Seriously.
 *
 * MIT License, See LICENSE for more details
 *
 * 2015 - James Munns
 *****************************************************************************/

#ifndef _OPTIONAL_C_H
#define _OPTIONAL_C_H

// Compiler switch to allow user-defined types (embedded compilers, etc.)
#ifndef OPTIONAL_NO_STD_INCLUDES
    #include "stdbool.h"
    #include "stdint.h"
#endif

// Error Code Definitions
typedef int8_t optional_error_code;
static const optional_error_code UNKNOWN_ERROR =   -1;
static const optional_error_code SUCCESS       =    0;

// Optional Header Definitions
typedef struct
{
    bool                    valid;
    optional_error_code     code;
} optional_header;

// This is a type
#define Optional(_optional_type) optional_##_optional_type##_type

// These are constructors
#define Some(_optional_type, _optional_parameter)   \
    ((Optional(_optional_type))                     \
        {   .header.valid = true,                   \
            .header.code  = SUCCESS,                \
            .contents     = _optional_parameter     \
        } )
// End Some()

#define None(_optional_type)                \
    ((Optional(_optional_type))             \
        {   .header.valid = false,          \
            .header.code  = UNKNOWN_ERROR   \
        } )
// End None()

// This creates an optional type named the same as the type
#define DefineOptional(_optional_type)  \
    typedef struct                      \
    {                                   \
        optional_header header;         \
        _optional_type  contents;       \
    }Optional(_optional_type)
// End DefineOptional

// This creates an optional type with a defined name.
// Useful with structs, enums, unions, and pointers that havent already been typedef'd
#define DefineNamedOptional(_optional_type, _optional_name) \
    typedef _optional_type _optional_name;                  \
    DefineOptional(_optional_name)
// End DefineNamedOptional

//// Back to magic prototypes

// bool IsSome(Optional_type);
#define IsSome(_optional_object) ((_optional_object).header.valid)

// bool IsSome(Optional_type);
#define IsNone(_optional_object) (!IsSome(_optional_object))

// void Unwrap(Optional_type, real_type);
#define Unwrap(_optional_object, _destination_object)           \
    ( IsSome(_optional_object) ?                                \
        (_destination_object=_optional_object.contents, true)   \
      : (false)                                                 \
    )
// End Unwrap

// IfUnwrap(){}
#define IfUnwrap(_optional_object, _destination_object)         \
    if Unwrap(_optional_object, _destination_object )

#endif // _OPTIONAL_C_H
