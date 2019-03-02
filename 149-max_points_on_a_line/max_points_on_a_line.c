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
            ydiff = 0;
    int this_line_count = 0,
        record = 0;
    for(int i = 0; i<pointsSize; i++){
        for(int j = i+1; j<pointsSize; j++){
            this_line_count = 0;
            xdiff = points[i].x - points[j].x;
            ydiff = points[i].y - points[j].y;

            if(xdiff != 0){
                for(int l = 0; l<pointsSize; l++){
                    if( points[l].y ==
                        (points[j].y-points[i].y)*
                       ((points[l].x-points[j].x)/(double)(points[j].x-points[i].x))+
                       points[j].y){    
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
    a[0].x = 0;
    a[0].y = 0;
    a[1].x = 94911151;
    a[1].y = 94911150;
    a[2].x = 94911152;
    a[2].y = 94911151;
    int res = maxPoints(a, 3);
    printf("%d", res);
    return 0;
}
