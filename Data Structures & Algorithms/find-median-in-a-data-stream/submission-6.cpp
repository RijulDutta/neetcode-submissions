class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        int minSize = minHeap.size();
        int maxSize = maxHeap.size();

        if(minSize - maxSize > 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }        
    }
    
    double findMedian() {
        int minSize = minHeap.size();
        int maxSize = maxHeap.size();

        if(minSize - maxSize == 0){
            double num = minHeap.top() + maxHeap.top(); 
            double ans = num/2.0;
            return ans;
        }else{
            return minHeap.top();
        }
    }
};
