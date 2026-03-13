func checkOnesSegment(s string) bool {

    foundZero := false
    for i := range s {
        if(string(s[i]) == "1") {
            if(foundZero) {
                return false
            }
        }else {
            foundZero = true
        }
    }
    return true
}