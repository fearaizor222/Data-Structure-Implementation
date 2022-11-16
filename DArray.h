#ifndef DARRAY_H
#define DARRAY_H
#include <stdexcept>
#include <iostream>
#include <initializer_list>

template<class type> class DArray {
private:
	type* data;
	long long length;

public:
	type *getData() const {
		return data;
	}

	DArray(){
		length = 0;
		data = nullptr;
	}

	template<class otherType>
	DArray(DArray<otherType> &k){
		length = k.size();
		data = new type[length];
		for(int i = 0; i<length; i++){
			data[i] = (type)k.getData()[i];
		}
	}

	DArray(int number){
		length = number;
		data = new type[length];
	}

	template<class otherType>
	DArray(otherType element, int length){
		this->length = length;
		data = new type[length];
		for(int i = 0; i<length; i++){
			data[i] = (type)element;
		}
	}

	template<class otherType>
	DArray(otherType arr[], int length){
		this->length = length;
		data = new type[length];
		for(int i = 0; i<length; i++){
			data[i] = (type)arr[i];
		}
	}

	template<class otherType>
	DArray(std::initializer_list<otherType> arr){
		length = arr.size();
		data = new type[length];

		typename std::initializer_list<otherType>::iterator it = arr.begin();
		for(int i = 0; i<length; i++){
			data[i] = (type)(*it);
			it++;
		}
	}

	type &operator[](int index){
		if(index < 0 || index >= length) throw std::invalid_argument("Out of bound");
		else return data[index];
	}

	template<class otherType>
	DArray<type> &operator=(const DArray<otherType> &k){
		this->resize(k.size());
		for(int i = 0; i<length; i++){
			data[i] = (type)k.getData()[i];
		}

		return *this;
	}

	DArray<type> &operator=(const DArray<type> &k){
		if(this == &k) return *this;

		this->resize(k.size());
		for(int i = 0; i<length; i++){
			data[i] = k.getData()[i];
		}

		return *this;
	}

	template<class otherType>
	DArray<type> &operator=(std::initializer_list<otherType> other){
		this->clear();

		typename std::initializer_list<otherType>::iterator it = other.begin();

		while(it != other.end()){
			this->addBack((type)(*it));
			it++;
		}
	}

	void sort(bool reverse = false){
		if(reverse){
			for(int i = 0; i<length; i++){
				int index = i;

				for(int j = i+1; j<length; j++){
					if(data[index] < data[j]) index = j;
				}

				this->swap(i, index);
			}
		}
		else{
			for(int i = 0; i<length; i++){
				int index = i;

				for(int j = i+1; j<length; j++){
					if(data[index] > data[j]) index = j;
				}

				this->swap(i, index);
			}
		}
	}

	void assign(type arr[], int lengtharr){
		this->resize(lengtharr);
		for(int i = 0; i<lengtharr; i++){
			data[i] = arr[i];
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
		for(int i = start; i<end; i++){
			temp.addBack(this->data[i]);
		}

		return temp;
	}

	int size() const {
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

	template<class otherType>
	void addBack(otherType number){
		length++;
		resize(length);
		data[length - 1] = (type)number;
	}

	template<class otherType>
	void addFront(otherType number){
		length++;
		type *temp = new type[length];
		for(int i = 0, j = 1; i<length-1; i++, j++){
			temp[j] = data[i];
		}

		temp[0] = (type)number;
		delete[] data;
		data = temp;
	}

	template<class otherType>
	void addIndex(otherType number, int index){
		if(index > length || index < 0) throw std::invalid_argument("Invalid index");
		length++;
		resize(length);
		type temp1 = data[index];
		for(int i = index+1; i<length; i++){
				type temp2 = data[i];
				data[i] = temp1;
				temp1 = temp2;
		}

		data[index] = (type)number;
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
	if(index > length || index < 0) throw std::invalid_argument("Invalid index");
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

	~DArray(){
		delete[] data;
	}
};

#endif