#include "optional_c.h"
#include "stdio.h"

struct foo
{
    int alpha;
    int beta;
};

// Simulate some resource (serial port, etc)
typedef void resource_handle_t;

DefineOptional(int);
DefineNamedOptional(struct foo, foo);
DefineNamedOptional(int*, intptr);
DefineNamedOptional(resource_handle_t*, serial_ptr);

// Getter function for simulated resource
Optional(serial_ptr) getSerialHandle( uint8_t port )
{
    Optional(serial_ptr) handle = None(serial_ptr);
    if(false)
    {
        //handle = Some(&serial_port[port]);
    }
    return handle;
}

// Test Driver
int main(void)
{
    Optional(foo)       myOpt;
    Optional(intptr)    myOptPtr;
    Optional(int)       myOptInt;

    struct foo  bap;

    IfUnwrap(myOpt, bap)
    {
        // Nothing
    }

    (void)myOpt;
    (void)myOptPtr;
    (void)myOptInt;
    (void)bap;
    printf("bar\n");


    // Using a non-nullable pointer
    Optional(serial_ptr)    opt_serial_handle;
    resource_handle_t*      never_null_handle;

    opt_serial_handle = getSerialHandle( 2 );
    IfUnwrap(opt_serial_handle, never_null_handle)
    {
        printf("Writing...\n");
        //never_null_handle->write(STRING_CONTENTS);
        (void)never_null_handle;
    }
    else
    {
        printf("Failed to obtain handle!\n");
    }

    return 0;
}
