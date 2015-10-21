# optional_c
## Implementation of Rust's Optional Type in C

This is a terrible proof of concept, attempting to bring the functionality of Rust's Optional Type (among many other languages) to C, through the magic of macros.

You can use it with standard type, your own types, structure definitions, the usages are limitless! Overhead is limited to two bytes (plus whatever your compiler packs structures to), and a little bit of sanity.

I even threw some Error Code possiblilties, but no behavior on that yet.

I accept pull requests.

# Usage
```C
#include "optional_c.h"

// Define your optional type
DefineOptional(float);

// Make a function that returns a float
Optional(float) goodExample( void )
{
    return Some(float, 1.0f);
}

// Make a function that doesnt (really) return a float
Optional(float) badExample( void )
{
    return None(float);
}

void testFunction(void)
{
    Optional(float) myOptionalFloat;
    float           actualFloat;

    myOptionalFloat = goodExample();
    if(Unwrap(myOptionalFloat, actualFloat))
    {
        printf("%.1f\n", actualFloat); // Prints "1.0"
    }

    myOptionalFloat = badExample();
    if(IsNone(myOptionalFloat))
    {
        printf("Guess that didn't go well...\n"); // It didnt go well!
    }
}
```

# Terrible things done by this implementation
Included but not limited to:

* Use of the `##` macro concatenator
* Use of the `,` operator
