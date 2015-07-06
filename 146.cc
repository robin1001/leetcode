/* Date: 2015-07-06
 * Author: robin1001
 * Comment: too slow, aborted
 */

#include <stdio.h>
#include <vector>


struct Element {
	int key, value, count;
};

class LRUCache {
private:
	std::vector<Element *> cache_;
	int left_;
public:
	LRUCache(int capacity): cache_(capacity, NULL), left_(capacity) {
	}
	~LRUCache() {
		for (int i = 0; i < cache_.size(); i++) {
			if (cache_[i] != NULL) {
				delete cache_[i];
				cache_[i] = NULL;
			}
		}
	}
	int get(int key) {
		for (int i = 0; i < cache_.size(); i++) {
			if (cache_[i] != NULL && key == cache_[i]->key) {
				cache_[i]->count++;
				return cache_[i]->value;
			}
		}
		return -1;
	}

	void set(int key, int value) {
		//in cache	
		bool in_cache = false;
		for (int i = 0; i < cache_.size(); i++) {
			if (cache_[i] != NULL && key == cache_[i]->key) {
				cache_[i]->value = value;
				cache_[i]->count++;
				in_cache = true;
				return;
			}
		}
		if (!in_cache) {
			//1. cache is not used up
			if (left_ > 0) {
				for (int i = 0; i < cache_.size(); i++) {
					if (cache_[i] == NULL) {
						cache_[i] = new Element;
						cache_[i]->key = key;
						cache_[i]->value = value;
						cache_[i]->count = 1;
					}
				}
				left_--;
			}
			//2. used up, lru algorithm, select least 
			else {
				int min_idx = 0;
				int min = cache_[0]->count;
				for (int i = 1; i < cache_.size(); i++) {
					if (cache_[i]->count < min) {
						min_idx = i;
						min = cache_[i]->count;
					}
				}
				cache_[min_idx]->key = key;
				cache_[min_idx]->value = value;
				cache_[min_idx]->count = 1;
			}
		}
	}
};




int main() {
}
