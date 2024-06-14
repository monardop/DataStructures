#include "excersise1.h"
#include <string.h>

int compare(info *org, info *result, int amountElem)
{
    int i = 0;

    while (i < amountElem)
    {
        if( strcmp(org[i].localidad, result[i].localidad) != 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void printTest(int elemFound, int elemExpected, info *expected, info *result, char *numTest)
{
    printf("%s: Analizing:\n", numTest);
    if(elemFound != elemExpected)
    {
        printf("\tWrong vector size\n");
        return;
    }

    if(compare(expected, result, elemExpected) == 0)
    {
        printf("\tNot right elems\n");
        return;
    }else {
        printf("\t%s: PASS\n", numTest);
        return;
    }
}

void test_case1() //normal flow
{
    info test[] = {{10, "LaMatanza", 3009.22f, 1997}, {20, "Haedo", 40.22f, 1927},
                   {3, "Moron", 69.22f, 1997}, {10, "Boedo", 50.22f, 1927},
                   {5, "Ituzaingo", 902.2f, 1997}, {15, "Sarmiento", 10.22f, 1927},
                   {7, "Tablada", 2009.22f, 1997}, {18, "Hurlingam", 50.22f, 1927},
                   {9, "SanMiguel", 900.22f, 1997}, {8, "Patricios", 100.22f, 1927}};
    info result[5],
         expected[5] = {{10, "LaMatanza", 3009.22, 1997},{7, "Tablada", 2009.22f, 1997},
                        {5, "Ituzaingo", 902.2f, 1997},{9, "SanMiguel", 900.22, 1997},  {8, "Patricios", 100.22, 1927}};
    int elemFound;

    FILE *pf = fopen("TestFile.dat", "wb");
    for (size_t i = 0; i < 10; i++)
    {
        fprintf(pf,"%2d %50s %5.2f %4d\n", test[i].prov, test[i].localidad, test[i].sup, test[i].population);
    }
    fclose(pf);

    elemFound = ex1Main(result,"TestFile.dat");
    printTest(elemFound, 5, expected, result, "Test Case 1");
    showResults(result, elemFound);
}

void test_case2() //alternative 1 flow
{
    info test[] = {{10, "LaMatanza", 3009.22f, 1997}, {20, "Haedo", 40.22f, 1927},
                   {3, "Moron", 69.22f, 1997}, {10, "Boedo", 50.22f, 1927}};
    info result[5],
         expected[4] = {{10, "LaMatanza", 3009.22f, 1997}, {3, "Moron", 69.22f, 1997}, 
                        {10, "Boedo", 50.22f, 1927} ,{20, "Haedo", 40.22f, 1927}}
    ;
    int elemFound;

    FILE *pf = fopen("TestFile.dat", "wb");
    for (size_t i = 0; i < 4; i++)
    {
        fprintf(pf,"%2d %50s %5.2f %4d\n", test[i].prov, test[i].localidad, test[i].sup, test[i].population);
    }
    fclose(pf);

    elemFound = ex1Main(result,"TestFile.dat");
    printTest(elemFound, 4, expected, result, "Test Case 2");
    showResults(result, elemFound);
}

void test_case3() //normal flow
{
    info result[5], expected[5];
    int elemFound;

    FILE *pf = fopen("TestFile.dat", "wb");
    fclose(pf);

    elemFound = ex1Main(result,"TestFile.dat");
    printTest(elemFound, 0, expected, result, "Test Case 3");
    showResults(result, elemFound);
}

void mainTest()
{
    test_case1();
    test_case2();
    test_case3();
}
