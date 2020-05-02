/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
        newNode := &ListNode{}
        vec1 := make([]int, 0)
        vec2 := make([]int, 0)
        for l1!=nil {
                vec1 = append(vec1, l1.Val)
                l1 = l1.Next
        }
        
        for l2!= nil {
                vec2 = append(vec2, l2.Val)
                l2 = l2.Next
        }
        
        overflow := 0
        pos1:=len(vec1)-1
        pos2:=len(vec2)-1
        for pos1 >= 0 || pos2 >= 0 {
                val1 := 0
                if pos1>=0 {
                        val1 = vec1[pos1]
                }
                
                val2 := 0
                if pos2 >= 0 {
                        val2 = vec2[pos2]
                }
                val := val1 + val2 + overflow
                if val > 9 {
                        overflow = 1
                        val -= 10
                } else {
                        overflow = 0
                }
                
                newNode.Val = val
                tmpNode := &ListNode{
                        Next: newNode,
                }
                newNode = tmpNode
                pos1--
                pos2-- 
        }
        if overflow == 1 {
                newNode.Val = 1
                return newNode
        } else {
                return newNode.Next
        }
}
