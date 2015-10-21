#include "optional_c.h"
#include "stdio.h"

DefineOptional(float);

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
    Optional(float) myOptionalFloat;

    if(true)
    {
        myOptionalFloat = Some(float, 2.0f);
    }

    return myOptionalFloat;
}

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


////////////

//optionalFloat getSuccessful1(void);
//optionalFloat getFailure(void);
//
//DefineOptional(float)
//
//int main(void)
//{
//    Optional(float) myOptFloat;
//    float           myFloat;
//
//    myOptFloat = getFailure();
//    if(IsSome(myOptFloat))
//    {
//        // Should never happen
//    }
//
//    myOptFloat = getSuccessful1();
//    if(IsSome(myOptFloat))
//    {
//        // Should Happen
//        // Use like myOptFloat.contents
//    }
//
//    myOptFloat = getSuccessful2();
//    if(Unwrap(myOptFloat, myFloat))
//    {
//        // you can now use myFloat
//        // Use like myFloat
//    }
//}
//

