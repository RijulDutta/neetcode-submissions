class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>>minHeap;
    priority_queue<int>maxHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() - maxHeap.size() == 2){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        double median = 0;
        if(minHeap.size() == maxHeap.size()){
            median = (double)(minHeap.top() + maxHeap.top())/2;
        }else{
            median = (double)minHeap.top();
        }

        return median;
    }
};
