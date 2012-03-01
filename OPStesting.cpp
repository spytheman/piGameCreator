#include <iostream>
#include <ctime>
using namespace std;
#include <cmath>


inline double point_distance(double x1, double y1, double x2, double y2)
{
    //register double xm=x2-x1, ym=y2-y1;
    //return sqrt(xm*xm + ym*ym);
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}



int main()
{
    clock_t time = clock();long c, secs, fps, sum;c=0;secs=0;fps=0;cout<<"Starting single-threaded bench:\n";
    cout<<"2D point distance"<<endl;
    while(true)
    {

        //code to bench
        double result = point_distance(500,100,30,secs);



        //the clock thing:
        if(clock() >  time + secs*CLOCKS_PER_SEC)
        {
            fps=c;
            if(secs>0)
            {
                cout<<"OPS: "<<fps<<endl;
                if(secs%10==0)
                {
                    cout<<fps/60 <<" ops per frame in 60 FPS cap\n";
                }
            }
            secs++;
            c=0;
        }
        c++;
    }

}
