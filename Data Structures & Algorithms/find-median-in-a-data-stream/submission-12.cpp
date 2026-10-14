class MedianFinder {
public:
    priority_queue<int>minHeap;
    priority_queue<int, vector<int>, greater<int>>maxHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() - maxHeap.size() > 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }    
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top())/2.0;
        }else{
            return minHeap.top();
        }
    }
};
