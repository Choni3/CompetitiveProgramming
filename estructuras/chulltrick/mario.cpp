struct line{
    long long y0;
    int m;
    
    line(){}
    line(long long _y0, int _m):
        y0(_y0), m(_m){}
};

bool check(line a, line b, line c){
    return (a.y0 - b.y0) * (c.m - a.m) < (a.y0 - c.y0) * (b.m - a.m);
}

int nh,pos;
line H[1005];

void update(line l){
    while(nh >= 2 && !check(H[nh - 2],H[nh - 1],l)){
        if(pos == nh - 1) --pos;
        --nh;
    }
    
    H[nh++] = l;
}

long long eval(int id, int x){
    return H[id].y0 + (long long)H[id].m * x;
}

long long query(int x){
    while(pos + 1 < nh && eval(pos,x) > eval(pos + 1,x)) ++pos;
    return eval(pos,x);
}
