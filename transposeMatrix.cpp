#include<iostream>
#include<vector>
class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();

        std::vector<std::vector<int>> result(n,std::vector<int>(m));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[j][i]=matrix[i][j];
            }
        }

        return result;
    }
};
int main(){
    int m,n;
    std::cout<<"enter the dimensions of matrix\n";
    std::cin>>m>>n;

    std::vector<std::vector<int>> matrix(m,std::vector<int>(n));

    std::cout<<"enter the elements of matrix\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cin>>matrix[i][j];
        }
    }
    Solution obj;
    std::vector<std::vector<int>> ans=obj.transpose(matrix);
    std::cout<<"Transposed matrix:-\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cout<<ans[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}