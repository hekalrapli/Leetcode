func findThePrefixCommonArray(A []int, B []int) []int {
    temp := make([]int,len(A))
    table_a := make(map[int]int)
    table_b := make(map[int]int)


    for i := 0; i < len(A); i++ {
        table_a[A[i]]++;
        table_b[B[i]]++;
        cnt := 0
        for key := range table_a {
            if table_b[key] == 1 {
                cnt++
            }
        }
        temp[i] = cnt


    }


    return temp
    
}