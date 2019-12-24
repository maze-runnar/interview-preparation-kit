#include<bits/stdc++.h>
using namespace std;
struct trie{
  trie *child[2];
  bool is_end;
};
trie *new_node()
{
  trie *temp=new trie;
  temp->child[0]=NULL;
  temp->child[1]=NULL;
  temp->is_end=false;
return temp;  
}
void insert(trie *root,int x)
{
  trie *temp=root;
  int index;
  for(int i=31;i>=0;i--)
  {
    if(x&(1<<i))
      index=1;
    else
      index=0;
    if(temp->child[index]==NULL)
     temp->child[index]=new_node();

    temp=temp->child[index]; 
  }
temp->is_end=true;  
}
void search_result(trie *root,int x)
{  int cnt=0,index,index_;
   trie *temp=root;
   for(int i=31;i>=0;i--)
   {
      if(x&(1<<i))
        index=1;
      else
        index=0;
         
       index_=(index+1)%2;

     if(temp->child[index_]!=NULL && temp->is_end==false)
     {
       cnt=cnt+pow(2,i) ;
       temp=temp->child[index_];
     } 
     else {
     temp=temp->child[index];
     }
   }
  cout<<cnt<<endl; 
}
void max_xor(int vec[],int n,int q[],int t)
{
  trie *root=new_node();
  
  for(int i=0;i<n;i++){
   //cout<<"insert: "<<q[i]<<endl;;
   insert(root,vec[i]);}
   
  for(int i=0;i<t;i++)
  { //cout<<"q["<<i<<"]: "<<q[i]<<"=";
    search_result(root,q[i]);
  }
}
int main()
{
  int n,x,t;
  cin>>n;
  int vec[n];
  for(int i=0;i<n;i++)
   cin>>vec[i];
   
   cin>>t;int q[t];
   for(int i=0;i<t;i++)
    cin>>q[i];
max_xor(vec,n,q,t);
return 0;
}
