double mPow(float x, int power)
{
    double retValue;
    short isNegative;

    if( power == 0 && x != 0 ) return 1;
    if( power == 1 )           return x; 

    isNegative = 0;
    retValue = 1;

    if ( power < 0 ) 
    {
        isNegative = 1;
        power *= -1;
    }

    for ( int i = 1; i <= power; i++ )
    {
        retValue *= x;
    }

    return (isNegative) ? (1 / retValue) : retValue ;
}

unsigned long long factorial(int x) 
{
    unsigned long long retValue = 1; 

    for( int i = 2; i<= x; i++ ) 
    {
        retValue *= i;
    }

    return retValue; 
}

double combinatoria(int m, int n) 
{
    if(m < n || n < 0) return -1;

    return (double)factorial(m) / (double)(factorial(n) * factorial (m - n)) ;
}

float ePotencia(int x, float tolerancia) 
{
    float retValue, curVal;
    int curPow;
    if( x == 0 ) return 1;

    curPow = retValue = 1;

    while ( (curVal = mPow(x, curPow) / factorial(curPow)) > tolerancia )
    {
        retValue += curVal;
        curPow++;
    }
    
    return retValue;
}
