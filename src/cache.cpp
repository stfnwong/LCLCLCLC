/*
 * CACHE
 * Cache algorithms.
 *
 * Stefan Wong 2019
 */

#include <sstream>
#include "cache.hpp"


std::string CacheNode::toString(void) const
{
	std::ostringstream oss;

	oss << "[" << this->key << "] : " << this->value << std::endl;
	return oss.str();
}


/*
 * destroy_cache_node()
 */
void destroy_cache_node(CacheNode* node)
{
	if(node->next != nullptr)
		destroy_cache_node(node->next);
	delete node;
}



// ======== LRU CACHE ======== //
LRUCache::LRUCache() {}


/*
 * get()
 */
CacheNode* LRUCache::get(int key)
{
	auto search = this->hashmap.find(key);
	if(search == this->hashmap.end())
        return nullptr;         // TODO : double check this...

	CacheNode* node = search->second;

    return node;    // TODO: incomplete
}

/*
 * set()
 */
void LRUCache::set(int key, int value)
{
	if(this->hashmap.find(key) == this->hashmap.end())
	{
		// not found - create a new node and add to cache
	}
	else
	{
		// found, update the node that exists in the cache now
	}
}
