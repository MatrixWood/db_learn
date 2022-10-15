#pragma once

#include <iostream>
#include <cassert>

struct Handle {
	Handle* next_hash;
	Handle* next;
	Handle* prev;
	uint32_t hash;
	char key_data[1];

	std::string key() const {
		assert(next != this);
		return std::string(key_data);
	}
};

class HandleTable {
public:
	HandleTable() : length_(0), elems_(0), list_(nullptr) { Resize(); }
	~HandleTable() { delete[] list_; }

	Handle* Insert(Handle* h) {

	}


private:
	uint32_t length_;
	uint32_t elems_;
	Handle** list_;

	Handle** FindPointer(const std::string& key, uint32_t hash) {
		Handle** ptr = &list_[hash & (length_ - 1)];
	}


	void Resize() {
		uint32_t new_length = 4;
		while (new_length < elems_) {
			new_length *= 2;
		}
		Handle** new_list = new Handle*[new_length];
		memset(new_list, 0, sizeof(new_list[0]) * new_length);
		uint32_t count = 0;
		for (uint32_t i = 0; i < length_; ++i) {
			Handle* h = list_[i];
			while (h != nullptr) {
				Handle* next = h->next_hash;
				uint32_t hash = h->hash;
				Handle** ptr = &new_list[hash & (new_length - 1)];
				h->next_hash = *ptr;
				*ptr = h;
				h = next;
				count++;
			}
		}
		assert(elems_ == count);
		delete[] list_;
		list_ = new_list;
		length_ = new_length;
	}
};
