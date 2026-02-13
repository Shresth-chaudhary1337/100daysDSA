/*Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

Test Cases:

Test Case 1:
Input:
2 2
1 2
3 4
5 6
7 8
Output:
6 8
10 12

Test Case 2:
Input:
1 3
10 20 30
1 2 3
Output:
11 22 33

Test Case 3:
Input:
3 1
1
2
3
4
5
6
Output:
5
7
9
*/
#include<iostream>
#include<vector>
int main(){
    int m1,n1,m2,n2;
    std::cout<<"enter the dimensions of matrix \n";
    std::cout<<"enter dimensions of first matrix\n";
    std::cin>>m1>>n1;
    std::cout<<"enter number of columns\n";
    std::cin>>m2>>n2;
    std::vector<std::vector<int>> a(m1,std::vector<int>(n1));
    std::vector<std::vector<int>> b(m2,std::vector<int>(n2));
    std::cout<<"enter the elements of first matrix\n";
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            std::cin>>a[i][j];
        }
    }
    std::cout<<"enter the elements of second matrix\n";
    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++){
            std::cin>>b[i][j];
        }
    }
    if(m1!=m2 || n1!=n2){
        std::cout<<"addition not possible on matrix with different dimensions\n";
        return 0;
    }
    std::cout<<"resultant matrix\n";
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            std::cout<<a[i][j]+b[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}