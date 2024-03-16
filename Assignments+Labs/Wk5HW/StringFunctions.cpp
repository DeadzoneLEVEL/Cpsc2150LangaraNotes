#include <iostream>
#include <string>
#include "HashingChain.h"
#include <chrono>

bool BigO_Nsquared(std::string);
bool BigO_NLogn(std::string);
bool BigO_N(std::string);
void merge(std::string&,int,int,int);
void mergeSort(std::string&,int,int);
void mergeSort(std::string&);

int main(){
    std::string str="clap00";
	std::string str2="smth";
	std::cout<<std::boolalpha<<BigO_NLogn(str)<<std::endl;
	std::cout<<std::boolalpha<<BigO_NLogn(str2)<<std::endl;
	std::cout<<std::boolalpha<<BigO_Nsquared(str)<<std::endl;
	std::cout<<std::boolalpha<<BigO_Nsquared(str2)<<std::endl;
	std::cout<<std::boolalpha<<BigO_N(str)<<std::endl;
	std::cout<<std::boolalpha<<BigO_N(str2)<<std::endl;

	// std::chrono::steady_clock::time_point quick1 = std::chrono::steady_clock::now();
    // cout <<"O(nlog(n)): " <<BigO_NLogn(str) << endl;
    // std::chrono::steady_clock::time_point quick2 = std::chrono::steady_clock::now();
    // std::cout << "Time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(quick2 - quick1).count() <<std::endl;

	// std::chrono::steady_clock::time_point quick3 = std::chrono::steady_clock::now();
    // cout <<"O(nlog(n)): " <<BigO_NLogn(str2) << endl;
    // std::chrono::steady_clock::time_point quick4 = std::chrono::steady_clock::now();
    // std::cout << "Time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(quick4 - quick3).count() <<std::endl;
	
    return 0;
}

/**
 * @brief A function to return true or false boolean based on whether there
 *  is a repeating char (does not consider 'whitespace' as a char)
 * Timecomplexity: O(n) since function makes use of a hashmap(O(1)) and only has to loop
 * through the string of size n
 * @param str 
 * @return true 
 * @return false 
 */
bool BigO_N(std::string str){
	char hashtable[127]={0};
	for(int i=0;i<str.size();i++){
		if(str[i]!=' '){
			std::hash<int> builtInHash;
			int hashCode=builtInHash(str[i]);
			int hashIndex=hashCode%(126);
			if(hashtable[hashIndex]!=0){
				return true;
			}else{
				hashtable[hashIndex]=str[i];
			}
		}
	}
	return false;
}

/**
 * @brief A function to return true or false boolean based on whether there
 *  is a repeating char (considers 'whitespace' as a char)
 * Timecomplexity: O(n^2) since function has a nested loop which loops through
 * string of size n for n times
 * @param str 
 * @return true 
 * @return false 
 */
bool BigO_Nsquared(std::string str){
	for(int i=0;i<str.size();i++){
		for(int j=0;j<str.size();j++){
			if((str[i]==str[j])&&(i!=j)){
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief A function to return true or false boolean based on whether there
 *  is a repeating char (considers 'whitespace' as a char)
 * Timecomplexity: O(nlog(n)) since function makes use of a mergeSotr(O(nlog(n))) and only has to loop
 * through the string of size n, (nlog(n)+n)=O(f(max)) therefore O(nlog(n))
 * @param str 
 * @return true 
 * @return false 
 */
bool BigO_NLogn(std::string str){
	std::string temp=str;
	mergeSort(temp);
    // std::cout<<temp;
	for(int i=0,j=1;i<temp.size()-1&&j<temp.size();i++,j++){
		if(temp[i]==temp[j]){
			return true;
		}
	}
	return false;
}

void merge(std::string &v,int l,int m,int h){
    std::string temp;

	int i, j;
	i = l;
	j = m + 1;

	while (i <= m && j <= h) {

		if (v[i] <= v[j]) {
			// temp.push_back(v[i]);
            temp+=v[i];
			++i;
		}
		else {
            temp+=v[j];
			// temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		// temp.push_back(v[i]);
        temp+=v[i];
		++i;
	}

	while (j <= h) {
		// temp.push_back(v[j]);
        temp+=v[j];
		++j;
	}

	for (int i = l; i <= h; ++i){
		v[i] = temp[i - l];
    }
}

void mergeSort(std::string &v,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,h);
        merge(v,l,mid,h);
    }
}

void mergeSort(std::string &v){
    mergeSort(v,0,v.size()-1);
}