2073. Time Needed to Buy Tickets
Easy

Hint
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

Example 1:
Input: tickets = [2,3,2], k = 2

Output: 6

Explanation:

The queue starts as [2,3,2], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
Continuing this process, the queue becomes [2,1,2] at 2 seconds.
Continuing this process, the queue becomes [1,2,1] at 3 seconds.
Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
Continuing this process, the queue becomes [1,1] at 5 seconds.
Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.
Example 2:

Input: tickets = [5,1,1,1], k = 0

Output: 8

Explanation:

The queue starts as [5,1,1,1], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. The kth person has bought all their tickets, so return 8.

    class Solution {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) {
        int anstime=0;
        queue<int>q1;
        queue<int>q2;

        for(int i=0;i<tickets.size();i++){

            if(i==k){
                q1.push(tickets[i]);
                q2.push(1);
            }else{
                q1.push(tickets[i]);
                q2.push(0);
            }
        }
            int tempnum=tickets[k];
        while(!q1.empty()&& tempnum>0){
            int num=q1.front();
            q1.pop();
            if(q2.front()==1){
                tempnum--;
            }
            int num2=q2.front();
            q2.pop();

            num=num-1;
            if(num>0){
                q1.push(num);
                q2.push(num2);

            }
            anstime++;

        }

        return anstime;
        }
    };

## Reverse first K of a Queue
Solved
Difficulty: EasyAccuracy: 81.28%Submissions: 197K+Points: 2
Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: 

The above operations represent the general processings.
In-built functions of the respective languages can be used to solve the problem.
If the size of queue is smaller than the given k , then return the original queue.
Examples:

Input: q = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
Explanation: After reversing the first 3 elements from the given queue the resultant queue will be [3, 2, 1, 4, 5]
Input: q = [4, 3, 2, 1], k = 4
Output: [1, 2, 3, 4] 
Explanation: After reversing the first 4 elements from the given queue the resultant queue will be [1, 2, 3, 4]

Approch 1

    class Solution {
    public:
        queue<int> reverseFirstK(queue<int> q, int k) {
            
        if(k > q.size() || k <= 0)
        return q;
        vector<int> nums;

        while(!q.empty()){
            nums.push_back(q.front());
            q.pop();
        }

        int i = 0;
        int j = k - 1;

        while(i < j){
            int num = nums[i];
            nums[i] = nums[j];
            nums[j] = num;

            i++;
            j--;
        }

        for(int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
        }

        return q;
        }
    };

Approch 2

    class Solution {
    public:
        queue<int> reverseFirstK(queue<int> q, int k) {
            
            if(k > q.size() || k <= 0)
                return q;
            
            stack<int> st;
            
            // Put first k elements into stack
            for(int i = 0; i < k; i++){
                st.push(q.front());
                q.pop();
            }
            
            // Put reversed first k elements back
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }
            
            // Move remaining elements to the back
            int remaining = q.size() - k;
            
            while(remaining--){
                q.push(q.front());
                q.pop();
            }
            
            return q;
        }
    };