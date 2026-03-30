#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void make(int node){
    parent[node]=node;
}

int find(int node){
    if(parent[node]==node) return node;
    return find(parent[node]);
}

void union(int node1, int node2){
    int p1=find(node1);
    int p2=find(node2);
    if(p1!=p2){
        
    }
}
int main(){

}