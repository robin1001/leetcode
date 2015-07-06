/* Date: 2015-07-06
 * Author: robin1001
 * Comment: accepted
 */

#include <stdio.h>
#include <assert.h>

#include <list>
#include <unordered_map>
#include <algorithm>

class LRUCache {
private:
	std::unordered_map<int,std::pair<int, std::list<int>::iterator> > map_;
	std::list<int> list_;
	int capacity_;
public:
	LRUCache(int capacity): capacity_(capacity) {
	}
	~LRUCache() {

	}
	int get(int key) {
		if (map_.find(key) != map_.end()) {//find
			list_.erase(map_[key].second);
			list_.push_front(key);
			map_[key].second = list_.begin();
			return map_[key].first;
		}
		return -1;
	}

	void set(int key, int value) {
		if (map_.find(key) != map_.end()) {
			map_[key].first = value;
			list_.erase(map_[key].second);
			list_.push_front(key);
			map_[key].second = list_.begin();

		} else {
			list_.push_front(key);
			map_.insert(std::make_pair(key, std::make_pair(value, list_.begin())));
			if (list_.size() > capacity_) {
				int k = list_.back();
				map_.erase(k);
				list_.pop_back();
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
