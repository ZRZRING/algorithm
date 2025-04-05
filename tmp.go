package acm

import (
	"container/list"
)

type LRUCache struct {
	capacity int
	cache    map[int]*list.Element
	list     *list.List
}

type entry struct {
	key, value int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		capacity: capacity,
		cache:    make(map[int]*list.Element),
		list:     list.New(),
	}
}

func (this *LRUCache) Get(key int) int {
	node := this.cache[key]
	if node == nil {
		return -1
	}
	this.list.MoveToFront(node)
	return node.Value.(entry).value
}

func (this *LRUCache) Put(key int, value int) {
	if node := this.cache[key]; node != nil {
		node.Value = value;
		this.list.MoveToFront(node)
		return
	}
	this.cache[key] = this.list.PushFront(entry{key, value})
	for len(this.cache) > this.capacity {
		delete(this.cache, this.list.Remove(this.list.Back()).(entry).key)
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
