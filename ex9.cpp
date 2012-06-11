#include "BtM.h"


using namespace std;
int const MAX=30,MIN=10;

class Sets{
    bool *Value;
    void setting();
    public:
            Sets();
            Sets(int n);
            void Insert(int n);
            void Remove(int n);
            void Member(int n);
            void Print();
    Sets operator+ (Sets s2);
    Sets operator- (Sets s2);
    Sets operator- ();
    Sets operator* (Sets s2);
    Sets operator== (Sets s2);

};

void Sets::setting(){
for (int a=0; a<(MAX-MIN+1);a++){
Value[a]=false;
}
}

Sets::Sets (){
    Value = new bool [MAX-MIN+1];
    setting();
    };

Sets::Sets(int n){
    Value = new bool [MAX-MIN+1];
    setting();
    Value[n-MIN] = true;
    };


void Sets::Print(){
/*
int comas=0;
for(int a=0; a<(MAX-MIN+1);a++){
    if (Value[a]==true){
        comas++;
        }
}

cout<<"{";
if (comas==0){ cout<<"0";}
for(int a=0; a<(MAX-MIN+1);a++){
    if (Value[a]==true){
        cout<<MIN+a;
        comas--;
            if (comas!=0){
            cout<<",";
            }
        }
}
cout<<"}"<<endl;
*/
cout<<"{";
for(int a=0; a<(MAX-MIN+1);a++){
            if (a!=0){
            cout<<",";
            }
        cout<<Value[a];
}
cout<<"}"<<endl;

//*/


}

void Sets::Insert(int n){Value[n-MIN] = true;}

void Sets::Remove(int n){Value[n-MIN] = false;}

void Sets::Member(int n){
    if ((n<MIN) || (n>MAX)){
        cout<<"Can`t check Member: N:"<<n<<" must be "<<MIN<<" < N < "<<MAX<<endl;
    return;
    }
    if (Value[n-MIN]==true)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    }

main ()                                // test the functions
{
    Sets set0;
    Sets set1(MIN);
    Sets s3; //save results of the operators
    Sets Univer;
    for(int a=MIN;a<=MAX; a++){
        Univer.Insert(a);}
    set1.Insert(MIN+1);
    set1.Insert(MIN+2);
    for(int a=MIN;a<=MAX; a=a+2){
        set0.Insert(a);}
    std::cout<<"Univ. Set: ";
    Univer.Print();
    std::cout<<"set0:      ";
    set0.Print();
    std::cout<<"set1:      ";
    set1.Print();
    s3=set0+set1;
    std::cout<<"set0+Set1: ";
    s3.Print();
    s3=set0-set1;
    std::cout<<"set0-Set1: ";
    s3.Print();
    s3=set0*set1;
    std::cout<<"set0*Set1: ";
    s3.Print();
    std::cout<<"!Set1:     ";
    (-set1).Print();
    std::cout<<"set1==Set1: ";
    s3=set1==set1;
    set0.Member(14);
    set0.Member(15);
    return 0;
}



Sets Sets::operator+(Sets s2){
Sets s0;
for(int a=0; a<(MAX-MIN+1);a++){
s0.Value[a]=s2.Value[a]+Value[a];
}
return (s0);
}

Sets Sets::operator-(Sets s2){
Sets s0;
for(int a=0; a<(MAX-MIN+1);a++){
s0.Value[a]=s2.Value[a]-Value[a];
}
return (s0);
}

Sets Sets::operator-(){
Sets s0;
for(int a=0; a<(MAX-MIN+1);a++){
s0.Value[a]=!Value[a];
}
return (s0);
}

Sets Sets::operator*(Sets s2){
Sets s0;
for(int a=0; a<(MAX-MIN+1);a++){
s0.Value[a]=s2.Value[a]*Value[a];
}
return (s0);
}

Sets Sets::operator==(Sets s2){
bool Equals;
Equals=true;
for(int a=0; a<(MAX-MIN+1);a++){
if(s2.Value[a]!=Value[a]){
            Equals=false;
            break;
        }
}
if (Equals==true){cout<<"True"<<endl;}
else {cout<<"False"<<endl;}
return (0);
}


