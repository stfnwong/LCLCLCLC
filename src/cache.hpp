/*
 * CACHE
 * Cache algorithms.
 *
 * Stefan Wong 2019
 */

#ifndef __LC_CACHE_HPP
#define __LC_CACHE_HPP

#include <map>
#include <string>

/*
 * CacheNode
 * A single node in a Cache object. 
 */
struct CacheNode
{
	int key;
	int value;
	CacheNode* next;
	CacheNode* prev;

	public:
		CacheNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {} 
		std::string toString(void) const;
};


/*
 * destroy_cache_node()
 * Free the memory associated with a cache node
 */
void destroy_cache_node(CacheNode* node);


/*
 * LRUCache 
 * Least Recently Used Cache
 *
 * This version uses std::map. 
 */
class LRUCache
{
	private:
		int                 capacity;
		int                 cur_size;
		std::map <int, CacheNode*> hashmap;

	public:
		LRUCache();

		CacheNode* get(int key);
		void set(int key, int value);
};


#endif /*__LC_CACHE_HPP*/
