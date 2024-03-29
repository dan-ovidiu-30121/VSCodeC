#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
typedef unsigned long long UINT64;
typedef struct Point
{
    double x,y;
} Point;

void getMiddlePoint(const Point* a,const Point* b, Point *out)
{
    out->x = (a->x + b->x)/2;
    out->y = (a->y + b->y)/2;
}
typedef union Example
{
   int x;
   float y;
   char bytes[12];
}Example;

typedef struct CustomFloat
{
    bool isExtended;
    union{
        float value;
        double valueExtended;
    };

}CustomFloat;

typedef enum Color
{
    RED = 2,
    BLUE,
    YELLOW
} Color;

int main()
{
    /*Point p1 = {.x = 1, .y = 1};
    Point p2 = {.x = 3, .y = 2};
    Point middle;
    getMiddlePoint(&p1,&p2,&middle);
    printf("%lf %lf\n",middle.x,middle.y);*/

    /*Example e;
    //e.num = 17;
    e.bytes[0] = 17;
    printf("%lld\n",e.num);
    for(int i = 0; i < 8; i++){
        printf("%02hhx ",e.bytes[i]);
    }*/
    /*CustomFloat cf,cf2;
    cf.isExtended = false;
    cf.value = 12.5;
     
    cf2.isExtended = true;
    cf2.valueExtended = 0.25;
    printf("%f %lf\n",cf.value,cf2.valueExtended);*/
    Color c = BLUE;
    Example e;
    printf("%d\n",sizeof(c));
    printf("%d\n",sizeof(e));
    return 0;
}