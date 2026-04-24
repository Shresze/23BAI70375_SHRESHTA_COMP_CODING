class Solution {
public:
    vector<int> p;

    int find(int x){
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }

    bool unite(int a,int b){
        a=find(a), b=find(b);
        if(a==b) return false;
        p[a]=b;
        return true;
    }

    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size()<n-1) return -1;
        p.resize(n);
        iota(p.begin(),p.end(),0);

        int comp=n;
        for(auto &e:conn)
            if(unite(e[0],e[1])) comp--;

        return comp-1;
    }
};
