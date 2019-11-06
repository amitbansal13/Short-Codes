#include <stdio.h>

void linearRegression(int n, double x[],double y[], double* m, double* b){
    //y=mx+b
    //implementing the formula 
    double   sumx = 0.0;                      
    double   sumx2 = 0.0;                     
    double   sumxy = 0.0;                     
    double   sumy = 0.0;                      
    double   sumy2 = 0.0;
    int i=0;
    for (i=0;i<n;i++){ 
        sumx  += x[i];       
        sumx2 += x[i]*x[i];  
        sumxy += x[i] * y[i];
        sumy  += y[i];      
        sumy2 += y[i]*y[i]; 
    } 

    double denom = (n * sumx2 - sumx*sumx);
    if (denom == 0) {//not solvable
        *m = 0;
        *b = 0;
    }

    *m = (n * sumxy  -  sumx * sumy) / denom;
    *b = (sumy * sumx2  -  sumx * sumxy) / denom;
}

int main(){
    double x[100];
    double y[100];
    int count=0;
    double m,b;
    double tempx;
    while(count<100){
        scanf("%lf",&tempx);
        if(tempx==-999)
            break;
        x[count]=tempx;
        scanf("%lf",&y[count]);
        count++;
    }
    linearRegression(count,x,y,&m,&b);
    printf("m\t\tb\n");
    printf("%lf\t%lf\n",m,b);
    double minX=x[0],maxX=x[0],minY=y[0],maxY=y[0];
    int i=0;
    for(i=0;i<count;i++){
        if(x[i]<minX && y[i]<minY){
            minX=x[i];
            minY=y[i];
        }
        if(y[i]>maxY && x[i]>maxX){
            maxX=x[i];
            maxY=y[i];
        }
    }
    printf("Cetroid x= %lf, y= %lf ",(minX+maxX)/2,(maxY+minY)/2);

}