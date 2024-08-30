#include<bits/stdc++.h>
#include<windows.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
using namespace std;

int arr[10]={1,2,3,4,5,6,7,8,9,10};

void* routine(void* arg){
    int index=*(int*)arg;//arg is a void pointer then it's casted to int pointer then int pointer value is used
    int sum=0;
    for(int i=0;i<5;i++)
    {
        sum+=arr[index+i];
    }
    cout<<"Local Sum: "<<sum<<"\n";
    *(int*)arg=sum;
    return arg;
}

int main(){
    pthread_t myThread[2];
    for(int i=0;i<2;i++){
        int*a=(int*)malloc(sizeof(int));
        *a=i*5;
        if(pthread_create(&myThread[i],NULL,&routine,a)!=0)
        {
            perror("An Error Occured");
        }
    }
    int globalSum = 0;
    for (int i = 0; i < 2; i++) {
        int* r;
        if (pthread_join(myThread[i], (void**) &r) != 0) {
            perror("Failed to join thread");
        }
        globalSum += *r;
        free(r);
    }
    cout<<"Global sum: "<<globalSum<<"\n";
    return 0;
}