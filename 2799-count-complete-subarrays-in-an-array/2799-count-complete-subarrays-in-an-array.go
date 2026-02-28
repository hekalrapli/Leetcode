func countCompleteSubarrays(nums []int) int {
    table := make(map[int]int)
    distinct := 0
    for _,val := range nums {
        if table[val] == 0 {
            table[val]++;
            distinct++;
        }
    }    
    res := 0
    for i:= 0; i < len(nums); i++ {
        temp := make(map[int]int)
        distinct_temp := 0
        temp[nums[i]]++;
        distinct_temp++;
         if distinct_temp == distinct {
            res++
        }
        for j := i+1; j < len(nums); j++ {
            if temp[nums[j]] == 0 {
                temp[nums[j]]++
                distinct_temp++
            }
               if distinct_temp == distinct {
                res++
            }
      
        }
     
    }
    return res
    

}