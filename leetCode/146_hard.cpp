//146.LRU缓存机制
//

class LRUCache {
private:
    int capacity_, size_ = 0;
    unordered_map<int, list<pair<int, int>>::iterator> hash_;
    list<pair<int, int>> list_;
    
public:
    LRUCache(int capacity): capacity_(capacity) {
        
    }
    
    int get(int key) {
        if(hash_.find(key)!=hash_.end())
        {
            auto it = hash_[key];
            int val = hash_[key]->second;
            list_.erase(it);
            list_.emplace_front(key,val);
            hash_[key] = list_.begin();
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(hash_.find(key)!=hash_.end())
        {
            list_.erase(hash_.find(key)->second);
            list_.emplace_front(key, value);
            hash_[key] = list_.begin();
            return ;
        }
            
        size_++;
        if(capacity_ < size_ )
        {
            auto it_end = list_.end();
            hash_.erase(it_end->first);
            list_.pop_back();
            size_ --;
            list_.emplace_front(key, value);
            hash_[key] = list_.begin();
            
            return ;
        }
        list_.emplace_front(key, value);
        hash_[key] = list_.begin();
        return ;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */