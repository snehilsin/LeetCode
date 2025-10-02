class MedianFinder {
public:
    // max heap for smaller half
    priority_queue<int> small_half;

    // min-heap for larger half
    priority_queue<int, vector<int>, greater<int>> large_half;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small_half.push(num);

        large_half.push(small_half.top());
        small_half.pop();

        if(large_half.size() > small_half.size()){
            small_half.push(large_half.top());
            large_half.pop();
        }
    }
    
    double findMedian() {
        if (small_half.size() > large_half.size()){
            return small_half.top();
        }
        return (small_half.top() + large_half.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */