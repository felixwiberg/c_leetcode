#include <stdio.h>
#include <stdlib.h>
struct Point {
    int x;
    int y;
};

int maxPoints(struct Point* points, int pointsSize) {
    if(pointsSize == 1){
        return 1;
    }
    
    double  xdiff = 0,
            ydiff = 0,
            m = 0,
            k = 0;
    int this_line_count = 0,
        record = 0;
    for(int i = 0; i<pointsSize; i++){
        for(int j = i+1; j<pointsSize; j++){
            this_line_count = 0;
            xdiff = points[i].x - points[j].x;
            ydiff = points[i].y - points[j].y;

            if(xdiff != 0){
                k = ydiff/xdiff;
                m = points[i].y-k*points[i].x;
                for(int l = 0; l<pointsSize; l++){
                    if(points[l].y*xdiff == ydiff*points[l].x + points[i].y*xdiff -ydiff*points[i].x){
                        this_line_count++;
                    }
                }
            }else{
                for(int l = 0; l<pointsSize; l++){
                    if(points[l].x == points[i].x){
                        this_line_count++;
                    }
                }
            }
            record=this_line_count>record?this_line_count:record;
        }
    }
    return record;
}

int main(){
    struct Point a[4];
    a[0].x = 3;
    a[0].y = 1;
    a[1].x = -6;
    a[1].y = -1;
    a[2].x = 3;
    a[2].y = 1;
    a[3].x = 12;
    a[3].y = 3;

    int res = maxPoints(a, 4);
    printf("%d", res);
    return 0;
}
