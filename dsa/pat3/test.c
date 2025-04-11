int gdc(int a,int b){
    while(b!=0){
        temp=b;
        b=b%a;
        a=temp;
    }
}

int lcm(){
    return (a/gdc(a,b))*b;
}