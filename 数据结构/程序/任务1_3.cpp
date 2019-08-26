#include <iostream>
using namespace std;

bool search(int *p[],const int len,const int key)
{
    int i = 0;
    for(;i<len;i++)
    {
        if(key == p[i])
            return true;
    }
    if(i>=len)
        return false;
}

int main()
{
    const int arr[5] = {3,6,8,5,9};
    cout << search(arr,5,8) << endl;
    return 0;
}
/*
找到的情况：比较了2i次
未找到的情况：比较了2n+1+1次
*/