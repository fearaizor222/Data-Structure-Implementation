#ifndef DARRAY_H
#define DARRAY_H
#include <stdexcept>
#include <iostream>
#include <initializer_list>
#include <string>

template<class type> class DArray {
private:
	type* data;
	long long length;

public:
	DArray(){
		length = 0;
		data = nullptr;
	}

	DArray(int number){
		length = number;
		data = new type[length];
	}

	DArray(type arr[], int number){
		length = number;
		data = new type[length];
		for(int i = 0; i<length; i++){
			data[i] = arr[i];
		}
	}

	DArray(std::initializer_list<type> arr){
		length = arr.size();
		data = new type[length];

		typename std::initializer_list<type>::iterator it = arr.begin();
		for(int i = 0; i<length; i++){
			data[i] = (*it);
			it++;
		}
	}

	type &operator[](int index){
		if(index < 0 || index >= length) throw std::invalid_argument("Out of bound");
		else return data[index];
	}

	// DArray<type> &operator=(DArray<type> &k){  Don't use this, it won't accept rvalue, use the assign method
	// 	if(this == &k) return *this;

	// 	this->resize(k.length);
	// 	for(int i = 0; i<k.length; i++){
	// 		data[i] = k[i];
	// 	}

	// 	return *this;
	// }

	void assign(const DArray<type> &k){
		this->resize(k.length);
		for(int i = 0; i<k.length; i++){
			data[i] = k.data[i];
		}
	}

	void assign(type arr[], int lengtharr){
		this->resize(lengtharr);
		for(int i = 0; i<lengtharr; i++){
			data[i] = arr[i];
		}
	}

	void assign(std::initializer_list<type> arr){
		this->resize(arr.size());
		typename std::initializer_list<type>::iterator it = arr.begin();
		
		for(int i = 0; i<length; i++){
			data[i] = *it;
			it++;
		}
	}

	void resize(int new_length){
		type *ptr = new type[new_length];

		if(data == NULL){
			for(int i = 0; i<new_length; i++){
				ptr[i] = 0;
			}
			
			length = new_length;
			data = ptr;
			return;
		}
		else{
			for(int i = 0; i<new_length; i++){
				if(i < length) ptr[i] = data[i];
				else ptr[i] = 0;
			}

			length = new_length;
			delete[] data;
			data = ptr;
			return;
		}
	}

	DArray<type> range(int start, int end){
		if(end > length) throw std::invalid_argument("Unvalid range");
		DArray<type> temp;
		temp.resize(end - start);
		for(int i = start, j = 0; i<end; i++, j++){
			temp[j] = data[i];
		}

		return temp;
	}

	int size(){
		return length;
	}

	type &at(int index){
		if(index<0 && length+index>=0) return data[length + index];
		else if(length+index < 0){
			throw std::invalid_argument("Out of bound");
		}
		else if(length <= index) throw std::invalid_argument("Out of bound");
		return data[index];
	}

	int indexOf(type number){
		int index = -1;
		for(int i = 0; i<length; i++){
			if(data[i] == number){
				index = i;
				break;
			}
		}
		return index;
	}

	void swap(int index1, int index2){
		type temp = data[index1];
		data[index1] = data[index2];
		data[index2] = temp;
	}

	void fill(type number){
		for(int i = 0; i<length; i++){
			data[i] = number;
		}
	}

	void fill_n(type number, int time){
		int i = 0;
		while(i < time){
			data[i] = number;
			i++;
		}
	}

	void extend(const DArray<type> &arr){
		int tempo_length = length;
		resize(length + arr.length);
		for(int i = tempo_length, j = 0; i<length; i++, j++){
			data[i] = arr.data[j];
		}
	}

	void addBack(type number){
		length++;
		resize(length);
		data[length - 1] = number;
	}

	void addFront(type number){
		length++;
		type *temp = new type[length];
		for(int i = 0, j = 1; i<length-1; i++, j++){
			temp[j] = data[i];
		}

		temp[0] = number;
		delete[] data;
		data = temp;
	}

	void addIndex(int index, type number){
		length++;
		resize(length);
		type temp1 = data[index];
		for(int i = index+1; i<length; i++){
				type temp2 = data[i];
				data[i] = temp1;
				temp1 = temp2;
		}

		data[index] = number;
	}

	void deleteBack(){
		length--;
		resize(length);
	}

	void deleteFront(){
		length--;
		type *temp = new type[length];
		for(int i = 1, d = 0; i<length+1; i++, d++){
			temp[d] = data[i];
		}
		delete[] data;
		data = temp;
	}

	void deleteIndex(int index){
		length--;
		type *temp = new type[length];
		for(int i = 0, j = 0; i<length+1; i++){
			if(i == index) continue;
			temp[j] = data[i];
			j++;
		}

		delete[] data;
		data = temp;
	}

	void clear(){
		delete[] data;
		length = 0;
		data = new type[length];
	}

	void print(){
		for(int i = 0; i<length; i++){
			std::cout<<data[i]<<" ";
		}
		std::cout<<"\n";
	}

	void print(const std::string &s, bool index = false, bool val = false){
		for(int i = 0; i<length; i++){
			if(index == false && val == false) printf(s.c_str());
			if(index == true && val == false)  printf(s.c_str(), i);
			if(index == true && val == true)   printf(s.c_str(), i, data[i]);
			if(index == false && val == true)  printf(s.c_str(), data[i]);
		}
	}

	~DArray(){
		delete[] data;
	}
};

#endif