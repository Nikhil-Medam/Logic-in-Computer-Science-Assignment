#include<bits/stdc++.h>
using namespace std;
struct node
{
    char c;
    struct node* lchild;
    struct node* rchild;
};
class Proposition{
 public:string s1,ps;
        struct node *head;
        Proposition(string st){
          s1=st;
          head=NULL;
          ps="";
        }
        string getPostfix(){
          stack<char> st;
          string s2;
          char op[]={'(','>','V','^','~'};
          for(int i=0;i<s1.length();i++)
          {
              if((int)s1[i]>=97&&(int)s1[i]<=122)
              {
                  s2=s2+s1[i];
              }
              else
              {
                  if(st.empty())
                  {
                      st.push(s1[i]);
                  }
                  else if(s1[i]=='(')
                      st.push(s1[i]);
                  else
                  {
                      int ind1=-1,ind2=-1;
                      for(int j=0;j<5;j++)
                      {
                          if(op[j]==s1[i])
                              ind1=j;
                          if(op[j]==st.top())
                              ind2=j;
                      }
                      if(ind1>=ind2)
                      {
                          st.push(s1[i]);
                      }
                      else
                      {
                          s2=s2+st.top();
                          st.pop();
                          if(ind1==-1)
                          {
                              while(st.top()!='(')
                              {
                                  s2=s2+st.top();
                                  st.pop();
                              }
                              st.pop();
                          }
                          else
                              st.push(s1[i]);
                      }
                  }
              }
          }
          for(int i=0;!st.empty();i++)
          {
              s2=s2+st.top();
              st.pop();
          }
          ps=s2;
          return s2;
        }
        struct node* binaryTree(){
          int n=ps.length();
          char op[]={'>','V','^','~'};
          int a[n]={0};
          struct node * p[n];
          for(int i=0;i<n;i++)
          p[i] = (struct node*)malloc(sizeof(struct node));
          for(int i=0;i<n;i++){
             p[i]->c=ps[i];
             p[i]->lchild=NULL;
             p[i]->rchild=NULL;
           }
          for(int i=0;i<n;i++)
          {
             int k=0;
             for(int j=0;j<4;j++)
             if(ps[i]==op[j])
                k=1;
             if(ps[i]=='~')
              {
                 int ind;
                 for(int j=i-1;j>=0;j--)
                    if(a[j]==0)
                   {
                    ind=j;
                    break;
                   }
                a[ind]=1;
                p[i]->rchild=p[ind];
             }
            else if(k)
             {
                int ind1=-1,ind2=-1;
                int k1=0;
                for(int j=i-1;j>=0;j--)
                  {
                     if(a[j]==0)
                     {
                        if(k1==0)
                        {
                          k1++;
                          ind1=j;
                        }
                        else
                        {
                          ind2=j;
                          break;
                        }
                     }
                  }
            a[ind1]=1;
            a[ind2]=1;
            p[i]->rchild=p[ind1];
            p[i]->lchild=p[ind2];
         }
      }
      head=p[n-1];
      //print(p[n-1]);
      return p[n-1];
   }
   void print(struct node* nd){
     if(nd==NULL)
       return;
    print(nd->lchild);
    cout<<nd->c;
    print(nd->rchild);
   }
};
int main()
{
    string s1;
    cout<<"Enter a propositional Expression:";
    cin>>s1;
    Proposition p(s1);
    string s2= p.getPostfix();
    cout<<"Postfix of the given expression is: "<<s2<<endl;
    struct node* head=NULL;
    head=p.binaryTree();
    cout<<head->lchild->c<<endl;
    cout<<"Infix expression from the parse tree is: ";
    p.print(head);
    return 0;
}
