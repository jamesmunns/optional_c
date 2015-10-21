#include "optional_c.h"
#include "stdio.h"

// You must first define the Optional Type
DefineOptional(float);

// Here are some functions to simulate real behavior
Optional(float) getFailure(void)
{
    return None(float);
}
Optional(float) getSuccessful1(void)
{
    return Some(float, 1.0f);
}
Optional(float) getSuccessful2(void)
{
    Optional(float) myOptionalFloat = {{0}};

    if(true)
    {
        myOptionalFloat = Some(float, 2.0f);
    }

    return myOptionalFloat;
}

// Test Driver
int main(void)
{
    Optional(float) myOpt = {{0}};
    float myFloat = 0.0f;

    // Optional checks

    if(IsSome(myOpt))
    {
        printf("Error!\n");
    }
    else
    {
        printf("Check!\n");
    }

    // None Checks

    myOpt = None(float);

    if(IsNone(myOpt))
    {
        printf("Check!\n");
    }
    else
    {
        printf("Error!\n");
    }

    // Some Checks

    myOpt = Some(float, 2.0f);

    if(IsSome(myOpt))
    {
        printf("Check!\n");
    }
    else
    {
        printf("Error!\n");
    }

    // Unwrap Checks

    if(Unwrap(myOpt, myFloat))
    {
        printf("2.0? %f\n", myFloat);
    }
    else
    {
        printf("Error!\n");
    }

    myOpt = None(float);

    if(Unwrap(myOpt, myFloat))
    {
        printf("Error!\n");
    }
    else
    {
        printf("Check!\n");
    }

    // Function checks
    myOpt = getFailure();
    if(Unwrap(myOpt, myFloat))
    {
        printf("Error!\n");
    }
    else
    {
        printf("Check!\n");
    }

    myOpt = getSuccessful1();
    if(Unwrap(myOpt, myFloat))
    {
        printf("1.0? %f\n", myFloat);
    }
    else
    {
        printf("Error!\n");
    }

    myOpt = getSuccessful2();
    if(Unwrap(myOpt, myFloat))
    {
        printf("2.0? %f\n", myFloat);
    }
    else
    {
        printf("Error!\n");
    }


    printf("foo\n");
    return 0;
}
