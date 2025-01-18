// Note that there is no need for "using namespace std",
// since no C++ standard libraries are used.

double addition(double left, double right) {
    return left + right;
}


double subtraction(double left, double right) {
    return left - right;
}


double multiplication(double left, double right) {
    return left * right;
}


double division(double left, double right) {
    return left / right;
}

double exponential(double left, double right)
{   if (right == 0)
    {
        return 1;
    }
    else
    {
        return left *exponential(left, right-1);
    }

}
