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
    Sets operator< (Sets s2);
    Sets operator> (Sets s2);
    Sets operator<= (Sets s2);
    Sets operator>= (Sets s2);


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
    Sets set4,set5,set6,set7; //for check comparition
    Sets Univer;
    for(int a=MIN;a<=MAX; a++){
        Univer.Insert(a);}
    set1.Insert(MIN+1);
    set1.Insert(MIN+2);
    for(int a=MIN;a<=MAX; a=a+2){
        set0.Insert(a);}
    std::cout<<"Univ. Set: ";
    Univer.Print();
    std::cout<<"Set0:      ";
    set0.Print();
    std::cout<<"Set1:      ";
    set1.Print();
    s3=set0+set1;
    std::cout<<"Set0+Set1: ";
    s3.Print();
    s3=set0-set1;
    std::cout<<"Set0-Set1: ";
    s3.Print();
    s3=set0*set1;
    std::cout<<"Set0*Set1: ";
    s3.Print();
    std::cout<<"!Set1:     ";
    (-set1).Print();
    set0.Member(14);
    set0.Member(15);

//comparation   positive
    set4.Insert(10);
    set4.Insert(15);
    set5.Insert(10);
    set5.Insert(15);
    set5.Insert(20);
    std::cout<<"\n\nSet4:      ";
    set4.Print();
    std::cout<<"Set5:      ";
    set5.Print();
    std::cout<<"\n\nAll of this must give true: \n";
    std::cout<<"Set4==Set4: ";
    s3=set4==set4;
    std::cout<<"Set4<Set5: ";
    s3=set4<set5;
    std::cout<<"Set4<=Set5: ";
    s3=set4<=set5;
    std::cout<<"Set4<=Set4: ";
    s3=set4<=set4;
    std::cout<<"Set5>Set4: ";
    s3=set5>set4;
    std::cout<<"Set5>=Set4: ";
    s3=set5>=set4;
    std::cout<<"Set4>=Set4: ";
    s3=set4>=set4;

//comparation  negative
    set6.Insert(11);
    set6.Insert(12);
    set7.Insert(13);
    set7.Insert(15);
    set7.Insert(24);
    std::cout<<"\n\nSet4:      ";
    set4.Print();
    std::cout<<"Set6:      ";
    set6.Print();
    std::cout<<"Set7:      ";
    set7.Print();
    std::cout<<"\n\nAll of this must give false: \n";
    std::cout<<"Set4<Set4: ";
    s3=set4<set4;
    std::cout<<"Set6>Set7: ";
    s3=set6>set7;
    std::cout<<"Set4>Set4: ";
    s3=set4>set4;
    std::cout<<"Set7<Set6: ";
    s3=set7<set6;
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

Sets Sets::operator>(Sets s2){
bool Answer;
Answer=false;
for(int a=0; a<(MAX-MIN+1);a++){
    if ((Value[a]!=s2.Value[a])&&(Value[a]>s2.Value[a])){
        Answer=true;
    }
    }
if (Answer==true){cout<<"True"<<endl;}
else {cout<<"False"<<endl;}
return (0);
}

Sets Sets::operator<(Sets s2){
    bool Answer;
    Answer=false;
    for(int a=0; a<(MAX-MIN+1);a++){
    if ((Value[a]!=s2.Value[a])&&(Value[a]<s2.Value[a])){
        Answer=true;
    }
    }
    if (Answer==true){cout<<"True"<<endl;}
    else {cout<<"False"<<endl;}
    return (0);
}

Sets Sets::operator<=(Sets s2){
    bool Answer=true;
    for(int a=0; a<(MAX-MIN+1);a++){
    if((s2.Value[a]!=Value[a])||((Value[a]==true) & (s2.Value[a]==false))){
                Answer=false;
            }else{Answer=true;

                    }
    }
    if (Answer==true){cout<<"True"<<endl;}
    else {cout<<"False"<<endl;}
    return (0);
}

Sets Sets::operator>=(Sets s2){
    bool Answer=true;
    for(int a=0; a<(MAX-MIN+1);a++){
    if((s2.Value[a]!=Value[a])||((Value[a]==false) & (s2.Value[a]==true))){
                Answer=false;
            }else{Answer=true;
                    }
    }
    if (Answer==true){cout<<"True"<<endl;}
    else {cout<<"False"<<endl;}
    return (0);
}
