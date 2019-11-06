#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}


int countWays(int dice[],int n,int i,int sum){
    if(sum==0 && i==n){
        return 1;
    }
    if(sum<0 || i>=n){
        return 0;
    }
    int ways=0;
    for(int j=1;j<=dice[i];j++){
        if(sum>=j)
            ways+=countWays(dice,n,i+1,sum-j);
    }
    return ways;
}
int main(){
    int n;
    cout<<"Enter the number of dice(s): ";
    cin>>n;
    int dice[n];
    int total_combinations=1;
    int max_value=0;//max possible sum
    int min_value=n;//minimum possible sum as each dice can be 1
    double diceFaces;
    string faces[]={ "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th"};
    for(int i=0;i<n;i++){
        cout<<"Enter the number of faces for the  "<<faces[i]<<" dice: ";
        cin>>diceFaces;
        while((int)diceFaces!=diceFaces){
            cout<<"Error: input value should be integer in range 1..12\n"
            cout<<"Enter the number of faces for the  "<<faces[i]<<" dice: ";
            cin>>diceFaces;
        }
        dice[i]=(int)diceFaces;
        total_combinations*=dice[i];
        max_value+=dice[i];
    }
    bool flags[max_value-min_value+1];
    for(int i=0;i<max_value-min_value+1;i++)
        flags[i]=false;
    int ways[max_value-min_value+1];
    for(int i=min_value;i<=max_value;i++){
        ways[i-min_value]=countWays(dice,n,0,i);
    }
    for(int i=0;i<max_value-min_value+1;i++){
        int index;//find the first value which is not printed then we can use that to find max
        for(int j=0;j<max_value-min_value+1;j++){
            if(flags[j]==false){
                index=j;
                break;
            }
        }
        for(int j=min_value;j<=max_value;j++){
            if(flags[j-min_value]==false && ways[j-min_value]>=ways[index]){
                index=j-min_value;
            }
        }
        flags[index]=true;
        int factor=gcd(ways[index],total_combinations);
        cout<<"Probability of having sum "<<min_value+index<<" is "<<ways[index]/factor<<"/"<<total_combinations/factor<<"\n";
    }
    
}