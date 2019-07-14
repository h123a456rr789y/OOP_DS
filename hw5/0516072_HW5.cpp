#include<iostream>
#include<cstdlib>
#include<cstdio>
#include <fstream>


using namespace std;
//find the position that the number in the adj_m
int search_pos(int a[],int n,int searchnum){
    for(int i=0;i<n;i++){
        if(a[i]==searchnum){
            return i;
        }
    }
}

int main(){
    while (1){

        int n;
        cin>> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        bool adj_m[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj_m[i][j]=0;
            }
        }
        //find how many lines each point is connected with
        int ref[n];
        for(int i=0;i<n;i++){
            ref[i]=0;
        }

        int con,num1,num2;
        cin>> con;
        for (int i=0;i<con;i++){
            int  num1,num2;
            char c;
            cin>>num1>>c>>num2;
           // cout<<num1<<" "<<num2<<endl;
            int pos1,pos2;
            //find the position of num1 and num2 and let the relation be 1
            pos1=search_pos(a,n,num1);
            pos2=search_pos(a,n,num2);
           // cout<<pos1<<" "<<pos2<<endl;
            adj_m[pos2][pos1]=1;
            //cout<<"get con"<<endl;
        }



      //make it a file
        fstream file;
        file.open("TP_Sort_0516072.txt", ios::out);
        if(file.fail()){
            cout<<"The file can't be open"<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj_m[i][j])
                        ref[j]++;
                }
            }
            for(int i=0;i<n;i++){
                    //find whether it has connected to another point
                    int s=0;
                    while(s<n&&ref[s]!=0) s++;

                    if(s==n)break; //can't find =>it's a circle ((not possible
                    ref[s]=-1;//already found

                    file<<a[s]<<" ";

                    //renew the ref value ((deleting the line connected with the point S
                    for(int k=0;k<n;k++){
                        if(adj_m[s][k])
                            ref[k]--;
                    }
            }

            cout<<"The file is created!"<<endl;
            file.close();
        }
    }

    return 0;
}
