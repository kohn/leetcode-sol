/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * 有几处问题需要考虑:
 * 1. iter要是指针, 因为用的时候NestedIterator还没定义完
 * 2. 由于程序隐含iter->hasNext()始终为true的条件, setIterator之后需要检查这条.
 * 3. setIterator时要检查index是否已经越界.
 */
class NestedIterator {

private:
    vector<NestedInteger> list;
    int index;
    NestedIterator *iter;
    
    void setIterator(){
        if(index >= list.size())
            return;
        if(!list[index].isInteger()){
            if(iter != NULL)
                delete iter;
            iter = new NestedIterator(list[index].getList());
            if(!iter->hasNext()){
                index++;
                setIterator();
            }
        }
    }
    
public:

    NestedIterator(vector<NestedInteger> &nestedList) {
        list = nestedList;
        index = 0;
        iter = NULL;
        setIterator();
    }
    
    ~NestedIterator(){
        if(iter != NULL)
            delete iter;
    }

    int next() {
        if(list[index].isInteger()){
            int res = list[index].getInteger();
            index++;
            setIterator();
            return res;
        } else{
            int res = iter->next();
            if(!iter->hasNext()){
                index++;
                setIterator();
            }
            return res;
        }
    }

    bool hasNext() {
        return index < list.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
