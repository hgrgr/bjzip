#include <iostream>
using namespace std;

typedef struct __Point
{
   int xpos;
   int ypos;

}Point;

Point *delpo;
// 위의 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하고
// (덧셈결과는 함수의 반환을 통해서 얻게 한다),
Point& PntAdder(const Point& p1, const Point& p2) {

   printf("\n p1 add = %d\n", &p1);
   printf("\n p2 add = %d\n", &p2);
   Point* sum = new Point;
   delpo = sum;
   printf("\n sum add = %d\n", sum);
   sum->xpos = p1.xpos + p2.xpos;
   sum->ypos = p1.ypos + p2.ypos;

   return *sum;

}

// 임의의 두 점을 선언하여, 위 함수를 이용한 덧셈연산을 진행하는 main함수를 정의해보자.
// 단, 구조체 Point관련 변수의 선언은 무조건 new연산자를 이용해서 진행해야 하며,
// 할당된 메모리 공간의 소멸도 철저해야 한다.
int main(void) {
   Point* a = new Point;
   Point* b = new Point;

   a->xpos = 5;
   a->ypos = 10;
   b->xpos = 3;
   b->ypos = 2;

   printf("\n a add = %d\n", a);
   printf("\n b add = %d\n", b);
   Point& ref = PntAdder(*a, *b); // Point &ref도 가능!
   printf("\n ref add = %d\n", &ref);
   printf("\n del add = %d\n", delpo);
   cout << "덧셈결과 x좌표: " << ref.xpos << endl;
   cout << "덧셈결과 y좌표: " << ref.ypos << endl;
    
   Point aa;
   Point *cc;
   printf(" \n aa size = %d bb size = %d cc size = %d \n", sizeof(aa), sizeof(ref),sizeof(cc));
   //delete delpo;
   cout <<  delpo->xpos << endl;
   cout <<  delpo->ypos << endl;

   delete &ref;
   cout <<  delpo->xpos << endl;
   cout <<  delpo->ypos << endl;
   delete a;
   delete b;
}
