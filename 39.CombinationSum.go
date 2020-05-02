package main
import (
        "fmt"
)

func combinationSum(candidates []int, target int) [][]int {
        solutions := make([][]int, 0)
        if target <= 0 || len(candidates) == 0{
                return solutions
        }
        
        if len(candidates) == 1 && target == candidates[0] {
                return [][]int{candidates}
        }
        
        for i:=0;i<len(candidates);i++{
                if candidates[i] <= target {
                        if target - candidates[i] == 0 {
                                solutions = append(solutions, []int{candidates[i]})
                        } else {
                                sol := combinationSum(candidates[i:], target-candidates[i])
                                for _, s := range sol {
                                        if len(s) > 0 {
                                                solutions = append(solutions, append(s, candidates[i]))
                                        }
                                }
                        }
                }
        }
        return solutions
}


func main() {
        result := combinationSum([]int{2, 3, 5}, 8)
        fmt.Println(result)
}
