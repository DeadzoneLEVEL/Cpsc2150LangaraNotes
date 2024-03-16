#include<vector>
#include<iostream>
using namespace std;
vector<int> Primes(int n);

int main(){
    vector<int> v;
    v=Primes(300);
    for(unsigned i=0;i<v.size();i++){
        std::cout<<v[i]<<" ";
    }
    return 0;
}

/**
 * @brief Space Complexity: The function contains an int vector of size n and one int.
 * Each int contains 4 bytes so if we consider the space as sum + forEach loop we can come up 
 * with a function of f(space)=4+4*n; (with n being the size of arr). That makes the bigO to be
 * O(n).
 * @param arr 
 * @return int 
 */
// int ArraySum(const vector<int>& arr) {
//     int sum = 0;
//     for (int num : arr) {
//         sum += num;
//     }
//     return sum;
// }

/**
 * @brief Space Complexity: The function contains two strings of size n.
 * Each char contains 1 byte so if we consider the space as string1 + string2 we can come up 
 * with a function of f(space)=1*n+1*n; (with n being the size of string). That makes the bigO to be
 * O(n).
 * @param str1 
 * @param str2 
 * @return string 
 */
// string StringConcatenation(const string& str1,const string& str2) {
//     return str1 + str2;
// }

/**
 * @brief Space Complexity: The function contains two ints and two matrices of ints.
 * Each int contains 4 bytes so if we consider the space as int + int + matrix + nested Loop
 * we can come up with a function of f(space)= 4+4+(4*n*m)+(4*m*n); If we assume (n*m->n^2),
 * then that makes the bigO to be O(n^2).
 * @param matrix 
 * @return vector<vector<int>> 
 */
// vector<vector<int>> TransposeMatrix(const vector<vector<int>>& matrix) {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     vector<vector<int>> transpose(n,vector<int>(m));
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             transpose[j][i] = matrix[i][j];
//         }
//     }
//     return transpose;
// }

vector<int> Primes(int n){
    vector<int> results;
    for(int i=2;i<=n;i++){
        results.push_back(i);
    }
    for(unsigned i=0;i<results.size();i++){
        for(unsigned j=i+1;j<results.size();j++){
            if(results[j]%results[i]==0){
                results.erase(results.begin()+j);
            }
        }
    }
    return results;
}
