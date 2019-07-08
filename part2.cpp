#include<bits/stdc++.h>
using namespace std;
//string s[100000];
class Proof{
public:int n;
       string ss;
       string *s;
       int k;
       int ind[100000];
       Proof(string *a,int nn){
         n=nn;
         k=0;
         s=a;
       }
       bool validateProof(){
         for(int i=0;i<n;i++)
          {
           //Determine position of '/'
           string s1="";
           for(int j=0;j<s[i].length();j++)
              if(s[i][j]=='/')
             {
                ind[i]=j;
                for(int l=j+1;l<j+4;l++)
                  s1=s1+s[i][l];
                break;
             }
           cout<<s1<<endl;
           if(s1=="^i/")
              ai(s[i]);
           if(s1=="^e1")
              ae1(s[i]);
              //And Elimination 2
           if(s1=="^e2")
              ae2(s[i]);
            //Or Introduction 1
           if(s1=="Vi1")
              oi1(s[i]);
            //Or Introduction 2
           if(s1=="Vi2")
              oi2(s[i]);
           //Implies Elimination
           if(s1==">e/")
              ie(s[i]);
           //MT
           if(s1=="MT/")
              MT(s[i]);
         }
         if(k==1)
            return false;
         if(k==0)
            return true;
       }
       void ai(string st){
            int ind1,ind2;
            int k1=0;
            int index;
            for(int i=0;i<st.length();i++)
                if(st[i]=='/')
                {
                    index=i;
                    break;
                }
            //Both slash
            for(int j=index+1;j<st.length();j++)
            {
                if(k1==0&&st[j]=='/')
                {
                    k1++;
                    ind1=j;
                }
                else if(k1==1&&st[j]=='/')
                {
                    ind2=j;
                    break;
                }
            }
            int n1=0,n2=0;
            for(int j=ind1+1;j<ind2;j++)
                n1=10*n1+(int)st[j]-48;
            for(int j=ind2+1;j<st.length();j++)
                n2=10*n2+(int)st[j]-48;
            string s3;
            int ind3,ind4;
            for(int j=0;j<s[n1-1].length();j++)
                if(s[n1-1][j]=='/')
                {
                    ind3=j;
                    break;
                }
            for(int j=0;j<s[n2-1].length();j++)
                if(s[n2-1][j]=='/')
                {
                    ind4=j;
                    break;
                }
            s3="(";
            for(int j=0;j<ind3;j++)
                s3=s3+s[n1-1][j];
            s3=s3+"^";
            for(int j=0;j<ind4;j++)
                s3=s3+s[n2-1][j];
            s3=s3+")";
            string s4="";
            for(int j=0;j<index;j++)
                s4=s4+st[j];
            //cout<<s3<<endl;
            //cout<<s4<<endl;
            if(s3!=s4)
              k=1;
       }
       void ae1(string str){
            int n1=0,n2=0;
            int ind2;
            int index;
            for(int i=0;i<str.length();i++)
                if(str[i]=='/')
                {
                    index=i;
                    break;
                }
            for(int j=str.length()-1;j>0;j--)
            {
                if(str[j]=='/')
                {
                    ind2=j;
                    break;
                }
            }
            for(int j=ind2+1;j<str.length();j++)
                n1=10*n1+(int)str[j]-48;
            stack<int> st;
            int ind1;
            for(int j=0;j<s[n1-1].length();j++)
            {
                if(s[n1-1][j]=='(')
                    st.push('1');
                if(s[n1-1][j]==')')
                    st.pop();
                if(s[n1-1][j]=='^'&&st.size()==1)
                {
                    ind1=j;
                    break;
                }
            }
            string s3="";
            for(int j=1;j<ind1;j++)
                s3=s3+s[n1-1][j];
            string s4="";
            for(int j=0;j<index;j++)
                s4=s4+str[j];
            if(s4.length()==0)
            {
                s4=s4+"(";
                s4=s4+str[0];
                s4=s4+")";
            }
            //cout<<s3<<endl;
            //cout<<s4<<endl;
            if(s3!=s4)
              k=1;

       }
       void ae2(string s1){
         string s3="";
         stack<int> st;
         int ind1,ind2;
         int n1=0;
         for(int i=s1.length()-1;i>=0;i--)
             if(s1[i]=='/')
             {
                 ind2=i;
                 break;
             }
         for(int i=ind2+1;i<s1.length();i++)
             n1=10*n1+(int)s1[i]-48;
         cout<<n1<<endl;
         for(int i=0;i<s[n1-1].length();i++)
         {
             if(s[n1-1][i]=='(')
                 st.push(1);
             if(s[n1-1][i]==')')
                 st.pop();
             if(st.size()==1&&s[n1-1][i]=='^')
             {
                 ind1=i;
                 break;
             }
         }
         cout<<ind1<<endl;
         for(int i=ind1+1;i<ind[n1-1]-1;i++)
             s3=s3+s[n1-1][i];
         cout<<s3<<endl;
         int ind3;
         for(int i=0;i<s1.length();i++)
             if(s1[i]=='/')
             {
                 ind3=i;
                 break;
             }
         string s4="";
         for(int i=0;i<ind3;i++)
               s4=s1[i]+s4;
         if(s3!=s4)
             k=1;
       }
       void oi1(string s1){
         string s3="";
         stack<int> st;
         int ind1,ind2;
         int n1=0;
         for(int i=s1.length()-1;i>=0;i--)
             if(s1[i]=='/')
             {
                 ind2=i;
                 break;
             }
         for(int i=ind2+1;i<s1.length();i++)
             n1=10*n1+(int)s1[i]-48;
         cout<<n1<<endl;
         for(int i=0;i<s1.length();i++)
         {
             if(s1[i]=='(')
                 st.push(1);
             if(s1[i]==')')
                 st.pop();
             if(st.size()==1&&s1[i]=='V')
             {
                 ind1=i;
                 break;
             }
         }
         for(int i=1;i<ind1;i++)
             s3=s3+s1[i];
         cout<<s3<<endl;
         string s4="";
         for(int i=0;i<ind[n1-1];i++)
             s4=s4+s[n1-1][i];
         cout<<s4<<endl;
         if(s3!=s4)
             k=1;
       }
       void oi2(string s1){
         string s3="";
         stack<int> st;
         int ind1,ind2;
         int n1=0;
         for(int i=s1.length()-1;i>=0;i--)
             if(s1[i]=='/')
             {
                 ind2=i;
                 break;
             }
         for(int i=ind2+1;i<s1.length();i++)
             n1=10*n1+(int)s1[i]-48;
         cout<<n1<<endl;
         for(int i=0;i<s1.length();i++)
         {
             if(s1[i]=='(')
                 st.push(1);
             if(s1[i]==')')
                 st.pop();
             if(st.size()==1&&s1[i]=='V')
             {
                 ind1=i;
                 break;
             }
         }
         int ind3;
         for(int i=0;i<s1.length();i++)
             if(s1[i]=='/')
             {
                 ind3=i;
                 break;
             }
         for(int i=ind1+1;i<ind3-1;i++)
             s3=s3+s1[i];
         cout<<s3<<endl;
         string s4="";
         for(int i=0;i<ind[n1-1];i++)
             s4=s4+s[n1-1][i];
         cout<<s4<<endl;
         if(s3!=s4)
             k=1;
       }
       void ie(string s1){
         int ind1,ind2;
         int k1=0;
         //Both slash
         int ind3;
         for(int i=0;i<s1.length();i++)
             if(s1[i]=='/')
             {
                 ind3=i;
                 break;
             }
         for(int j=ind3+1;j<s1.length();j++)
         {
             if(k1==0&&s1[j]=='/')
             {
                 k1++;
                 ind1=j;
             }
             else if(k1==1&&s1[j]=='/')
             {
                 ind2=j;
                 break;
             }
         }
         int n1=0,n2=0;
         for(int j=ind1+1;j<ind2;j++)
             n1=10*n1+(int)s1[j]-48;
         for(int j=ind2+1;j<s1.length();j++)
             n2=10*n2+(int)s1[j]-48;
         string s3="(";
         for(int i=0;i<ind[n2-1];i++)
             s3=s3+s[n2-1][i];
         s3=s3+">";
         for(int i=0;i<ind3;i++)
             s3=s3+s1[i];
         s3=s3+")";
         string s4="";
         for(int i=0;i<ind[n1-1];i++)
             s4=s4+s[n1-1][i];
         cout<<s3<<endl;
         cout<<s4<<endl;
         if(s3!=s4)
             k=1;
       }
       void MT(string s1){
         int ind1,ind2;
         int k1=0;
         //Both slash
         int ind3;
         for(int i=0;i<s1.length();i++)
             if(s1[i]=='/')
             {
                 ind3=i;
                 break;
             }
         for(int j=ind3+1;j<s1.length();j++)
         {
             if(k1==0&&s1[j]=='/')
             {
                 k1++;
                 ind1=j;
             }
             else if(k1==1&&s1[j]=='/')
             {
                 ind2=j;
                 break;
             }
         }
         int n1=0,n2=0;
         for(int j=ind1+1;j<ind2;j++)
             n1=10*n1+(int)s1[j]-48;
         for(int j=ind2+1;j<s1.length();j++)
             n2=10*n2+(int)s1[j]-48;
         string s3="(";
         for(int i=1;i<ind3;i++)
             s3=s3+s1[i];
         s3=s3+">";
         for(int i=1;i<ind[n2-1];i++)
             s3=s3+s[n2-1][i];
         s3=s3+")";
         string s4="";
         for(int i=0;i<ind[n1-1];i++)
             s4=s4+s[n1-1][i];
         cout<<s3<<endl;
         cout<<s4<<endl;
         if(s3!=s4)
             k=1;
       }
};
int main(){
  int n;
  string ss,s[1000];
  cin>>n;
  getline(cin,ss);
  for(int i=0;i<n;i++)
      getline(cin,s[i]);
  Proof p(s,n);
  bool t = p.validateProof();
  if(t)
    cout<<"Valid Proof";
  else
    cout<<"Invalid proof";
  return 0;
}
