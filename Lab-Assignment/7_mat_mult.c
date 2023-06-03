#include<stdio.h>

int n,i,m[100][100],s[100][100],p[100];



void matrix_chain_order() {   
   int j,l,k,N,q;

   N=n-1;
   for (i=1;i<=N;i++){
      m[i][i] = 0;
   }
   for(l=2;l<=N;l++){
      for(i=1;i<=N-l+1;i++){
         j=i+l-1;
         m[i][j]=9999;
         for(k=i;k<=j-1;k++){
            q=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
            if (q<m[i][j]){
               m[i][j] = q;
               s[i][j]=k;
            }
         }
      }
   } 
}



void print_optimal_parens(int i , int j){
 
 if(i==j){
   printf("A%d",i);
 }
 else{
   printf("(");
   print_optimal_parens(i,s[i][j]);
   print_optimal_parens(s[i][j]+1,j);
   printf(")");
 }
}



void print_list(){

 int k;

   printf("\nm table :\n");
   for(i=1;i<=n;i++){
      for(k=1;k<=n-1;k++){
         if(i<=k)
            printf("%d\t",m[i][k]);
         else
            printf("\t");
      }
   printf("\n");
   }

   printf("\ns table:\n");
   for(i=1;i<=n;i++){
      for(k=1;k<=n-1;k++){
         if(i<k)
            printf("%d\t",s[i][k]);
         else
            printf("\t");
      }
   printf("\n");
   }
   printf("\nOptimal cost of matrix multiplication : %d\n",m[1][n-1]);
}



int main(){

 printf("\nEnter dimention of the array : ");
 scanf("%d",&n); 
 
 printf("Enter the array elements : ");
 for(i=0;i<=n-1;i++){
   scanf("%d",&p[i]);
 }
 
 printf("\np = ");
 for(i=0;i<n;i++){
   printf("%d ",p[i]);
 }
 printf("\n\n");
 
 matrix_chain_order();
 print_list();
 printf("Optimal parenthesis sequence of the matrix : ");
 print_optimal_parens(1,n-1);
  
return 0;
}