
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


//-----------------------------------------------------
// show matrix : cout<< in c++ , printf() in c
void printf(vector<vector<float> > &a,int n,int show){
    int i,j;
    if(show == 1)
        for(i=0;i < n;i++){
            for(j=0;j < n;j++)
                cout<<" "<<a[i][j]<<" \t";
            cout<<"\n";
        }
    else if(show == 2){
        cout<<"\n\n The Inverse Of Matrix Is : \n\n";
        for (i=0;i<n;i++){
            for (j=0;j<n;j++)
                cout<<" "<<a[i][j]<<" \t";
            cout<<"\n";
        }
    }
}

//---------------------------------------------------
//  calculate minor of matrix OR build new matrix : k-had = minor
void Minor(vector<vector<float>> &b,vector<vector<float>> &a,int i,int n){
    int j,l,h=0,k=0;
    for(l=1;l<n;l++){
        for( j=0;j<n;j++){
            if(j == i)
                continue;
            b[h][k] = a[l][j];
            k++;
            if(k == (n-1)){
                h++;
                k=0;
            }
        }
    }
        
}// end function

//---------------------------------------------------
//  calculate determinte of matrix
float det(vector<vector<float>> &a,int n){
    int i;
    vector<vector<float> > b;
    for(int i=0;i<n;i++){
        vector<float> temp;
        for(int j=0;j<n;j++){
            temp.push_back(0.0);
        }
        b.push_back(temp);
    }
    float sum=0;
    if (n == 1)
return a[0][0];
    else if(n == 2)
return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    else
        for(i=0;i<n;i++){
            Minor(b,a,i,n); // read function
            sum = (float) (sum+a[0][i]*pow(-1,i)*det(b,(n-1))); // read function    // sum = determinte matrix
        }
return sum;
}// end function

//---------------------------------------------------
//  calculate transpose of matrix
void transpose(vector<vector<float>> &c,vector<vector<float>> &d,int n,float det){
    int i,j;
    vector<vector<float> > b;
    for(int i=0;i<n;i++){
        vector<float> temp;
        for(int j=0;j<n;j++){
            temp.push_back(0.0);
        }
        b.push_back(temp);
    }
    //float b[100][100];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            b[i][j] = c[j][i];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            d[i][j] = b[i][j]/det;  // array d[][] = inverse matrix
}// end function

//---------------------------------------------------
//  calculate cofactor of matrix
void cofactor(vector<vector<float>> &a,vector<vector<float>> &d,int n,float determinte){
    vector<vector<float> > b,c; 
    //float b[100][100],c[100][100];
    int l,h,m,k,i,j;
    for(int i=0;i<n;i++){
        vector<float> temp;
        for(int j=0;j<n;j++){
            temp.push_back(0.0);
        }
        b.push_back(temp);
    }
    for(int i=0;i<n;i++){
        vector<float> temp;
        for(int j=0;j<n;j++){
            temp.push_back(0.0);
        }
        c.push_back(temp);
    }
    for (h=0;h<n;h++)
        for (l=0;l<n;l++){
            m=0;
            k=0;
            for (i=0;i<n;i++)
                for (j=0;j<n;j++)
                    if (i != h && j != l){
                        b[m][k]=a[i][j];
                        if (k<(n-2))
                            k++;
                        else{
                            k=0;
                            m++;
                        }
                    }
            c[h][l] = (float) pow(-1,(h+l))*det(b,(n-1));   // c = cofactor Matrix
        }
    transpose(c,d,n,determinte);    // read function
}// end function

//---------------------------------------------------
//  calculate inverse of matrix
void inverse(vector<vector<float>> &a,vector<vector<float>> &d,int n,float det){
    if(det == 0)
        cout<<"\nInverse of Entered Matrix is not possible\n";
    else if(n == 1)
        d[0][0] = 1;
    else
        cofactor(a,d,n,det);    // read function
}// end function

//---------------------------------------------------
//main fuction exe
int main(void){



    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int n;
    cout<<"enter the order of input matrix"<<endl;
    cin>>n;
    vector<vector<float> > a,d;
    cout<<"enter elements of the matrix"<<endl;
    
    for(int i=0;i<n;i++){
        vector<float> temp;
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            temp.push_back(k);
        }
        a.push_back(temp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        vector<float> temp;
        for(int j=0;j<n;j++){
            temp.push_back(0.0);
        }
        d.push_back(temp);
    }
    
    int print_matrix = 1;
    printf(a,n,print_matrix);
    
    double deter = (float) det(a,n);
    cout<<deter<<endl;
    
    inverse(a,d,n,deter);
    
    int print_inverse = 2;
    printf(d,n,print_inverse);
    
}// end main
