#include <iostream>
//Smovzhenko Anton
using namespace std;

#include "Point.h"
#include "triangle.h"


int main()
{
    try
    {


        Point a(-5, 2),
            b(7, -7),
            c(5, 7);
        Triangle triangle(a, b, c);
        cout << "Triangle: " << triangle << endl;
        cout << endl;

        Point p1(7, 8),
            p2(6, 2),
            p3(4, 3);
        Triangle triangle1(p1, p2, p3);
        cout << "Triangle ¹1: " << triangle1 << endl;

        Triangle triangle2;
        cout << "Triangle ¹2: " << triangle2 << endl;

        //creation of triangle2 by points
        Point point4(12, 1);
        triangle2.apexA(point4);

        Point point6(13, 1);
        triangle2.apexC(point6);

        Point point5(12, 3);
        triangle2.apexB(point5);

        Triangle triangle3(3, 6, 4, 6, 7, 8);
        cout << "Triangle ¹3: " << triangle3 << endl;

        Triangle triangle4(triangle3);
        cout << "Triangle ¹4: " << triangle4 << endl;

        triangle4 = triangle1;
        cout << "(1) Triangle ¹4: " << triangle4 << endl;

        Triangle triangle5(1, 6, 5, 4, 3, 4);
        cout << "Triangle ¹5: " << triangle5 << endl;
        cout << endl;
        cout << endl;

        
        cout << "Triangle - top of A: " << triangle.apexA() << endl;
        cout << "Triangle - top of B: " << triangle.apexB() << endl;
        cout << "Triangle - top of C: " << triangle.apexC() << endl;
        cout << endl;
        cout << endl;


        cout << "Triangle ¹3 - top of A: " << triangle3.apexA() << endl;
        cout << "Triangle ¹3 - top of B: " << triangle3.apexB() << endl;
        cout << "Triangle ¹3 - top of C: " << triangle3.apexC() << endl;
        cout << endl;
        cout << endl;


      

        cout << "Triangle ¹2: " << triangle2 << endl;
        cout << endl;
        cout << endl;

        cout << "Triangle ¹1 - side A = " << triangle1.side_a() << endl;
        cout << "Triangle ¹1 - side B = " << triangle1.side_b() << endl;
        cout << endl;
        cout << endl;

        cout << "Triangle ¹1 - side A length = " << triangle1.length_a() << endl;
        cout << "Triangle ¹1 - side B length = " << triangle1.length_b() << endl;
        cout << endl;
        cout << endl;

        cout << "Triangle - med to A = " << triangle.mediana_a() << endl;
        cout << "Triangle - med to B = " << triangle.mediana_b() << endl;
        cout << "Triangle - med to C = " << triangle.mediana_c() << endl;
        cout << endl;
        cout << endl;

  
        cout << "Triangle ¹4 - mediana to A = " << triangle4.mediana_a() << endl;
        cout << "Triangle ¹4 - mediana to B = " << triangle4.mediana_b() << endl;
        cout << "Triangle ¹4 - mediana to C = " << triangle4.mediana_c() << endl;
        cout << endl;
        cout << endl;

        Triangle t6(1, 200, 300, 400, 500, 666);
    }
    catch (Triangle::BadTriangle badTriangle)
    {
        cerr << badTriangle << endl;
    }
}
