/* 안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을
 * 갑니다.  원석 선생님은 소풍 때 학생들은 두 명씩 짝을 지어 행동하게
 * 하려고 합니다. 그런데 서로 친구가 아닌 학생들끼리 짝을 지어주면
 * 서로 싸우거나 같이 돌아다니지 않기 떄문에, 항상 서로 친구인
 * 학생들끼리만 짝을 지어야합니다. 각 학생들의 쌍에 대해 이들이 서로
 * 친구인지 여부가 주어질 때, 학생들을 짝 지을 수 있는 방법의 수를
 * 계산하는 프로그램을 작성하세요. 짝이 되는 학생들이 일부만
 * 다르더라도 다른 방법이라고 봅니다. */

package main

import 	"fmt"

type Friend struct {
	FA int
	FB int
}

func (f *Friend) check(a int, b int) bool{
	return (f.FA == a && f.FB == b) || (f.FA == b && f.FB == a)
}

func main(){
	var cases int
	var student int
	var friendPair int
	
	fmt.Scanf("%d", &cases)
	for cases > 0 {
		fmt.Scanf("%d", &student)
		fmt.Scanf("%d", &friendPair)
		
		friendList := make([]Friend, friendPair)
		
		for friendPair > 0 {
			var pairA int
			var pairB int
			fmt.Scanf("%d", &pairA)
			fmt.Scanf("%d", &pairB)

			friendList[len(friendList) - friendPair] = Friend{pairA, pairB}

			friendPair--
		}

		remainList := make([]int, student)
		
		solution := countPairing(remainList, friendList)
		fmt.Printf("%d\n", solution)
		cases--
	}
}

func checkFriendly(friendList []Friend, a int, b int) bool{
	for _, friend := range friendList {
		if friend.check(a, b) {
			return true
		}
	}
	return false
}


func countPairing(remainList []int, friendList []Friend) int{
	var selected int = -1

	for i, value := range remainList{
		if value == 0{
			selected = i
			break
		}
	}

	if selected == -1 {
		return 1
	}

	//전역 solution을 쓰는 것보다 각 단계에서 solution값을 유지하여, 상위로 던지는 편이 더 깔끔하다.
	ret := 0

	for pair := selected+1 ; pair < len(remainList) ; pair++ {
		if remainList[pair] == 0 && checkFriendly(friendList, selected, pair){
			//재귀를 위해 배열을 복사하지 않고, 값을 변경했다가 이전의 상태로 되돌리는 편이 더 깔끔하다.
			remainList[selected] = 1
			remainList[pair] = 1
			ret += countPairing(remainList, friendList)
			remainList[selected] = 0
			remainList[pair] = 0
		}
	}
	return ret
}
	
 
