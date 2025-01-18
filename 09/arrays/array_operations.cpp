#include "array_operations.hh"


int greatest_v1(int *itemptr, int size)
{
    int greatest = *itemptr;

    for ( int i = 1;  i< size; ++i)
    {
        if ( *(itemptr+i) > greatest)
        {
            greatest = *(itemptr + i);
        }

    }
    return greatest;

}

int greatest_v2(int *itemptr, int *endptr)
{
    int greatest = *itemptr;
    //++ itemptr;  // i dont really get the point of the increment here

    while ( itemptr < endptr)
    {
        if ( *itemptr > greatest)
        {
            greatest = *itemptr;
        }
        ++ itemptr;
    }
    return greatest;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{
    while ( itemptr < endptr) {
        * targetptr = * itemptr;
        ++ itemptr;
        ++targetptr;

    }
}

void reverse(int *leftptr, int *rightptr)
{
    --rightptr;
    while ( leftptr < rightptr) {
        // Copy l -> temp -> l
        int tmp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = tmp;

        ++leftptr;
        --rightptr;
    }
}

