#include<iostream>
using namespace std;
template<typename T>
class vector{
	T *arr;
	int cs;
	int ms;
public:	
	vector(){
		cs=0;
		ms=1;
		arr = new T[ms];	
	}
	void push_back(T data){
		if(ms==cs){
			T *oldarr=arr;
			ms=2*ms;
			arr = new T[ms];
		for(int i=0;i<cs;i++){
			arr[i]=oldarr[i];
		}
		delete []oldarr;
		}
		arr[cs]=data;
		cs++;
	}
	void pop_back(){
		if(cs>=0){
			cs--;
		}
	}
	T front(){
		return arr[0];
	}
	T back(){
		return arr[cs-1];
	}
	bool isEmpty(){
		return cs==0;
	}
	T at(int i){
		return arr[i];
	}
	int size(){
		return cs;
	}
	int capacity(){
		return ms;
	}
	T operator[](int i){
		return arr[i];
	}
	
};

int main(){
	vector<int>arr;
	cout<<"isEmpty :: "<<arr.isEmpty()<<endl;
	cout<<"Size :: "<<arr.size()<<endl;
	arr.push_back(1);
	cout<<"Capacity :: "<<arr.capacity()<<endl;
	arr.pop_back();
	cout<<"Capacity :: "<<arr.capacity()<<endl;
	arr.push_back(2);
	cout<<"Capacity :: "<<arr.capacity()<<endl;
	arr.push_back(3);
	cout<<"Capacity :: "<<arr.capacity()<<endl;
	arr.push_back(4);
	cout<<"Capacity :: "<<arr.capacity()<<endl;
	arr.push_back(5);
	cout<<"Capacity :: "<<arr.capacity()<<endl;
	cout<<"isEmpty :: "<<arr.isEmpty()<<endl;
	cout<<"Size :: "<<arr.size()<<endl;
	cout<<"front :: "<<arr.front()<<endl;
	cout<<"back :: "<<arr.back()<<endl;
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<endl;
	}
	cout<<"At fxn :: "<<arr.at(3)<<endl;
	return 0;
}
