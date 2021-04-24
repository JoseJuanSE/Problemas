for(int i=0;i<=78495;i++){
        int s = get_S(p[i],p[i+1]);
        if(s%p[i+1]!=0){
            // cout<<"PROBLEMAS"<<endl;
        }
        ans += s;
    }