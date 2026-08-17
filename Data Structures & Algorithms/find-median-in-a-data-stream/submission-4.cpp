class MedianFinder {
public:
    priority_queue<int> maxHeap;                            // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // upper half

    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() - maxHeap.size() > 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        int minSize = minHeap.size();
        int maxSize = maxHeap.size();

        if (minSize == maxSize) {
            double num = minHeap.top() + maxHeap.top();
            return num / 2.0;
        } else { // minSize - maxSize == 1
            return minHeap.top();
        }
    }
};