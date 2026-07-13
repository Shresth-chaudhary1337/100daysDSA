/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize) {

    int *ans= (int *)malloc(40*sizeof(int));

    *returnSize=0;
    for(int len=2;len<=9;len++){

    for(int start=1;start<=10-len;start++){
        int num=0;

        //forming sequential number numbers
        for(int digit=start;digit<start+len;digit++){
            num=num*10+digit;
        }
            if(num>=low && num<=high){
                ans[*returnSize]=num;
                (*returnSize)++;
            
        }
    }
    }
    return ans;
    
}