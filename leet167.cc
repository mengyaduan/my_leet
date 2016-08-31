#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target);
int main(int argc, char const *argv[])
{
	vector<int> numbers(4,-3);
	numbers[1] = 3;numbers[2] = 4;numbers[3] = 90;
	std::vector<int> v = twoSum(numbers,0);
	cout<<v[0]<<" "<<v[1]<<endl;
	return 0;
}

vector<int> twoSum(vector<int>& numbers, int target){
    vector<int> v;
	int n = numbers.size();
    int i = 0;
    int j = n-1;
    int sum = 0;
    bool flag = 1;
    // while(numbers[j]>target)	--j;
    while(flag){
	   	sum = numbers[i]+numbers[j];
   		if(sum > target){
   			--j;
   			cout<<"j = "<<j<<endl;
   		}
   		else if(sum < target){
   			++i;
   			cout<<sum<<endl;
   			cout<<"i = "<<i<<endl;
   		}
   		else{
   			flag = 0;
   			cout<<"i = "<<i<<endl;
   			cout<<"j = "<<j<<endl;
   			v.push_back(i+1);
   			v.push_back(j+1);
   		}
    }
	return v;
}