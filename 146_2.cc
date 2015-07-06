/* Date: 2015-07-06
 * Author: robin1001
 * Comment: too slow, aborted
 */

#include <stdio.h>
#include <assert.h>

#include <list>
#include <unordered_map>
#include <algorithm>

class LRUCache {
private:
	std::unordered_map<int,int> map_;
	std::list<int> list_;
	int capacity_;
public:
	LRUCache(int capacity): capacity_(capacity) {
	}
	~LRUCache() {

	}
	int get(int key) {
		if (map_.find(key) != map_.end()) {//find
			std::list<int>::iterator it = std::find(list_.begin(), list_.end(), key);
			assert(it != list_.end());
			list_.erase(it);
			list_.push_back(key);
			return map_[key];
		}
		return -1;
	}

	void set(int key, int value) {
		if (map_.find(key) != map_.end()) {
			map_[key] = value;
			std::list<int>::iterator it = std::find(list_.begin(), list_.end(), key);
			list_.erase(it);
			list_.push_back(key);

		} else {
			map_.insert(std::make_pair(key, value));
			//printf("%d\n", map_[key]);
			list_.push_back(key);
			if (list_.size() > capacity_) {
				int k = list_.front();
				list_.pop_front();
				map_.erase(k);
			}
		}

	}
};


int main() {
	LRUCache cache(1);
	//1,[set(2,1),get(2),set(3,2),get(2),get(3)]
	cache.set(2,1);
	printf("%d\n", cache.get(2));
	cache.set(3,2);
	printf("%d\n", cache.get(2));
	printf("%d\n", cache.get(3));

}
