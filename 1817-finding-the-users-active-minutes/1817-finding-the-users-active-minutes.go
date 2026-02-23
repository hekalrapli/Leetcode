func findingUsersActiveMinutes(logs [][]int, k int) []int {
    table := make(map[[2]int]int)
    temp := make(map[int]int)
    res  := make([]int,k)
    cnt := make(map[int]int)
 
    for i := range logs {
        if(table[[2]int{logs[i][0], logs[i][1]}] == 0) {
            table[[2]int{logs[i][0],logs[i][1]}]++
            temp[logs[i][0]]++
        }
 
    }
    for _,val := range temp {
        cnt[val]++
    }
    fmt.Println()
    for key,val := range cnt {
        res[key-1] = val
        
    }
    return res
}